#include "Heap.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    std::vector<int> input = {1, 10, 3, 4, 5, 6, 7};

    pamsi::Heap_t test(10);

    for(auto& i : input)
        test.Insert(i);

    cout << test._size << endl;

    for(uint32_t i = 0; i < test._size; i++)
        cout << test._tab[i] << " ";

    return 0;
}