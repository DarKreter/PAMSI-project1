#ifndef LIST_PAMSI_PROJECT_DEFINE
#define LIST_PAMSI_PROJECT_DEFINE

#include <stdint.h>
#include <string>
#include <utility>


namespace pamsi {

class Heap_t {
private:
    typedef std::string T;
    typedef uint32_t size_t;
    typedef std::pair<size_t, T> pairT;

    size_t _maxSize;
    size_t _size;
    pairT* _tab;

    size_t Parent(size_t idx) const;
    size_t LeftChild(size_t idx) const;
    size_t RightChild(size_t idx) const;

    void UpHeap(size_t idx);
    void DownHeap(size_t idx);
    void Swap(size_t idx1, size_t idx2);

public:
    Heap_t(uint32_t initialSize);

    void Insert(pairT object);
    void removeMin();
    [[nodiscard]] pairT Min() const;
    [[nodiscard]] size_t Size() const;
    [[nodiscard]] bool IsEmpty() const;
};

} // namespace pamsi

#endif // LIST_PAMSI_PROJECT_DEFINE