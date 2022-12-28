#include "../utilities/input.h"
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#define INPUT_FILE "input.txt"

int part2(std::vector<std::string> input) {
    std::vector<int> elfSumVector{};

    int curr_elf = 0;
    for (std::string &line : input) {
        if (line.empty()) {
            elfSumVector.emplace_back(curr_elf);
            curr_elf = 0;
        } else {
            curr_elf += std::stoi(line);
        }
    }
    std::sort(elfSumVector.begin(), elfSumVector.end(), std::greater<>());
    return elfSumVector[0] + elfSumVector[1] + elfSumVector[2];
};

int part1(std::vector<std::string> input) {
    int max = 0, curr_elf = 0;
    for (std::string &line : input) {
        if (line.empty()) {
            max = std::max(curr_elf, max);
            curr_elf = 0;
        } else {
            curr_elf += std::stoi(line);
        }
    }
    return max;
};

int main() {
    std::vector<std::string> input = Input::readLinesFromFile(INPUT_FILE);

    std::cout << "The answer to part 1 is: " << part1(input) << std::endl;
    std::cout << "The answer to part 2 is: " << part2(input) << std::endl;

    return 0;
}
