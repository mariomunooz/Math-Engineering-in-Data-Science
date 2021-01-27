cmake_minimum_required(VERSION 3.15)
project(Lab2 C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_executable(Lab2
        include/commons.h
        src/file_utils.c
        include/file_utils.h
        src/main.c
        include/main.h
        src/tree.c
        include/tree.h
        src/word_info.c
        include/word_info.h)
