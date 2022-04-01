#ifndef LIST_PAMSI_PROJECT_DEFINE
#define LIST_PAMSI_PROJECT_DEFINE

#include <stdint.h>

namespace pamsi {

class Heap_t {
public:
    typedef int16_t T;
    typedef uint32_t size_t;

    size_t _maxSize;
    size_t _size;
    T* _tab;

    size_t Parent(size_t idx) const;
    size_t LeftChild(size_t idx) const;
    size_t RightChild(size_t idx) const;

    void UpHead(size_t idx);
    void Swap(size_t idx1, size_t idx2);

public:
    Heap_t(uint32_t initialSize);

    void Insert(T object);
};

} // namespace pamsi

#endif // LIST_PAMSI_PROJECT_DEFINE