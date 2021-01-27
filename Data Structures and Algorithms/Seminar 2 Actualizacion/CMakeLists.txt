cmake_minimum_required(VERSION 3.15)
project(seminar_files_students)

set(CMAKE_C_STANDARD 99)

add_executable(seminar_files_students
        main.c
        seminar-files-exercises.c seminar-files-exercises.h
        common.h)

add_custom_command(TARGET seminar_files_students POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${PROJECT_SOURCE_DIR}/resources/
        $<TARGET_FILE_DIR:seminar_files_students>/)
