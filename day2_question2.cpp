#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <fstream>
#include <sstream>
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
    if (argc != 4) {
        cerr << "Usage: " << argv[0] << " <num_iterations> <probability> <output_filename>" << endl;
        return 1;
    }

    int numIterations = atoi(argv[1]);
    int probability = atoi(argv[2]);
    string outputFilename = argv[3];

    List<int>::dynamicArray dynamicArray;
    long long totalExecutionTime = 0;

    ofstream outputFile(outputFilename);

    for (int iteration = 0; iteration < numIterations; ++iteration) {
        auto start = high_resolution_clock::now();

        // Execute /usr/bin/time and redirect the output to a temporary file
        string command = "/usr/bin/time -o temp_time.txt -f \"%e %M\" ./your_program_name " + to_string(probability);
        system(command.c_str());

        // Open and read the temporary time file
        ifstream timeFile("temp_time.txt");
        double executionTime, memoryUsage;
        timeFile >> executionTime >> memoryUsage;
        timeFile.close();
        remove("temp_time.txt");

        totalExecutionTime += static_cast<long long>(executionTime * 1e6); // Convert to microseconds

        // Store execution time and memory usage in the output file
        outputFile << probability << " " << executionTime << " " << memoryUsage << endl;
    }

    double averageExecutionTime = static_cast<double>(totalExecutionTime) / numIterations;
    outputFile << "Average Execution Time: " << averageExecutionTime << " microseconds" << endl;
    outputFile.close();

    return 0;
}
