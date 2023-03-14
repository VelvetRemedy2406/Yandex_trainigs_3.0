
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<char> stek;
    string str;
    cin >> str;
    for (auto elem: str) {
        if (elem == '(') {
            stek.push_back(elem);
        }
        if (elem == '{') {
            stek.push_back(elem);
        }
        if (elem == '[') {
            stek.push_back(elem);
        }
        if (elem == ')') {
            if (stek.empty() || stek.back() != '(') {
                cout << "no";
                return 0;
            }
            stek.pop_back();
        }
        if (elem == ']') {
            if (stek.empty() || stek.back() != '[') {
                cout << "no";
                return 0;
            }
            stek.pop_back();
        }
        if (elem == '}') {
            if (stek.empty() || stek.back() != '{') {
                cout << "no";
                return 0;
            }
            stek.pop_back();
        }
    }
    if(!stek.empty())
    {
        cout << "no";
        return 0;
    }
    cout << "yes";
    return 0;
}