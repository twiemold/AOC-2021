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
    int numberOfOverlaps = 0;
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

    // Create map
    for (int i = 0; i < coordinates.size(); i += 2) {
        int x1 = coordinates[i][0];
        int x2 = coordinates[i+1][0];
        int y1 = coordinates[i][1];
        int y2 = coordinates[i+1][1];
        if (y1 == y2) {
            int xRange = abs(x1 - x2);
            int startX = -1;
            if (x1 > x2) {
                startX = x2;
            } else {
                startX = x1;
            }
            for (int k = 0; k < xRange + 1; ++k) {
                int xVal = startX + k;
                board[xVal][y1] += 1;
            }
        } else if (x1 == x2) {
            int yRange = abs(y1 - y2);
            int startY = -1;
            if (y1 > y2) {
                startY = y2;
            } else {
                startY = y1;
            }
            for (int k = 0; k < yRange + 1; ++k) {
                int yVal = startY + k;
                board[x1][yVal] += 1;
            }
        } else {
            continue;
        }
    }

    for (int i = 0; i < 1000; ++i) {
        for (int j = 0; j < 1000; ++j) {
            if (board[i][j] >= 2) {
                ++numberOfOverlaps;
            }
        }
    }

    cout << "There are " + to_string(numberOfOverlaps) + " places with two overlaps";



    return 0;
}
