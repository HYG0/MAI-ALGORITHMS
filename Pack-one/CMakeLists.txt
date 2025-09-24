cmake_minimum_required(VERSION 3.10)

project(Fund-alogos)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

add_library(Modules STATIC src/modules.c)

add_executable(Cli_app CLI_1.c)

target_link_libraries(Cli_app Modules)