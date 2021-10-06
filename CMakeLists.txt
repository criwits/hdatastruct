cmake_minimum_required(VERSION 3.20)
project(hdatastruct C)

set(CMAKE_C_STANDARD 99)

include_directories(${PROJECT_SOURCE_DIR}/include)
aux_source_directory(${PROJECT_SOURCE_DIR}/src/stack HDS_STACK_DIR)
aux_source_directory(${PROJECT_SOURCE_DIR}/src/queue HDS_QUEUE_DIR)

add_executable(hdatastruct main.c ${HDS_STACK_DIR} ${HDS_QUEUE_DIR} src/queue/hds_queue_enqueue.c)