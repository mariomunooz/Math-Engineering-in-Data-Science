cmake_minimum_required(VERSION 3.15)
project(Lab1 C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_executable(Lab1
        include/hash_table.h
        include/linked_list.h
        include/utils.h
        include/word_info.h
        src/hash_table.c
        src/linked_list.c
        src/main.c
        src/utils.c
        src/word_info.c
        include/test.h
        src/test.c)
