add_library(heap src/Heap.cpp inc/Heap.hpp fml/Heap.tpp)
add_library(pair src/Pair.cpp inc/Pair.hpp fml/Pair.tpp)

target_include_directories(heap PUBLIC . src inc fml)
target_include_directories(pair PUBLIC . src inc fml)