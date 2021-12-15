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

    for (int i = 0; i < 80; ++i) {
        int newLanternfish = 0;
        for (int & fish : lanternfish) {
            if (fish == 0) {
                ++newLanternfish;
                fish = 6;
            } else {
                --fish;
            }
        }
        for (int j = 0; j < newLanternfish; ++j) {
            lanternfish.push_back(8);
        }
    }

    cout << "There are " + to_string(lanternfish.size()) + " lanternfish after 80 days";

    return 0;
}
