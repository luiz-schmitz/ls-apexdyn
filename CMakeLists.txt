cmake_minimum_required(VERSION 3.31)
project(apexdyn)
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

FetchContent_Declare(
        mini
        GIT_REPOSITORY https://github.com/pulzed/mINI.git
        GIT_TAG master
)
FetchContent_MakeAvailable(mini)

add_executable(apexdyn src/main.cpp src/DirectoryInspection.cpp)
target_include_directories(apexdyn PRIVATE include ${mini_SOURCE_DIR}/src)