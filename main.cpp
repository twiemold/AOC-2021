#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int main() {
    fstream inputFile;
    string input;
    vector<string> signalPatterns;
    vector<string> outputValues;
    inputFile.open("../input.txt");
    if (inputFile.is_open()) {
        while (inputFile >> input) {
            getline(inputFile, input, '|');
            signalPatterns.push_back(input);
            getline(inputFile, input);
            outputValues.push_back(input);
        }
    }
    inputFile.close();

    for (auto & outputVal : outputValues) {
        string checkVal;
        outputVal >> checkVal;
    }
    return 0;
}
