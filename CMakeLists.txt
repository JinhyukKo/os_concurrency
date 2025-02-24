cmake_minimum_required(VERSION 3.30)
project(concurrency C)

set(CMAKE_C_STANDARD 11)

add_executable(concurrency threads/pthread.c)
