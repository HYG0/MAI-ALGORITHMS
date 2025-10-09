cmake_minimum_required(VERSION 3.10)

project(Fund-algos)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_C_FLAGS_DEBUG "-g -O0 -Wall -Wextra")

# Settings for Task_1
# add_library(Modules STATIC src/modules.c)

# add_executable(Cli_app CLI_1.c)

# target_link_libraries(Cli_app Modules)
# target_link_libraries(Cli_app m)

# target_compile_options(Cli_app PUBLIC -std=c99)


# Settings for Task_2
add_library(Modules STATIC src/modules_lab_2.c)

add_executable(Task_2 Task_2.c)

target_link_libraries(Task_2 Modules)
target_link_libraries(Task_2 m)

target_compile_options(Task_2 PUBLIC -std=c99)