#ifndef LIST_PAMSI_PROJECT_DEFINE
#define LIST_PAMSI_PROJECT_DEFINE

#include "Pair.hpp"
#include <stdint.h>

namespace pamsi {

template <typename ValueType>
class Heap_t {
private:
    typedef uint32_t size_t;
    typedef Pair_t<size_t, ValueType> PairType_t;

    size_t _maxSize;
    size_t _size;
    PairType_t* _tab;

    size_t Parent(size_t idx) const;
    size_t LeftChild(size_t idx) const;
    size_t RightChild(size_t idx) const;

    void UpHeap(size_t idx);
    void DownHeap(size_t idx);
    void Swap(size_t idx1, size_t idx2);

    void CheckMaxSize();

public:
    Heap_t(uint32_t initialSize);

    void Insert(PairType_t object);
    void Insert(size_t, ValueType);
    void removeMin();
    [[nodiscard]] PairType_t Min() const;
    [[nodiscard]] size_t Size() const;
    [[nodiscard]] bool IsEmpty() const;
};

} // namespace pamsi

#include "Heap.tpp"

#endif // LIST_PAMSI_PROJECT_DEFINE