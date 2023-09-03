#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <fstream>
#include "list.h"

using namespace std;
using namespace std::chrono;

void generateRandomTestCases(List<int>::dynamicArray& dynamicArray, int probInsert, int probStart) {
    int numInsertions = (dynamicArray.cnt * probInsert) / 100;
    for (int i = 0; i < numInsertions; ++i) {
        dynamicArray.addArrayToFront(i);
    }

    int numDeletions = (dynamicArray.cnt * probStart) / 100;
    for (int i = 0; i < numDeletions; ++i) {
        dynamicArray.deleteArray(0);
    }

    for (int i = 0; i < numInsertions; ++i) {
        dynamicArray.deleteArray(dynamicArray.cnt - 1);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <probability_insert> <probability_start>" << endl;
        return 1;
    }

    int probInsert = atoi(argv[1]);
    int probStart = atoi(argv[2]);

    List<int>::dynamicArray dynamicArray;

    auto start = high_resolution_clock::now();
    generateRandomTestCases(dynamicArray, probInsert, probStart);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Probability (Insert): " << probInsert << "%, Probability (Start): " << probStart
               << "%, Time taken: " << duration.count() << " microseconds" << endl;
    dynamicArray.arrayTravel();

    return 0;
}
