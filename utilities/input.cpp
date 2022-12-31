#include "input.h"

namespace Input {

std::vector<std::string> readLinesFromFile(const std::filesystem::path& path) {
    std::vector<std::string> lines{};
    if (!std::filesystem::exists(path)) {
        return lines;
    }

    std::ifstream file_stream{path};
    std::string current_line;
    while (std::getline(file_stream, current_line)) {
        lines.emplace_back(current_line);
    }

    return lines;
}

std::vector<std::string> splitString(const std::string str, char delimiter) {
    std::vector<std::string> splitString{};
    std::string token;
    std::istringstream token_stream(str);

    while (getline(token_stream, token, delimiter)) {
        splitString.push_back(token);
    }

    return splitString;
}

} // namespace Input
