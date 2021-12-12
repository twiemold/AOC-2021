#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main() {
    fstream inputFile;
    vector<string> inputs;
    string input;
    string gammaRate;
    string epsilonRate;
    inputFile.open("../input.txt");
    if (inputFile.is_open()) {
        while (inputFile >> input) {
            inputs.push_back(input);
        }
    }

    for (int i = 0; i < input.size(); ++i) {
        int zeroBits = 0;
        int oneBits = 0;
        for (int j = 0; j < inputs.size(); ++j) {
            int val = stoi(inputs[j].substr(i,1));
            if (val == 1) {
                ++oneBits;
            } else {
                ++zeroBits;
            }
        }
        if (oneBits > zeroBits) {
            gammaRate.append("1");
            epsilonRate.append("0");
        } else {
            epsilonRate.append("1");
            gammaRate.append("0");
        }
    }

    cout << "The gamma rate is " + gammaRate << endl;
    cout << "The epsilon rate is " + epsilonRate << endl;

    return 0;
}
