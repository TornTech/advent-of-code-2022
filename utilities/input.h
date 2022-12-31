#ifndef INPUT_H
#define INPUT_H

#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace Input {
std::vector<std::string> readLinesFromFile(const std::filesystem::path& path);

std::vector<std::string> splitString(const std::string str, char delimiter);
} // namespace Input

#endif // INPUT_H