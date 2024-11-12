# stop if cmake version is below 3.0
cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

# project name and enable C++ support
# project(testbed LANGUAGES CXX)

message(STATUS "Generating CXX Code...")

# require C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# we define the executable
add_executable(testbed "")

file(GLOB_RECURSE HEADERS *.h)
file(GLOB_RECURSE SOURCES *.cc *.c)

# and its sources
target_sources(
  testbed
  PRIVATE
    ${SHARED}
    ${SOURCES}
  )
  