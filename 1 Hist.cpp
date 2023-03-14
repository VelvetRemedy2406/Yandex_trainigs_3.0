
#include <iostream>
#include <fstream>
#include <map>

using namespace std;


int main() {
    fstream fin("input.txt",ios::in);
    map<char, int> dict;
    char c;
    int max_level = 0;
    while (!fin.eof()) {
        fin.get(c);
        if (c != '\n' && c != ' ') {
            dict[c]++;
            max_level = max(max_level, dict[c]);
        }
    }
    int current_level = max_level;
    for (size_t i = 0; i < max_level; ++i) {
        for (auto &it: dict) {
            if (current_level <= it.second) {
                cout << "#";
            } else {
                cout << " ";
            }
        }
        current_level--;
        cout << endl;
    }

    for (auto &it: dict) {
        cout << it.first;
    }

    return 0;
}