cmake_minimum_required(VERSION 3.6)

project(client)

file(GLOB_RECURSE SOURCES src/*.c)

add_executable(client ${SOURCES})

target_link_libraries (client zmq jsmn) 

include_directories(jsmn)

link_directories (jsmn) 