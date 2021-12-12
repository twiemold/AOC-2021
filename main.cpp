#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main() {
    fstream inputFile;
    int forward = 0;
    int depth = 0;
    vector<string> inputs;
    vector<int> values;
    string input;
    inputFile.open("../input.txt");
    if (inputFile.is_open()) {
        while (inputFile >> input) {
            inputs.push_back(input);
        }
    }

    for (int i = 1; i < inputs.size(); i+=2) {
        values.push_back(stoi(inputs[i]));
    }

    for (int i = 0; i < inputs.size(); i += 2) {
        if (inputs[i] == "up") {
            depth -= values[i];
        } else if (inputs[i] == "down") {
            depth += values[i];
        } else {
            forward += values[i];
        }
    }

    return 0;
}
