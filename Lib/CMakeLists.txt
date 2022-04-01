set(HEADER_LIST inc/List.hpp)

set(SRC_LIST src/List.cpp)

add_library(LIST ${SRC_LIST} ${HEADER_LIST})

target_include_directories(LIST PUBLIC . src inc)