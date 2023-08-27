#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <fstream>
#include "list.h"

using namespace std;
using namespace std::chrono;

void generateRandomTestCases(List<int>::dynamicArray& dynamicArray, int prob) {
    int numInsertions = (dynamicArray.cnt * prob) / 100;
    for (int i = 0; i < numInsertions; ++i) {
        dynamicArray.addArray(i);
    }

    for (int i = 0; i < numInsertions; ++i) {
        dynamicArray.deleteArray(dynamicArray.cnt - 1);
    }
}

int main() {
    List<int>::dynamicArray dynamicArray;
    for (int prob = 0; prob <= 100; prob += 10) {
        auto start = high_resolution_clock::now();
        generateRandomTestCases(dynamicArray, prob);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        cout << "Probability: " << prob << "%, Time taken: " << duration.count() << " microseconds" << endl;
    }
    return 0;
}
