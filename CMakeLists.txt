cmake_minimum_required(VERSION 3.10)

project(NvimClutch)

# For LSP
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Contains the source for the nclutch daemon
add_subdirectory(nclutch)

# Contains the source for the C++ Serial communication library (Linux)
add_subdirectory(CppLinuxSerial)
