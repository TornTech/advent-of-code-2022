#include "../utilities/input.h"
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>

#define INPUT_FILE "input.txt"

int part1(std::vector<std::string> input) {
    int sum = 0;
    for (std::string rucksack : input) {
        int mid = rucksack.size() / 2;
        std::set<char> itemCountsLeft{};

        for (char item : rucksack.substr(0, mid)) {
            itemCountsLeft.insert(item);
        }

        for (char item : rucksack.substr(mid)) {
            if (itemCountsLeft.find(item) != itemCountsLeft.end()) {
                sum += isupper(item) ? static_cast<int>(item) - 64 + 26 : static_cast<int>(item) - 96;
                break;
            }
        }
    }
    return sum;
};

int part2(std::vector<std::string> input) {
    int sum = 0;
    int elf_group_count = 0;
    std::set<char> rucksack_first{};
    std::set<char> rucksack_second{};
    for (std::string rucksack : input) {
        if (elf_group_count % 3 == 0) {
            for (char item : rucksack) {
                rucksack_first.insert(item);
            }
            elf_group_count++;
        } else if (elf_group_count % 3 == 1) {
            for (char item : rucksack) {
                rucksack_second.insert(item);
            }
            elf_group_count++;
        } else {
            for (char item : rucksack) {
                if (rucksack_first.find(item) != rucksack_first.end() &&
                    rucksack_second.find(item) != rucksack_second.end()) {
                    sum += isupper(item) ? static_cast<int>(item) - 64 + 26 : static_cast<int>(item) - 96;
                    break;
                }
            }
            elf_group_count = 0;
            rucksack_first.clear();
            rucksack_second.clear();
        }
    }
    return sum;
}

int main() {
    std::vector<std::string> input = Input::readLinesFromFile(INPUT_FILE);

    int part1_answer = part1(input);
    std::cout << "The answer to part 1 is: " << part1_answer << std::endl;

    int part2_answer = part2(input);
    std::cout << "The answer to part 2 is: " << part2_answer << std::endl;

    return 0;
}
