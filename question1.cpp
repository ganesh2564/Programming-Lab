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

    // Insert 100 elements at a time
    for (int i = 0; i < numInsertions; ++i) {
        for (int j = 0; j < 100; ++j) {
            dynamicArray.addArray(i);
        }
    }

    // Delete 100 elements at a time
    for (int i = 0; i < numInsertions; ++i) {
        for (int j = 0; j < 100; ++j) {
            dynamicArray.deleteArray(dynamicArray.cnt - 1);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <num_iterations> <probability>" << endl;
        return 1;
    }

    int numIterations = atoi(argv[1]);
    int probability = atoi(argv[2]);

    List<int>::dynamicArray dynamicArray;
    for (int iteration = 0; iteration < numIterations; ++iteration) {
        auto start = high_resolution_clock::now();
        generateRandomTestCases(dynamicArray, probability);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        cout << "Probability: " << probability << "%, Time taken: " << duration.count() << " microseconds" << endl;
    }
    return 0;
}
