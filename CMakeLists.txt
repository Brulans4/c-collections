cmake_minimum_required(VERSION 3.10)
project(c_collections C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pedantic -Wvla -Werror -Wall -D_DEFAULT_SOURCE")

include_directories(include)

set(LIB_SOURCES
    src/arraylist.c
)

add_library(collections STATIC ${LIB_SOURCES})

add_executable(test_arraylist tests/test_arraylist.c)
target_link_libraries(test_arraylist collections)
