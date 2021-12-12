#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main() {
    int depth = 0;
    int numGreaterThan = 0;
    double numberOfDivisions;
    vector<int> depths;
    ifstream numbersFile;

    numbersFile.open("../input.txt");
    if (numbersFile.is_open()) {
        while (numbersFile >> depth) {
            depths.push_back(depth);
        }

        cout << "Read in ";
        cout << depths.size();
        cout << " numbers" << endl;

        numbersFile.close();
    }

    for (int i = 2; i < depths.size(); ++i) {
        int previousSum = depths[i-2] + depths[i-1] + depths[i];
        int currentSum = depths[i-1] + depths[i] + depths[i+1];
        if (currentSum > previousSum) {
            ++numGreaterThan;
        }
    }

    cout << "There are " + to_string(numGreaterThan) + " readings greater than the previous";
}
