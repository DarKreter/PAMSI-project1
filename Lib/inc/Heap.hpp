#ifndef LIST_PAMSI_PROJECT_DEFINE
#define LIST_PAMSI_PROJECT_DEFINE

#include "Pair.hpp"
#include <stdint.h>

namespace pamsi {

/**
 * @brief Data structare representing heap. Stores smaller values
 * higher(MinHeap). This heap is based on priority list and compares nodes only
 * by key. Heap based on array.
 *
 */
template <typename ValueType>
class Heap_t {
private:
    typedef uint32_t size_t;
    typedef Pair_t<size_t, ValueType> PairType_t;

    // Size of alocated memory for array
    size_t _maxSize;
    // Actual size of heap
    size_t _size;
    // Main dynamic array
    PairType_t* _tab;

    /**
     * @brief Calculating Parent node index.
     *
     * @param idx node index
     * @return size_t parent node index
     */
    size_t Parent(size_t idx) const;
    /**
     * @brief Calculating left child node index.
     *
     * @param idx left child index
     * @return size_t left child node index
     */
    size_t LeftChild(size_t idx) const;
    /**
     * @brief Calculating right child node index.
     *
     * @param idx right child index
     * @return size_t right child node index
     */
    size_t RightChild(size_t idx) const;

    /**
     * @brief Checks if node is in right position in heap. If not transport it
     * as high as possible.
     *
     * @param idx index of node to check
     */
    void UpHeap(size_t idx);
    /**
     * @brief Checks if node is in right position in heap. If not transport it
     * as low as possible.
     *
     * @param idx index of node to check
     */
    void DownHeap(size_t idx);
    /**
     * @brief Swapping places of two nodes.
     *
     * @param idx1 index of first node
     * @param idx2 index of second node
     */
    void Swap(size_t idx1, size_t idx2);

    /**
     * @brief Checks if we have achieved maximum size of array. Compares _size
     * with _maxSize. If limit is reached, new array is allocated doubly larger.
     * After allocating new array, values are copied from the old one and old
     * one is deleted.
     *
     */
    void CheckMaxSize();

public:
    /**
     * @brief Construct a new Heap_t object
     *
     * @param initialSize initial size for array. It's recommended to set this
     * to anticipated size of heap.
     */
    Heap_t(uint32_t initialSize);

    /**
     * @brief Inserting object to heap.
     *
     * @param object object to insert
     */
    void Insert(PairType_t object);
    /**
     * @brief Inserting object to heap
     *
     * @param key @param value from this values, pair will be created
     */
    void Insert(size_t key, ValueType value);
    /**
     * @brief Removing smallest value from heap
     *
     */
    void removeMin();
    /**
     * @brief Getter for minimal value
     *
     * @return PairType_t pair with the smallest key
     */
    [[nodiscard]] PairType_t Min() const;
    /**
     * @brief Gives information about actual size of heap
     *
     * @return size_t size of heap
     */
    [[nodiscard]] size_t Size() const;
    /**
     * @brief Tells if heap is empty or not
     *
     * @return true if is empty
     * @return false if is not empty
     */
    [[nodiscard]] bool IsEmpty() const;
};

} // namespace pamsi

#include "Heap.tpp"

#endif // LIST_PAMSI_PROJECT_DEFINE