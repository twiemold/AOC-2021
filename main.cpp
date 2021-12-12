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
    int finalScore = 0;
    int finalDrawNumber = -1;
    int winningBoard = -1;
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
    int boards[numberOfBoards][5][5];

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

    for (int i = 0; i < drawNumbers.size(); ++i) {
        int drawNumber = drawNumbers[i];
        // Mark boards
        for (int q = 0; q < numberOfBoards; ++q) {
            for (int j = 0; j < 5; ++j) {
                for (int k = 0; k < 5; ++k) {
                    if (boards[q][j][k] == drawNumber) {
                        boards[q][j][k] = -1;
                    }
                }
            }
        }


        // Check boards
        for (int q = 0; q < numberOfBoards; ++q) {
            for (int j = 0; j < 5; ++j) {
                int rowSum = 0;
                int columnSum = 0;
                for (int k = 0; k < 5; ++k) {
                    rowSum += boards[q][j][k];
                    columnSum += boards[q][k][j];
                }
                if (rowSum == -5 || columnSum == -5) {
                    // Bingo !
                    winningBoard = q;
                    finalDrawNumber = drawNumber;
                    break;
                }
            }
            if (winningBoard != -1) {
                break;
            }
        }
        if (winningBoard != -1) {
            break;
        }
    }

    int unmarkedTotal = 0;
    for (int j = 0; j < 5; ++j) {
        for (int k = 0; k < 5; ++k) {
            if (boards[winningBoard][k][j] != -1) {
                unmarkedTotal += boards[winningBoard][k][j];
            }
        }
    }
    finalScore = unmarkedTotal * finalDrawNumber;

    cout << "Final winning score is " + to_string(finalScore);

    return 0;
}
