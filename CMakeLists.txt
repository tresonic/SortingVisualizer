cmake_minimum_required(VERSION 3.12)

project(SortingVisualizer
  VERSION 0.1
  LANGUAGES CXX
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_subdirectory(dependencies)
add_subdirectory(src)
