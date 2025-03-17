# Minimum CMake version
cmake_minimum_required(VERSION 3.10)

# Project definition
project(MSTK_TEST.elf C ASM)

# Define the startup file
set(STARTUP_FILE "${CMAKE_SOURCE_DIR}/COMMON/startup_stm32f401xc.S")
set(LINKER_SCRIPT "${CMAKE_SOURCE_DIR}/COMMON/STM32F401CCUX_FLASH.ld")



# Define the executable
add_executable(${PROJECT_NAME} 
    main.c                  # Main application file
    ${STARTUP_FILE}         # Startup file
)


# Include the driver management script
include(${CMAKE_SOURCE_DIR}/Drivers.cmake)



# Add drivers to the target executable
add_drivers(${PROJECT_NAME} "MCAL" "MRCC;MGPIO;MSTK")

# Link the executable to the driver libraries
target_link_libraries(${PROJECT_NAME} PRIVATE MRCC MGPIO MSTK)

# Define linker options
target_link_options(${PROJECT_NAME} PRIVATE
    ${COMMON_FLAGS}         # Reuse common flags
    -T${LINKER_SCRIPT}      # Specify linker script
    -Wl,--gc-sections       # Remove unused sections
)

# Define output paths for ELF and HEX files
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(TARGET_ELF "${CMAKE_BINARY_DIR}/bin/MSTK_TEST.elf")
set(TARGET_HEX "${CMAKE_BINARY_DIR}/bin/MSTK_TEST.hex")



# Add custom command to generate the HEX file from the ELF
add_custom_command(
    OUTPUT ${TARGET_HEX}
    COMMAND ${CMAKE_OBJCOPY} -O binary ${TARGET_ELF} ${TARGET_HEX}
    DEPENDS ${TARGET_ELF}
    COMMENT "Generating HEX file from ELF"
    VERBATIM
)

# Add a custom target to build the HEX file
add_custom_target(
    MSTK_TEST_generate_hex ALL
    DEPENDS ${TARGET_HEX}
)

add_custom_target(
    flash_MSTK_TEST
    COMMAND st-flash write ${TARGET_HEX} 0x8000000
    COMMAND openocd -f interface/stlink.cfg -f target/stm32f4x.cfg -c "reset run; exit"
    DEPENDS MSTK_TEST_generate_hex
    COMMENT "Flashing HEX to hardware and resetting"
    VERBATIM
)
