#include "algorithms.h"

void shellSort(std::vector<int>& set) {
    int interval = 0;
    while (interval < (int)set.size() / 3)
        interval = interval * 3 + 1;

    while (interval > 0) {
        for (int outer = interval; outer < (int)set.size(); outer++) {
            int value = set[outer];
            int inner = outer;

            while (inner > interval - 1 && set[inner - interval] >= value) {
                set[inner] = set[inner - interval];
                inner = inner - interval;
            }
            set[inner] = value;
        }

        interval = (interval - 1) / 3;
    }
}

int binarySearch(const std::vector<int>& set, int value) {
    int l = 0;
    int r = (int)set.size() - 1;

    while (l <= r) {
        int m = (l + r) / 2;
        if (value == set[m])
            return m;
        else if (value < set[m])
            r = m - 1;
        else
            l = m + 1;
    }

    return -1;
}