cmake_minimum_required(VERSION 3.20)
project(apexdyn)
enable_testing()

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
        src/TorqueCurve.cpp
)

add_executable(vehicle_loader_tests
        tests/VehicleLoaderTests.cpp
        src/VehicleLoader.cpp
        src/IniValueParsing.cpp
)
target_include_directories(vehicle_loader_tests PRIVATE include ${mini_SOURCE_DIR}/src ${CMAKE_BINARY_DIR}/generated)

add_test(NAME VehicleLoaderTests COMMAND vehicle_loader_tests)

target_include_directories(apexdyn PRIVATE include ${mini_SOURCE_DIR}/src)

configure_file(
        ${CMAKE_SOURCE_DIR}/tests/TestConfig.h.in
        ${CMAKE_BINARY_DIR}/generated/TestConfig.h
)