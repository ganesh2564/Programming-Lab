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

int main() {
   
    List<int>::dynamicArray dynamicArray;
    dynamicArray.addArray(1);
    dynamicArray.addArray(2);
    dynamicArray.addArray(3);
    dynamicArray.addArray(4);
    dynamicArray.addArray(5);

    for (int probInsert = 0; probInsert <= 100; probInsert += 10) {
        for (int probStart = 0; probStart <= 100; probStart += 10) {
            auto start = high_resolution_clock::now();
            generateRandomTestCases(dynamicArray, probInsert, probStart);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(end - start);
            cout << "Probability (Insert): " << probInsert << "%, Probability (Start): " << probStart
                       << "%, Time taken: " << duration.count() << " microseconds" << endl;
            dynamicArray.travel();
        }
    }
    return 0;
}
