#include "../utilities/input.h"
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/classification.hpp> // Include boost::for is_any_of
#include <boost/algorithm/string/split.hpp>          // Include for boost::split
#include <boost/range/algorithm/remove_if.hpp>
#include <iostream>
#include <map>
#include <regex>
#include <stack>
#include <string>
#include <tuple>
#include <vector>

#define INPUT_FILE "input.txt"

std::map<int, std::vector<char>> parseInitialStacks(std::vector<std::string> input, int column_count,
                                                    int column_height) {
    std::map<int, std::vector<char>> stackMap{};
    for (int i = 0; i < column_count; i++) {
        stackMap.insert({i, std::vector<char>{}});
    }

    int realColumn = 0;
    for (int column = 1; column <= column_count * 4; column += 4) {
        for (int row = column_height - 1; row >= 0; row--) {
            if (isalpha(input[row][column])) {
                stackMap[realColumn].emplace_back(input[row][column]);
            }
        }
        realColumn++;
    }

    return stackMap;
}

std::tuple<int, int, int> parseInstruction(std::string& instruction) {
    std::vector<std::string> instructions{};
    boost::split(instructions, instruction, boost::is_any_of("move from to"), boost::token_compress_on);
    return std::make_tuple(stoi(instructions[1]), stoi(instructions[2]), stoi(instructions[3]));
}

std::string part1(std::vector<std::string> input) {
    int column_height = 0;
    while (true) {
        if (isdigit(input[column_height][1])) {
            break;
        }
        column_height++;
    }

    int column_count = 0;
    for (int i = 0; i < input[column_height].size(); i++) {
        if (isdigit(input[column_height][i])) {
            column_count++;
        }
    }

    std::map<int, std::vector<char>> stackMap = parseInitialStacks(input, column_count, column_height);

    for (int instructionRow = column_height + 2; instructionRow < input.size(); instructionRow++) {
        int moveCount, moveFrom, moveTo;
        std::tie(moveCount, moveFrom, moveTo) = parseInstruction(input[instructionRow]);
        moveFrom--;
        moveTo--;
        for (int i = 0; i < moveCount; i++) {
            stackMap[moveTo].emplace_back(stackMap[moveFrom].back());
            stackMap[moveFrom].pop_back();
        }
    }

    std::string topCreates{};
    for (int i = 0; i < column_count; i++) {
        std::vector<char> currentStack = stackMap[i];
        topCreates += currentStack.back();
    }
    return topCreates;
};

std::string part2(std::vector<std::string> input) {
    int column_height = 0;
    while (true) {
        if (isdigit(input[column_height][1])) {
            break;
        }
        column_height++;
    }

    int column_count = 0;
    for (int i = 0; i < input[column_height].size(); i++) {
        if (isdigit(input[column_height][i])) {
            column_count++;
        }
    }
    std::map<int, std::vector<char>> stackMap = parseInitialStacks(input, column_count, column_height);

    for (int instructionRow = column_height + 2; instructionRow < input.size(); instructionRow++) {
        int moveCount, moveFrom, moveTo;
        std::tie(moveCount, moveFrom, moveTo) = parseInstruction(input[instructionRow]);
        moveFrom--;
        moveTo--;
        for (int i = moveCount - 1; i >= 0; i--) {
            stackMap[moveTo].emplace_back(stackMap[moveFrom][stackMap[moveFrom].size() - i - 1]);
            stackMap[moveFrom].erase(stackMap[moveFrom].end() - i - 1);
        }
    }

    std::string topCreates{};
    for (int i = 0; i < column_count; i++) {
        std::vector<char> currentStack = stackMap[i];
        topCreates += currentStack.back();
    }

    return topCreates;
}

int main() {
    std::vector<std::string> input = Input::readLinesFromFile(INPUT_FILE);

    std::string part1_answer = part1(input);
    std::cout << "The answer to part 1 is: " << part1_answer << std::endl;

    std::string part2_answer = part2(input);
    std::cout << "The answer to part 2 is: " << part2_answer << std::endl;

    return 0;
}
