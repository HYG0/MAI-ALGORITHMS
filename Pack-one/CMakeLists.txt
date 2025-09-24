cmake_minimum_required(VERSION 3.10)

project(Fund-alogos)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

add_library(Modules STATIC src/modules.c)

add_executable(Cli_app CLI_1.c)

target_link_libraries(Cli_app Modules)
target_link_libraries(Cli_app m)

target_compile_options(Cli_app PUBLIC -std=c99 -lm)