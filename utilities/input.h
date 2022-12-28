#ifndef INPUT_H
#define INPUT_H

#include <filesystem>
#include <fstream>
#include <string>
#include <vector>

namespace Input
{
    std::vector<std::string> readLinesFromFile(const std::filesystem::path &path);
}

#endif // INPUT_H