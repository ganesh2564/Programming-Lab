#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <fstream>
#include "list.h"

using namespace std;
using namespace std::chrono;

void generateRandomTestCases(List<char>::dynamicArray& dynamicArray, int probInsert, int probIndex) {
    int numInsertions = (dynamicArray.cnt * probInsert) / 100;
    for (int i = 0; i < numInsertions; ++i) {
        char ch = 'A' + (rand() % 26);
        int index = 0;

        int randNum = rand() % 100;
        if (randNum < probIndex) {
            index = 0;
        } else if (randNum < 2 * probIndex) {
            index = dynamicArray.cnt - 1;
        } else {
            index = dynamicArray.cnt / 2;
        }

        dynamicArray.addArrayAtIndex(ch, index);
    }

    int numDeletions = (dynamicArray.cnt * probInsert) / 100;
    for (int i = 0; i < numDeletions; ++i) {
        int index = 0;

        int randNum = rand() % 100;
        if (randNum < probIndex) {
            index = 0;
        } else if (randNum < 2 * probIndex) {
            index = dynamicArray.cnt - 1;
        } else {
            index = dynamicArray.cnt / 2;
        }

        dynamicArray.deleteArrayAtIndex(index);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <probability_insert> <probability_index_bias>" << endl;
        return 1;
    }

    int probInsert = atoi(argv[1]);
    int probIndex = atoi(argv[2]);

    List<char>::dynamicArray dynamicArray;
    srand(time(nullptr));

    auto start = high_resolution_clock::now();
    generateRandomTestCases(dynamicArray, probInsert, probIndex);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Probability (Insert): " << probInsert << "%, Probability (Index Bias): " << probIndex
               << "%, Time taken: " << duration.count() << " microseconds" << endl;

    return 0;
}
