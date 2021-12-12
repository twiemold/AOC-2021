#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main() {
    fstream inputFile;
    vector<string> inputs;
    string input;
    inputFile.open("../input.txt");
    if (inputFile.is_open()) {
        while (inputFile >> input) {
            inputs.push_back(input);
        }
    }

    for (string &i : inputs) {
        cout << i << endl;
    }

    return 0;
}
