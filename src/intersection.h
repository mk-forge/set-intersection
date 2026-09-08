#ifndef INTERSECTION_H
#define INTERSECTION_H
#pragma once

#include <vector>

/**
 * @file intersection.h
 * 
 * @brief Header file containing set intersection function prototype
 */

/**
 * @brief Compute the intersection of two sets
 *
 * Builds the intersection of two sets represented as vectors
 *
 * @param setA First set
 * @param setB Second set
 * 
 * @return Vector representing the intersection of the two sets
 */
std::vector<int> setIntersection(std::vector<int>& setA, std::vector<int>& setB);

#endif