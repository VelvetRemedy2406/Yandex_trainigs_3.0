
#include <iostream>
#include <map>

using namespace std;

int main() {
    map<char, long long> letters_res;
    string str;
    cin >> str;
    for (size_t i = 0; i < str.size(); ++i) {
        letters_res[str[i]] += (i + 1) * (str.size() - i);
    }
    for (auto &it: letters_res) {
        cout << it.first << ": " << it.second << endl;
    }
}