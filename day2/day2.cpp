#include "../utilities/input.h"
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>

#define INPUT_FILE "input.txt"

enum class Move { Rock, Paper, Scissors };
enum class Result { Loss, Draw, Win };

const std::unordered_map<Move, int> HandScores = {{Move::Rock, 1}, {Move::Paper, 2}, {Move::Scissors, 3}};
const std::unordered_map<Result, int> ResultScores = {{Result::Loss, 0}, {Result::Draw, 3}, {Result::Win, 6}};

// Key: std::pair<My Move, Opponent Move>  Value: Result
const std::map<std::pair<Move, Move>, Result> Results = {
    {{Move::Rock, Move::Rock}, Result::Draw},         {{Move::Rock, Move::Paper}, Result::Loss},
    {{Move::Rock, Move::Scissors}, Result::Win},      {{Move::Paper, Move::Rock}, Result::Win},
    {{Move::Paper, Move::Paper}, Result::Draw},       {{Move::Paper, Move::Scissors}, Result::Loss},
    {{Move::Scissors, Move::Rock}, Result::Loss},     {{Move::Scissors, Move::Paper}, Result::Win},
    {{Move::Scissors, Move::Scissors}, Result::Draw},
};

int part1(std::vector<std::string>& input) {
    int score = 0;
    for (const std::string& line : input) {

        Move opponent_hand = static_cast<Move>(line[0] - 'A');
        Move my_hand = static_cast<Move>(line[2] - 'X');

        int hand_score = HandScores.at(my_hand);
        int outcome_score = ResultScores.at(Results.at({my_hand, opponent_hand}));

        score += hand_score + outcome_score;
    }

    return score;
};

int part2(std::vector<std::string>& input) {

    int score = 0;
    for (const std::string& line : input) {

        Move opponent_hand = static_cast<Move>(line[0] - 'A');
        Result result = static_cast<Result>(line[2] - 'X');

        Move my_move;
        for (const std::pair<std::pair<Move, Move>, Result>& p : Results) {
            if (Results.at(std::make_pair(static_cast<Move>(p.first.first), opponent_hand)) == result) {
                my_move = p.first.first;
                break;
            }
        }

        int hand_score = HandScores.at(my_move);
        int outcome_score = ResultScores.at(result);

        score += hand_score + outcome_score;
    }

    return score;
}

int main() {
    std::vector<std::string> input = Input::readLinesFromFile(INPUT_FILE);

    int part1_answer = part1(input);
    std::cout << "The answer to part 1 is: " << part1_answer << std::endl;

    int part2_answer = part2(input);
    std::cout << "The answer to part 2 is: " << part2_answer << std::endl;

    return 0;
}
