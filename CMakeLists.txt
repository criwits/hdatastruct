cmake_minimum_required(VERSION 3.20)
project(hdatastruct C)

set(CMAKE_C_STANDARD 99)

include_directories(${PROJECT_SOURCE_DIR}/include)
aux_source_directory(${PROJECT_SOURCE_DIR}/src/stack DIR_SRCS)

add_executable(hdatastruct main.c ${DIR_SRCS} src/stack/hds_stack_destroy.c)
