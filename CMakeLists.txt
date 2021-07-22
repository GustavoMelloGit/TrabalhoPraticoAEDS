cmake_minimum_required(VERSION 3.19)
project(TrabalhoPratico C)

set(CMAKE_C_STANDARD 11)

set(PROJECT_HEADERS
        pilhaCaluladora.h
        )

add_executable(TrabalhoPratico
        main.c
        pilhaCalculadora.c
        )