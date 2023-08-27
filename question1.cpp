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
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <test_case_number>" << endl;
        return 1;
    }

    int testCase = atoi(argv[1]);
    if (testCase != 1) {
        cout << "Invalid test case number. Choose 1." << endl;
        return 1;
    }

    List<int>::dynamicArray dynamicArray;

    ofstream outputFile("scenario1_results.txt");
    outputFile << "Scenario 1: Insertion/Deletion from end" << endl;

    for (int prob = 0; prob <= 100; prob += 10) {
        auto start = high_resolution_clock::now();
        generateRandomTestCases(dynamicArray, prob);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        outputFile << "Probability: " << prob << "%, Time taken: " << duration.count() << " microseconds" << endl;
    }

    outputFile.close();

    return 0;
}
