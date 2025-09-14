# CrowCPP Web Server

A simple web server project using [Crow](https://github.com/CrowCpp/Crow) and [Asio](https://think-async.com/Asio/), built with CMake and managed with Conan.

## Features

- Modern C++ web server
- Uses Crow (crowcpp-crow/1.2.1) and Asio (asio/1.29.0) headers
- Easy dependency management with Conan

## Build & Run

1. **Install Conan**  
    [Conan installation guide](https://docs.conan.io/en/latest/installation.html)

2. **Install dependencies**
    ```sh
    conan install . --build=missing
    ```

3. **Build the project**
    ```sh
    #cofigure build
    cmake -B build -S . -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE="Release"
    #build the project
    cmake --build build
    ```

4. **Run**
    ```sh
    ./build/my_server.exe

    #or run the my_server.exe through the system file manager.
    ```
    > **Important Note:**  
    > This project uses `MinGW Makefiles` as the CMake toolchain. If you are using Visual Studio Code, you may not see `MinGW Makefiles` as an available toolchain in the CMake Tools configuration.  
    > **Do not select `conan-release` as the build preset in VS Code.**  
    > If you are using VS Code, skip the step where you specify the generator in the `CMake: Configure` and use the default CMake configuration provided in the Command given here (`-G "MinGW Maefiles"`).
## Requirements

- C++17 or newer
- CMake
- Conan

## License

MIT
