#[=============================================================================[
# SPDX-License-Identifier: Apache-2.0
# SPDX-FileCopyrightText: 2021 Avinal Kumar <avinal.xlvii@gmail.com>
#]=============================================================================]

cmake_minimum_required(VERSION 3.16)
project(basic LANGUAGES C)

file(GLOB BASIC_SRC src/*.c)
add_library(basic "")
target_sources(basic PRIVATE ${BASIC_SRC})
target_include_directories(basic PRIVATE include/basic)

add_executable(basic_exec main.cc)
target_include_directories(basic_exec PRIVATE include/basic)
target_link_libraries(basic_exec PRIVATE basic)


