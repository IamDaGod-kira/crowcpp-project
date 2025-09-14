    cmake_minimum_required(VERSION 3.15)
    project(MyCrowApp CXX)
    
    # Set Crow_DIR or CMAKE_PREFIX_PATH to help CMake find Crow
     list(APPEND CMAKE_PREFIX_PATH "build/Release/generators/")
     
    # This finds the Crow package provided by Conan
    find_package(Crow REQUIRED)
    
    add_executable(my_server src/main.cpp) # Assuming your main source file is src/main.cpp
    target_link_libraries(my_server Crow::Crow)