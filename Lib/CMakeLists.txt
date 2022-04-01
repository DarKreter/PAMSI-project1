set(HEADER_LIST inc/Heap.hpp)

set(SRC_LIST src/Heap.cpp)

add_library(heap ${SRC_LIST} ${HEADER_LIST})

target_include_directories(heap PUBLIC . src inc)