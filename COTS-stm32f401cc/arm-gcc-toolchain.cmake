# arm-none-eabi-toolchain.cmake

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

# Set the target MCU
set(MCU cortex-m4)

# Define the programmer (update as needed for your setup)
set(PROGRAMMER stlink)
set(USB_PORT /dev/ttyUSB0) # Update for your USB port
set(BaudRate 115200)       # Common baud rate for STM32 programming

# Set the cross-compilers
set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)
set(CMAKE_ASM_COMPILER arm-none-eabi-as)

# Set additional tools
set(CMAKE_AR arm-none-eabi-ar)
set(CMAKE_OBJCOPY arm-none-eabi-objcopy)
set(CMAKE_OBJDUMP arm-none-eabi-objdump)
set(CMAKE_SIZE arm-none-eabi-size)

# Set the target MCU and compiler flags
set(CMAKE_C_FLAGS "-mcpu=${MCU} -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard -Wall -O2")
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -fno-exceptions -fno-rtti")
set(CMAKE_ASM_FLAGS "-mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard")


# Linker flags
 set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)