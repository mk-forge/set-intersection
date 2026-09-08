#include <iostream>
#include <vector>
#include <cassert>
#include "algorithms.h"
#include "file_io.h"
#include "intersection.h"

void testShellSort() {
    std::vector<int> test = {5, 2, 8, 1, 9};
    shellSort(test);
    assert(test[0] == 1);
    assert(test[1] == 2);
    assert(test[2] == 5);
    assert(test[3] == 8);
    assert(test[4] == 9);
    std::cout << "ShellSort test passed." << std::endl;
}

void testBinarySearch() {
    std::vector<int> sorted = {1, 2, 5, 8, 9};
    assert(binarySearch(sorted, 5) == 2);
    assert(binarySearch(sorted, 9) == 4);
    assert(binarySearch(sorted, 99) == -1);
    std::cout << "BinarySearch test passed." << std::endl;
}

void testSetIntersection() {
    std::vector<int> A = {1, 2, 3, 4, 5};
    std::vector<int> B = {3, 4, 5, 6, 7};
    
    shellSort(A);
    shellSort(B);
    
    std::vector<int> result = setIntersection(A, B);
    assert(result.size() == 3);
    assert(result[0] == 3);
    assert(result[1] == 4);
    assert(result[2] == 5);
    std::cout << "SetIntersection test passed." << std::endl;
}

int main() {
    testShellSort();
    testBinarySearch();
    testSetIntersection();
    std::cout << "All tests passed." << std::endl;
    return 0;
}