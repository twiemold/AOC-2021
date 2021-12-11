#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main() {
    int depth = 0;
    int numGreaterThan = 0;
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

    for (int i = 1; i < depths.size(); ++i) {
        if (depths[i] > depths[i-1]) {
            ++numGreaterThan;
        }
    }

    cout << "There are " + to_string(numGreaterThan) + " readings greater than the previous";
}
