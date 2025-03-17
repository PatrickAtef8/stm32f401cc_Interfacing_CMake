# Set minimum CMake version
cmake_minimum_required(VERSION 3.10)

# Project Name
project(COTS LANGUAGES C)

# Set ARM Toolchain
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/arm-gcc-toolchain.cmake) # Use the ARM toolchain

# Set output directories for the binaries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Include the driver script
include(${CMAKE_SOURCE_DIR}/Drivers.cmake)

# Define the list of drivers for MCAL layer
set(drivers "MRCC;MGPIO;MNVIC;MSTK")  # List of MCAL drivers

# Create standalone libraries for the MCAL drivers
create_driver_libraries(MCAL "${drivers}")

# Add the APP subdirectory
add_subdirectory(APP/MRCC_TEST)
add_subdirectory(APP/MGPIO_TEST)
add_subdirectory(APP/MNVIC_TEST)
add_subdirectory(APP/MSTK_TEST)