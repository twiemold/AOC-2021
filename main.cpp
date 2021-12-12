#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int main() {
    fstream inputFile;
    vector<string> inputs;
    vector<int> drawNumbers;
    string input;
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
        drawNumbers.push_back(val);
    }

    const int numberOfBoards = (inputs.size() - 1) / 25;
    // Cheating
    int boards[100][5][5];
    int markedBoards[100][5][5];

    int l = 1;
    for (int i = 0; i < numberOfBoards; ++i) {
        for (int j = 0; j < 5; ++j) {
            for (int k = 0; k < 5; ++k) {
                int val = stoi(inputs[l]);
                boards[i][j][k] = val;
                ++l;
            }
        }
    }



    for (int& i : drawNumbers) {
        cout << i << endl;
    }

    cout << inputs.size();
    return 0;
}
