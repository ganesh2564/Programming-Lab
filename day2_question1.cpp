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

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <num_iterations> <probability>" << endl;
        return 1;
    }

    int numIterations = atoi(argv[1]);
    int probability = atoi(argv[2]);

    List<int>::dynamicArray dynamicArray;
    long long totalExecutionTime = 0;

    for (int iteration = 0; iteration < numIterations; ++iteration) {
        auto start = high_resolution_clock::now();
        generateRandomTestCases(dynamicArray, probability);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        totalExecutionTime += duration.count();
    }

    double averageExecutionTime = static_cast<double>(totalExecutionTime) / numIterations;
    cout << "Average Execution Time: " << averageExecutionTime << " microseconds" << endl;

    return 0;
}





