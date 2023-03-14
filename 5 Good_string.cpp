
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<long long> letters;
    vector<long long> sorted_letters;
    long long n;
    cin >> n;
    letters.resize(n);
    for (size_t i = 0; i < n; ++i) {
        cin >> letters[i];
    }
    sorted_letters = letters;
    sort(sorted_letters.begin(), sorted_letters.end());
    long long last_level = 0;
    long long curr_level = 0;
    long long res = 0;
    for (size_t i = 0; i < n - 1; ++i) {
        curr_level = sorted_letters[i];
        for (size_t j = 0; j < n - 1; ++j) {
            if (curr_level <= letters[j] && curr_level <= letters[j + 1]) {
                res += curr_level - last_level;
            }
        }
        last_level = curr_level;
    }
    cout << res;
    return 0;
}