cmake_minimum_required(VERSION 3.10)

project(PAMSI LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_compile_options(
        ${CPU_OPTIONS}
        -Werror
        -Wall
        -Wextra
        -pedantic
        -ffunction-sections
        -fdata-sections
        -Os
)

add_library(heap src/Heap.cpp inc/Heap.hpp fml/Heap.tpp)
add_library(pair src/Pair.cpp inc/Pair.hpp fml/Pair.tpp)

target_include_directories(heap PUBLIC . src inc fml)
target_include_directories(pair PUBLIC . src inc fml)

set(LIBS heap pair)

add_executable(firmware main.cpp)


target_link_libraries(firmware ${LIBS})

target_compile_options(firmware PUBLIC ${CPU_OPTIONS})