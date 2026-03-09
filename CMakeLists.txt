cmake_minimum_required(VERSION 3.15)

execute_process(COMMAND xcrun --show-sdk-path OUTPUT_VARIABLE XCRUN_SDK_PATH OUTPUT_STRIP_TRAILING_WHITESPACE)
set(CMAKE_OSX_SYSROOT ${XCRUN_SDK_PATH})
set(CMAKE_CXX_COMPILER g++-14)

project(scrabble-engine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE SOURCES "*.cpp")
add_executable(scrabble ${SOURCES})