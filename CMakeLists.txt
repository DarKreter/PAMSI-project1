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

set(LIBS heap)

add_executable(firmware main.cpp)


target_link_libraries(firmware ${LIBS})

target_compile_options(firmware PUBLIC ${CPU_OPTIONS})

add_subdirectory(Lib)