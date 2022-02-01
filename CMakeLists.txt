# This is an example of how to use FetchContent to easily
# manage 3rd-party dependencies
# First, check out src/CMakeLists.txt - it's really simple!
# Then, check out dependencies directory, it get a bit more complex
# there, but you'll see how it goes
#
# Options:
# * USE_SYSTEM_DEPS - try to find dependencies using find_package (OFF by default)
# * LINK_DEPS_STATIC - link to dependencies statically (ON by default)
#
cmake_minimum_required(VERSION 3.12)

project(SortingVisualizer
  VERSION 0.1
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_subdirectory(dependencies)
add_subdirectory(src)
