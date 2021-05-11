cmake_minimum_required(VERSION 3.20)

project(expression)

aux_source_directory(. SRC_LIST)

add_executable(main ${SRC_LIST})