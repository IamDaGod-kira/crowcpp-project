    cmake_minimum_required(VERSION 3.15)
    project(MyCrowApp CXX)
    
    # Set Crow_DIR or CMAKE_PREFIX_PATH to help CMake find Crow
    list(APPEND CMAKE_PREFIX_PATH "build/Release/generators/")
    
    set(CMAKE_GENERATOR "MinGW Makefiles")

    # This finds the Crow package provided by Conan
    find_package(Crow REQUIRED)
    
    add_executable(my_server src/main.cpp) # Assuming your main source file is src/main.cpp
    target_link_libraries(my_server Crow::Crow)

    add_custom_command(
        TARGET my_server 
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
                "${CMAKE_CURRENT_SOURCE_DIR}/src/templates"
                "$<TARGET_FILE_DIR:my_server>/templates"
        COMMENT "Copying Templates directory"
    )