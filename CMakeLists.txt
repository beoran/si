cmake_minimum_required(VERSION 2.8)
# Set policy: link_directories is relative to source dir
cmake_policy(SET CMP0015 NEW)

set(CMAKE_C_FLAGS "-Wall -Wno-unused -Wno-unknown-pragmas -g -std=gnu99 -ffast-math")  
# always use gnu99, debugging, all warnings except unused and unknown pragmas.


include_directories("include")
include_directories("include/si")

link_directories("src")
add_subdirectory("src")


enable_testing()
# Let ctest run valgrind
set(CMAKE_CTEST_OPTIONS --output-on-failure)
set(CTEST_OUTPUT_ON_FAILURE TRUE)
set(CTEST_MEMORYCHECK_COMMAND:FILEPATH "/usr/bin/valgrind")
add_subdirectory("test")

# Install targets 
#INSTALL(FILES file1.h file2.h ${CMAKE_CURRENT_BINARY_DIR}/file3.h
#  DESTINATION include)
#  FILE(GLOB files "${CMAKE_CURRENT_SOURCE_DIR}/*.hxx")
#  INSTALL(FILES ${files} DESTINATION include)







