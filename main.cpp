#include "Heap.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    std::vector<int> input = {5, 12, 67, 4, 3, 6, 1, 1, 5, 4, 7, 4, 8, 45, 6, 34};

    for(auto& i : input)
        cout << i << " ";

    return 0;
}