#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

vector<string> iterateByBit(vector<string> &list, int bitPosition, int leastMost);

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

    vector<string> oxygenVec;
    vector<string> carbonVec;

    oxygenVec = iterateByBit(inputs, 0, 1);
    int i = 1;
    while (oxygenVec.size() != 1) {
        oxygenVec = iterateByBit(oxygenVec, i, 1);
        ++i;
    }
    carbonVec = iterateByBit(inputs, 0, 0);
    i = 1;
    while (carbonVec.size() != 1) {
        carbonVec = iterateByBit(carbonVec, i, 0);
        ++i;
    }


    cout << "The oxygen rate is " + oxygenVec[0] << endl;
    cout << "The CO2 rate is " + carbonVec[0] << endl;

    return 0;
}

vector<string> iterateByBit(vector<string> &list, int bitPosition, int leastMost) {
    int zeroBits = 0;
    int oneBits = 0;
    vector<string> zeroPosition;
    vector<string> onePosition;
    for (int i = 0; i < list.size(); ++i) {
        int val = stoi(list[i].substr(bitPosition,1));
        if (val == 1) {
            ++oneBits;
            onePosition.push_back(list[i]);
        } else {
            ++zeroBits;
            zeroPosition.push_back(list[i]);
        }
    }
    if (leastMost == 1) {
        if (oneBits > zeroBits || oneBits == zeroBits) {
            return onePosition;
        } else {
            return zeroPosition;
        }
    } else {
        if (oneBits > zeroBits || oneBits == zeroBits) {
            return zeroPosition;
        } else {
            return onePosition;
        }
    }

}
