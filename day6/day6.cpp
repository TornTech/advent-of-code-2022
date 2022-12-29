#include "../utilities/input.h"
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

#define INPUT_FILE "input.txt"

int part1(std::string& input) {
    std::vector<char> lastThreeChars{input[0], input[1], input[2]};

    for (int i = 3; i < input.size(); i++) {
        char currChar = input[i];

        std::set<char> uniqueSet{lastThreeChars.begin(), lastThreeChars.end()};
        if (uniqueSet.size() != lastThreeChars.size() || uniqueSet.contains(currChar)) {
            lastThreeChars.erase(lastThreeChars.begin());
            lastThreeChars.emplace_back(currChar);
            continue;
        }

        if (std::find(lastThreeChars.begin(), lastThreeChars.end(), currChar) == lastThreeChars.end()) {
            return i + 1;
        }
    }

    std::cout << "Did not find non-repeating character" << std::endl;
    return 0;
};

int part2(std::string& input) {
    std::vector<char> lastThirteenChars{input.begin(), input.begin() + 13};

    for (int i = 13; i < input.size(); i++) {
        char currChar = input[i];

        std::set<char> uniqueSet{lastThirteenChars.begin(), lastThirteenChars.end()};
        if (uniqueSet.size() != lastThirteenChars.size() || uniqueSet.contains(currChar)) {
            lastThirteenChars.erase(lastThirteenChars.begin());
            lastThirteenChars.emplace_back(currChar);
            continue;
        }

        if (std::find(lastThirteenChars.begin(), lastThirteenChars.end(), currChar) == lastThirteenChars.end()) {
            return i + 1;
        }
    }

    std::cout << "Did not find non-repeating character" << std::endl;
    return 0;
}

int main() {
    std::vector<std::string> input = Input::readLinesFromFile(INPUT_FILE);

    int part1_answer = part1(input[0]);
    std::cout << "The answer to part 1 is: " << part1_answer << std::endl;

    int part2_answer = part2(input[0]);
    std::cout << "The answer to part 2 is: " << part2_answer << std::endl;

    return 0;
}
