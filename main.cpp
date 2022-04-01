#include "Heap.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <vector>

void ReadFromFile(std::vector<std::pair<uint32_t, std::string>>& v,
                  std::string fileName);

int main(int argc, char* argv[])
{
    if(argc != 2) {
        std::cout << "Incorrect call paramters!" << std::endl;
        exit(2);
    }
    std::string fileName = argv[1];

    // Create heap with initial size 2
    pamsi::Heap_t<std::string> heap(2);
    std::vector<std::pair<uint32_t, std::string>> randomData;

    // Save each line with its number as vector element
    ReadFromFile(randomData, fileName);

    // Shuffle vector content
    auto rd = std::random_device{};
    auto rng = std::default_random_engine{rd()};
    std::shuffle(std::begin(randomData), std::end(randomData), rng);

    // Insert elements of vector in random sequence
    for(auto& pair : randomData)
        heap.Insert(pair.first, pair.second);

    // Get elements from heap and write them to output file
    std::ofstream output1("result.txt");
    std::ofstream output2("shuffled.txt");
    uint32_t size = heap.Size();
    for(uint32_t i = 0; i < size; i++) {
        // Get the smallest value
        pamsi::Pair_t p = heap.Min();
        // Write it to file
        output1 << p.first() << ". " << p.second() << std::endl;
        // remove this value from heap
        heap.removeMin();

        // For reference write shuffled vector to another file
        auto [number1, line1] = randomData[i];
        output2 << number1 << ". " << line1 << std::endl;
    }

    return 0;
}

void ReadFromFile(std::vector<std::pair<uint32_t, std::string>>& v,
                  std::string fileName)
{
    std::ifstream file;
    file.open(fileName);

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
        v.push_back(std::make_pair(ordinalNumber, line));
    }
    file.close();
}