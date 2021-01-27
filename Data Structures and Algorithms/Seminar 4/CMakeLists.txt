cmake_minimum_required(VERSION 3.15)
project(seminar_recursion_students)

set(CMAKE_C_STANDARD 99)

add_executable(seminar_recursion_students
        main.c
        seminar-recursion-exercises.c seminar-recursion-exercises.h)

target_link_libraries(seminar_recursion_students m)