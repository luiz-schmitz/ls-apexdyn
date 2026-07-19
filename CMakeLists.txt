cmake_minimum_required(VERSION 3.20)

project(apexdyn)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

FetchContent_Declare(
        mini
        GIT_REPOSITORY https://github.com/pulzed/mINI.git
        GIT_TAG master
)
FetchContent_MakeAvailable(mini)

add_executable(apexdyn
        src/main.cpp
        src/DirectoryInspection.cpp
        src/IniValueParsing.cpp
        src/VehicleLoader.cpp
)
target_include_directories(apexdyn PRIVATE include ${mini_SOURCE_DIR}/src)