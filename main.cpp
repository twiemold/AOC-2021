#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

const int numberOfDays = 256;

int main() {
    fstream inputFile;
    vector<string> inputs;
    string input;
    vector<long int> lanternfish(9, 0);
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
        lanternfish[val] += 1;
    }

    for (int i = 0; i < numberOfDays; ++i) {
        vector<long int> oldLanternfish(9, 0);
        for (int j = 0; j < lanternfish.size(); ++j) {
            oldLanternfish[j] = lanternfish[j];
        }
        for (int j = 0; j < lanternfish.size(); ++j) {
            if (j == 8) {
                lanternfish[j] = oldLanternfish[0];
            }
            else if (j == 6) {
                lanternfish[j] = oldLanternfish[0];
                lanternfish[j] += oldLanternfish[j+1];
            }
            else {
                lanternfish[j] = oldLanternfish[j+1];
            }
        }
    }

    unsigned long int sum = 0;
    for (auto & fish : lanternfish) {
        sum += fish;
    }


    cout << "There are " + to_string(sum) + " lanternfish after 80 days";

    return 0;
}
