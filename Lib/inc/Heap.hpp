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

    void UpHeap(size_t idx);
    void DownHeap(size_t idx);
    void Swap(size_t idx1, size_t idx2);

public:
    Heap_t(uint32_t initialSize);

    void Insert(T object);
    void removeMin();
    [[nodiscard]] T Min() const;
    [[nodiscard]] size_t Size() const;
    [[nodiscard]] bool IsEmpty() const;
};

} // namespace pamsi

#endif // LIST_PAMSI_PROJECT_DEFINE