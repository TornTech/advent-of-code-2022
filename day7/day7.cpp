#include "../utilities/input.h"
#include <iostream>
#include <memory>
#include <numeric>
#include <string>
#include <vector>

#define INPUT_FILE "input.txt"
#define MAX_DIR_SIZE 100000
#define TOTAL_SPACE 70000000
#define NEEDED_SPACE 30000000

struct File {
    File(const std::string name, int size) : fileName(name), fileSize(size){};

    std::string fileName{};
    size_t fileSize;
};

struct Directory {
    Directory(const std::string& name) : dirName(name){};

    std::string dirName{};
    size_t dirSize{0};
    std::shared_ptr<Directory> parentDir{};
    std::vector<std::shared_ptr<Directory>> childDirs{};
    std::vector<std::shared_ptr<File>> childFiles{};
};

long fillDirectorySize(std::shared_ptr<Directory> dir) {

    for (std::shared_ptr<File> currFile : dir->childFiles) {
        dir->dirSize += currFile->fileSize;
    }

    for (std::shared_ptr<Directory> childDir : dir->childDirs) {
        long childDirSize = fillDirectorySize(childDir);
        dir->dirSize += childDirSize;
    }

    return dir->dirSize;
}

std::vector<std::shared_ptr<Directory>> parseDirectories(std::vector<std::string>& input) {
    std::vector<std::shared_ptr<Directory>> allDirs{};
    std::shared_ptr<Directory> rootDir = std::make_shared<Directory>("/");
    std::shared_ptr<Directory> currDir(rootDir);

    allDirs.emplace_back(rootDir);

    for (std::string line : input) {
        std::vector<std::string> commandVector = Input::splitString(line, ' ');
        if (commandVector[0] == "$" && commandVector[1] == "cd") {
            std::string& folderName{commandVector[2]};
            if (folderName != "/" && folderName != "..") {
                std::shared_ptr childDir = std::make_shared<Directory>(folderName);
                childDir->parentDir = currDir;
                currDir->childDirs.emplace_back(childDir);
                allDirs.emplace_back(childDir);
                currDir = childDir;
            } else if (folderName == "..") {
                currDir = currDir->parentDir;
            }
        } else if (commandVector[0] != "$" && commandVector[0] != "dir") {
            size_t fileSize = stoi(commandVector[0]);
            std::string& fileName = commandVector[1];
            std::shared_ptr<File> newFile = std::make_shared<File>(fileName, fileSize);
            currDir->childFiles.emplace_back(newFile);
        }
    }

    fillDirectorySize(rootDir);
    return allDirs;
}

int part1(std::vector<std::string>& input) {
    std::vector<std::shared_ptr<Directory>> allDirs = parseDirectories(input);

    long sumOfDirs = std::accumulate(allDirs.begin(), allDirs.end(), 0, [](int sum, std::shared_ptr<Directory> dir) {
        return dir->dirSize <= MAX_DIR_SIZE ? sum + dir->dirSize : sum;
    });

    return sumOfDirs;
};

int part2(std::vector<std::string>& input) {
    std::vector<std::shared_ptr<Directory>> allDirs = parseDirectories(input);
    std::shared_ptr<Directory> rootDir = allDirs[0];
    int unusedSpace = TOTAL_SPACE - rootDir->dirSize;
    int sizeToDelete = NEEDED_SPACE - unusedSpace;

    std::sort(allDirs.begin(), allDirs.end(),
              [](const std::shared_ptr<Directory> dir1, const std::shared_ptr<Directory> dir2) {
                  return dir1->dirSize < dir2->dirSize;
              });

    for (auto dir : allDirs) {
        if (dir->dirSize >= sizeToDelete) {
            return dir->dirSize;
        }
    }

    return 0;
}

int main() {
    std::vector<std::string> input = Input::readLinesFromFile(INPUT_FILE);

    int part1_answer = part1(input);
    std::cout << "The answer to part 1 is: " << part1_answer << std::endl;

    int part2_answer = part2(input);
    std::cout << "The answer to part 2 is: " << part2_answer << std::endl;

    return 0;
}
