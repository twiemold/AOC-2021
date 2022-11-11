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
        while (x1 != x2 || y1 != y2) {
            board[x1][y1] += 1;
            if (x1 > x2) {
                --x1;
            } else if (x2 > x1) {
                ++x1;
            }
            if (y1 > y2) {
                --y1;
            } else if (y2 > y1) {
                ++y1;
            }
        }
        // Fix off by one error, sloppy
        board[x1][y1] += 1;
    }

    for (int i = 0; i < 1000; ++i) {
        for (int j = 0; j < 1000; ++j) {
            if (board[i][j] >= 2) {
                ++numberOfOverlaps;
            }
        }
    }

    cout << "There are " + to_string(numberOfOverlaps) + " places with two or more overlaps";



    return 0;
}
