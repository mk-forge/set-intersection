#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#pragma once

#include <vector>

/**
 * @file algorithms.h
 * 
 * @brief Header file containing function prototypes for set operations
 */

/**
 * @brief Shell Sort algorithm
 *
 * Sorts a vector using the Shell Sort algorithm.
 * Pseudocode source: https://www.tutorialspoint.com/data_structures_algorithms/shell_sort_algorithm.htm
 *
 * @param set Unsorted vector to be sorted
 */
void shellSort(std::vector<int>& set);

/**
 * @brief Binary Search algorithm
 *
 * Searches for a value in a sorted vector using Binary Search.
 * Pseudocode source: Introduction to The Design and Analysis of Algorithms - Anany Levitin
 *
 * @param set Sorted vector to search in
 * @param value Value to search for
 * 
 * @return Index of the value if found, otherwise -1
 */
int binarySearch(const std::vector<int>& set, int value);

#endif