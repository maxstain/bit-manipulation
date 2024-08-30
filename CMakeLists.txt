cmake_minimum_required(VERSION 3.28)
project(bit_manipulations C)

set(CMAKE_C_STANDARD 23)

add_executable(bit_manipulations main.c
        headers/main.h
        Motor/check_motor_fault.c
        headers/check_motor_fault.h
        Motor/display_motor_info.c
        headers/display_motor_info.h
        Motor/motor_init.c
        headers/motor_init.h)
