# Macro to add drivers (source + include directory) to an executable or library
macro(add_drivers target_name layer drivers)
    message(STATUS "Adding drivers: ${drivers} from layer: ${layer} to target: ${target_name}")
    foreach(driver IN LISTS drivers)
        # Set paths to the driver source and include directory
        set(driver_src "${CMAKE_SOURCE_DIR}/${layer}/${driver}/src/${driver}.c")
        set(driver_inc "${CMAKE_SOURCE_DIR}/${layer}/${driver}/inc")
        set(Common_inc "${CMAKE_SOURCE_DIR}/COMMON")

        # Debugging message to print paths
        message(STATUS "Driver source: ${driver_src}")
        message(STATUS "Driver include directory: ${driver_inc}")

        # Add source files and include directories to the target
        target_sources(${target_name} PRIVATE ${driver_src})
        
        target_include_directories(${target_name} PRIVATE ${driver_inc} ${Common_inc})
    endforeach()
endmacro()

# Macro to create standalone libraries for each driver
macro(create_driver_libraries layer drivers)
    foreach(driver IN LISTS drivers)
        # Create a static library for the driver
        add_library(${driver} STATIC)

        # Add the driver sources and includes
        add_drivers(${driver} ${layer} ${drivers})
    endforeach()
endmacro()
