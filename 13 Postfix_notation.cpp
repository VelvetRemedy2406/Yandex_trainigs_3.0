
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<long long> stek;
    string token;
    while (cin >> token) {
        if (token == "-") {
            long long right = stek.back();
            stek.pop_back();
            long long left = stek.back();
            stek.pop_back();
            stek.push_back(left - right);
        } else if (token == "+") {
            long long right = stek.back();
            stek.pop_back();
            long long left = stek.back();
            stek.pop_back();
            stek.push_back(left + right);
        } else if (token == "*") {
            long long right = stek.back();
            stek.pop_back();
            long long left = stek.back();
            stek.pop_back();
            stek.push_back(left * right);
        } else if (token == "/") {
            long long right = stek.back();
            stek.pop_back();
            long long left = stek.back();
            stek.pop_back();
            stek.push_back(left / right);
        } else {
            stek.push_back(atoi(token.c_str()));
        }
    }
    cout << stek.back();
    return 0;
}