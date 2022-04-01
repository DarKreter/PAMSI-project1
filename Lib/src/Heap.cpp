#include "Heap.hpp"
#include <iostream>

namespace pamsi {

Heap_t::Heap_t(uint32_t initialSize) : _maxSize{initialSize}, _size{}
{
    _tab = new T[_maxSize];
}

auto Heap_t::Parent(size_t idx) const -> size_t { return (idx - 1) / 2; }
auto Heap_t::LeftChild(size_t idx) const -> size_t { return (idx * 2) + 1; }
auto Heap_t::RightChild(size_t idx) const -> size_t { return (idx * 2) + 2; }

void Heap_t::Insert(T object)
{
    // check if we have space

    _tab[_size] = object;

    UpHeap(_size++);
}

void Heap_t::UpHeap(size_t idx)
{
    while(idx != 0 && _tab[idx] < _tab[Parent(idx)]) {
        Swap(idx, Parent(idx));
        idx = Parent(idx);
    }
}

void Heap_t::DownHeap(size_t idx)
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

void Heap_t::Swap(size_t idx1, size_t idx2)
{
    T temp = _tab[idx1];
    _tab[idx1] = _tab[idx2];
    _tab[idx2] = temp;
}

void Heap_t::removeMin()
{
    _tab[0] = _tab[--_size];

    DownHeap(0);
}

auto Heap_t::Min() const -> T { return _tab[0]; }
auto Heap_t::Size() const -> size_t { return _size; }

bool Heap_t::IsEmpty() const { return _size == 0; }

} // namespace pamsi
