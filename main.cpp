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
    vector<int> numbers(10, 0);
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

    string space_delimiter = " ";
    vector<string> singleOutputVals{};

    size_t pos = 0;

    for (auto & line : outputValues) {
        line.erase(0, 1);
        line.append(" ");
    }

    for (auto & line : outputValues) {
        while ((pos = line.find(space_delimiter)) != string::npos) {
            singleOutputVals.push_back(line.substr(0, pos));
            line.erase(0, pos + space_delimiter.length());
        }
    }

    for (auto & val : singleOutputVals) {
        if (val.length() == 2) {
            numbers[1] += 1;
        } else if (val.length() == 4) {
            numbers[4] += 1;
        } else if (val.length() == 3) {
            numbers[7] += 1;
        } else if (val.length() == 7) {
            numbers[8] += 1;
        }
    }

    int sum = 0;
    for (auto & val : numbers) {
        sum += val;
    }

    cout << "There are " + to_string(sum) + " 1s, 4s, 7s, and 8s";

    return 0;
}
