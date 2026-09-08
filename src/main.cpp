#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include "file_io.h"
#include "algorithms.h"
#include "intersection.h"

/**
 * @file main.cpp
 * 
 * @brief Main program file containing timing and execution logic
 */

/**
 * @brief Measure execution time
 *
 * Measures the time required to compute the set intersection
 *
 * @param fileA Path to the first input file
 * @param fileB Path to the second input file
 * @param outputFile Path to the output file
 */
void measureTime(const std::string& fileA, const std::string& fileB, const std::string& outputFile) {
    std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
    std::vector<int> setA = loadFile(fileA);
    std::vector<int> setB = loadFile(fileB);

    shellSort(setA);
    shellSort(setB);

    std::vector<int> intersection = setIntersection(setA, setB);

    saveToFile(intersection, outputFile);

    std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();
    std::chrono::milliseconds duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Execution time: " << duration.count() << " ms" << std::endl;
}

/**
 * @brief Print usage information
 */
void printUsage() {
    std::cout << "Usage: set_intersection.exe [input1] [input2] [output]\n"
                 "  input1  - path to the first set file\n"
                 "  input2  - path to the second set file\n"
                 "  output  - path to the output file\n"
                 "\n"
                 "If no arguments are provided, default files are used:\n"
                 "  input1: data/SmallSetA.txt\n"
                 "  input2: data/SmallSetB.txt\n"
                 "  output: intersection.txt\n";
}

int main(int argc, char* argv[]) {
    std::string fileA, fileB, outputFile;

    if (argc == 2 && std::string(argv[1]) == "--help") {
        printUsage();
        return 0;
    }

    if (argc == 4) {
        fileA = argv[1];
        fileB = argv[2];
        outputFile = argv[3];
    } else {
        std::cout << "Using default files: data/SmallSetA.txt, data/SmallSetB.txt, intersection.txt\n";
        std::cout << "Use --help for usage information.\n";
        fileA = "data/SmallSetA.txt";
        fileB = "data/SmallSetB.txt";
        outputFile = "intersection.txt";
    }

    measureTime(fileA, fileB, outputFile);
    return 0;
}