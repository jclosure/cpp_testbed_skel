# stop if cmake version is below 3.0
cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

message(STATUS "Generating C Code...")

# we define the executable
add_executable(testbed "")

file(GLOB_RECURSE HEADERS *.h)
file(GLOB_RECURSE SOURCES *.c)

# and its sources
target_sources(
  testbed
  PRIVATE
    ${HEADERS}
    ${SOURCES}
  )