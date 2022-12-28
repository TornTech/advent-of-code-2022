#include "../utilities/input.h"
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>

#define INPUT_FILE "input.txt"

int part1(std::vector<std::string> input) {
    int CountOfFullyContained = 0;
    for (std::string line : input) {
        std::string elfOne = line.substr(0, line.find(","));
        std::string elfTwo = line.substr(line.find(",") + 1);

        int elfOneBegin = stoi(elfOne.substr(0, elfOne.find('-')));
        int elfOneEnd = stoi(elfOne.substr(elfOne.find('-') + 1));
        int elfTwoBegin = stoi(elfTwo.substr(0, elfTwo.find('-')));
        int elfTwoEnd = stoi(elfTwo.substr(elfTwo.find('-') + 1));

        if ((elfOneBegin <= elfTwoBegin && elfOneEnd >= elfTwoEnd) ||
            (elfTwoBegin <= elfOneBegin && elfTwoEnd >= elfOneEnd)) {
            CountOfFullyContained++;
        }
    }
    return CountOfFullyContained;
};

int part2(std::vector<std::string> input) {
    int CountOfFullyContained = 0;
    for (std::string line : input) {
        std::string elfOne = line.substr(0, line.find(","));
        std::string elfTwo = line.substr(line.find(",") + 1);

        int elfOneBegin = stoi(elfOne.substr(0, elfOne.find('-')));
        int elfOneEnd = stoi(elfOne.substr(elfOne.find('-') + 1));
        int elfTwoBegin = stoi(elfTwo.substr(0, elfTwo.find('-')));
        int elfTwoEnd = stoi(elfTwo.substr(elfTwo.find('-') + 1));

        if ((elfTwoBegin <= elfOneBegin && elfTwoEnd >= elfOneBegin) ||
            (elfOneBegin <= elfTwoBegin && elfOneEnd >= elfTwoBegin)) {
            CountOfFullyContained++;
        }
    }

    return CountOfFullyContained;
}

int main() {
    std::vector<std::string> input = Input::readLinesFromFile(INPUT_FILE);

    int part1_answer = part1(input);
    std::cout << "The answer to part 1 is: " << part1_answer << std::endl;

    int part2_answer = part2(input);
    std::cout << "The answer to part 2 is: " << part2_answer << std::endl;

    return 0;
}
