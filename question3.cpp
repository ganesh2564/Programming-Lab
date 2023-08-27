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
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <test_case_number>" << endl;
        return 1;
    }

    int testCase = atoi(argv[1]);
    if (testCase != 3) {
        cout << "Invalid test case number. Choose 3." << endl;
        return 1;
    }

    List<char>::dynamicArray dynamicArray;

    ofstream outputFile("scenario3_results.txt");
    outputFile << "Scenario 3: Insertion/Deletion from any index" << endl;

    srand(time(nullptr));

    for (int probInsert = 0; probInsert <= 100; probInsert += 10) {
        for (int probIndex = 0; probIndex <= 100; probIndex += 10) {
            auto start = high_resolution_clock::now();
            generateRandomTestCases(dynamicArray, probInsert, probIndex);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(end - start);
            outputFile << "Probability (Insert): " << probInsert << "%, Probability (Index Bias): " << probIndex
                       << "%, Time taken: " << duration.count() << " microseconds" << endl;
        }
    }

    outputFile.close();

    return 0;
}
