#include <iostream>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int main() {
    fstream inputFile;
    vector<string> inputs;
    string input;
    vector<int> lanternfish;
    inputFile.open("../input.txt");
    if (inputFile.is_open()) {
        while (inputFile >> input) {
            inputs.push_back(input);
        }
    }
    inputFile.close();

    stringstream myStream(inputs[0].substr());
    while (myStream.good()) {
        string substr;
        getline(myStream, substr, ',');
        int val = stoi(substr);
        lanternfish.push_back(val);
    }

    for (int &i : lanternfish) {
        cout << i << endl;
    }
    return 0;
}
