cmake_minimum_required(VERSION 3.10)
project(c_collections C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pedantic -Wvla -Werror -Wall -D_DEFAULT_SOURCE")

option(ENABLE_ARRAYLIST "Build the ArrayList module" ON)

include_directories(include)

if(ENABLE_ARRAYLIST)
    add_library(collections_arraylist src/arraylist.c)

    install(TARGETS collections_arraylist DESTINATION lib)
    install(FILES include/arraylist.h DESTINATION include)
endif()
