# stop if cmake version is below 3.0
cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

### COMMENT/UNCOMMENT "C PROG" AND "CXX PROG" TO SWITCH BETWEEN C <=> CPP

## C PROG
project(testbed LANGUAGES C)
add_subdirectory("./c") 

## CXX PROG
# project(testbed LANGUAGES CXX)
# add_subdirectory("./cpp") 