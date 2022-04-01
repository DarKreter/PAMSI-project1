#include "Heap.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <vector>

int main()
{
    std::vector<int> input = {2, 5, 6, 9};

    pamsi::Heap_t<std::string> test(2);

    std::vector<std::pair<uint32_t, std::string>> randomData;
    std::ifstream file;
    file.open("../PanTadeusz.txt");

    if(!file.is_open()) {
        std::cout << "Error opening file to read!" << std::endl;
        exit(1);
    }

    std::string line;
    char null;
    uint32_t ordinalNumber;
    while(!file.eof()) {
        file >> ordinalNumber >> std::ws >> null;
        getline(file, line);
        randomData.push_back(std::make_pair(ordinalNumber, line));
    }
    file.close();

    auto rd = std::random_device{};
    auto rng = std::default_random_engine{rd()};
    std::shuffle(std::begin(randomData), std::end(randomData), rng);

    for(auto& pair : randomData)
        test.Insert(pair.first, pair.second);

    std::ofstream output1("../output1.txt");
    std::ofstream output2("../output2.txt");
    uint32_t size = test.Size();
    for(uint32_t i = 0; i < size; i++) {
        pamsi::Pair_t p = test.Min();
        output1 << p.first() << ". " << p.second() << std::endl;
        test.removeMin();

        auto [number1, line1] = randomData[i];
        output2 << number1 << ". " << line1 << std::endl;
    }

    return 0;
}