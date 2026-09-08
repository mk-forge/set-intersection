#include "intersection.h"
#include "algorithms.h"
#include <cstddef>

std::vector<int> setIntersection(std::vector<int>& setA, std::vector<int>& setB) {
    std::vector<int> intersection = {};
    bool added = false;

    for (size_t i = 0; i < setA.size(); i++) {    
        if (binarySearch(setB, setA[i]) != -1) {
            added = false;
            
            for (size_t j = 0; j < intersection.size(); j++) {
                if (setA[i] == intersection[j]) {
                    added = true;
                    break;
                }
            }

            if (!added)
                intersection.push_back(setA[i]);
        }
    }

    return intersection;
}