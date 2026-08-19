#ifndef FILE_IO_H
#define FILE_IO_H
#pragma once

#include <vector>
#include <fstream>
#include <string>

/**
 * @file file_io.h
 * 
 * @brief Header file containing function prototypes for file operations
 */

/**
 * @brief Load a set from a file
 *
 * Reads integer values from a file and stores them in a vector
 *
 * @param path Path to the input file
 * 
 * @return Vector representing the set
 */
std::vector<int> loadFile(const std::string& path);

/**
 * @brief Write the set intersection to a file
 *
 * Writes the resulting intersection of two sets to a file
 *
 * @param intersection Vector representing the intersection of sets
 * @param outputPath Path to the output file
 */
void saveToFile(const std::vector<int>& intersection, const std::string& outputPath);

#endif