#include "Heap.hpp"

namespace pamsi {

template <typename ValueType>
Heap_t<ValueType>::Heap_t(uint32_t initialSize) : _maxSize{initialSize}, _size{}
{
    _tab = new PairType_t[_maxSize];
}

template <typename ValueType>
auto Heap_t<ValueType>::Parent(size_t idx) const -> size_t
{
    return (idx - 1) / 2;
}

template <typename ValueType>
auto Heap_t<ValueType>::LeftChild(size_t idx) const -> size_t
{
    return (idx * 2) + 1;
}

template <typename ValueType>
auto Heap_t<ValueType>::RightChild(size_t idx) const -> size_t
{
    return (idx * 2) + 2;
}

template <typename ValueType>
void Heap_t<ValueType>::Insert(PairType_t object)
{
    CheckMaxSize();

    _tab[_size] = object;

    UpHeap(_size++);
}

template <typename ValueType>
void Heap_t<ValueType>::CheckMaxSize()
{
    if(_size == _maxSize) {
        _maxSize *= 2;

        PairType_t* newTab = new PairType_t[_maxSize];

        for(size_t i = 0; i < _size; i++)
            newTab[i] = _tab[i];

        delete[] _tab;
        _tab = newTab;
    }
}

template <typename ValueType>
void Heap_t<ValueType>::Insert(size_t key, ValueType value)
{
    PairType_t object(key, value);

    CheckMaxSize();

    _tab[_size] = object;

    UpHeap(_size++);
}

template <typename ValueType>
void Heap_t<ValueType>::UpHeap(size_t idx)
{
    while(idx != 0 && _tab[idx] < _tab[Parent(idx)]) {
        Swap(idx, Parent(idx));
        idx = Parent(idx);
    }
}

template <typename ValueType>
void Heap_t<ValueType>::DownHeap(size_t idx)
{
    size_t smallest = idx;
    while(true) {
        if(LeftChild(idx) < _size && _tab[LeftChild(idx)] < _tab[idx])
            smallest = LeftChild(idx);
        if(RightChild(idx) < _size && _tab[RightChild(idx)] < _tab[smallest])
            smallest = RightChild(idx);
        if(smallest != idx) {
            Swap(idx, smallest);
            idx = smallest;
        }
        else
            break;
    }

    while(idx != 0 && _tab[idx] < _tab[Parent(idx)]) {
        Swap(idx, Parent(idx));
        idx = Parent(idx);
    }
}

template <typename ValueType>
void Heap_t<ValueType>::Swap(size_t idx1, size_t idx2)
{
    PairType_t temp = _tab[idx1];
    _tab[idx1] = _tab[idx2];
    _tab[idx2] = temp;
}

template <typename ValueType>
void Heap_t<ValueType>::removeMin()
{
    _tab[0] = _tab[--_size];

    DownHeap(0);
}

template <typename ValueType>
auto Heap_t<ValueType>::Min() const -> PairType_t
{
    return _tab[0];
}

template <typename ValueType>
auto Heap_t<ValueType>::Size() const -> size_t
{
    return _size;
}

template <typename ValueType>
bool Heap_t<ValueType>::IsEmpty() const
{
    return _size == 0;
}

} // namespace pamsi
