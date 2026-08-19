#include "file_io.h"
#include <iostream>

std::vector<int> loadFile(const std::string& path) {
    std::fstream file(path);

    if (!file.is_open()) {
        std::cout << "Error opening file: " + path;
        exit(1);
    }

    std::vector<int> vec = {};
    int element;
    while (file >> element) {
        vec.push_back(element);
    }

    file.close();
    return vec;
}

void saveToFile(const std::vector<int>& intersection, const std::string& outputPath) {
    std::fstream output(outputPath, std::ios::out);
    for (size_t i = 0; i < intersection.size(); i++) {
        output << intersection[i] << std::endl;
    }

    output.close();
}