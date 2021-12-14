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
    vector<vector<int>> coordinates;
    string input;
    inputFile.open("../input.txt");
    if (inputFile.is_open()) {
        while (inputFile >> input) {
            inputs.push_back(input);
        }
    }
    inputFile.close();

    // Create blank board
    int board[1000][1000];
    for (int i = 0; i < 1000; ++i) {
        for (int j = 0; j < 1000; ++j) {
            board[i][j] = 0;
        }
    }

    // Extract values from input
    for (int i = 0; i < inputs.size(); ++i) {
        if (inputs[i].substr() != "->") {
            stringstream myStream(inputs[i].substr());
            vector<int> v1;
            while (myStream.good()) {
                string substr;
                getline(myStream, substr, ',');
                int val = stoi(substr);
                v1.push_back(val);
            }
            coordinates.push_back(v1);
        }
    }


    return 0;
}
