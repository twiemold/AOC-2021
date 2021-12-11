#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main() {
    int depth;
    vector<int> depths;
    fstream numbersFile;
    numbersFile.open("input.txt");
    if (numbersFile.is_open()) {
        while (numbersFile >> depth) {
            depths.push_back(depth);
        }
    }
    numbersFile.close();
}
