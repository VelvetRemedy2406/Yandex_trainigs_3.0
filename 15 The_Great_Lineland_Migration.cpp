
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<pair<long long, long long>> stek;
    long long n, num;
    cin >> n;
    vector<long long> res(n, -1);
    for (size_t i = 0; i < n; ++i) {
        cin >> num;
        if (stek.empty() || stek.back().first <= num) {
            stek.emplace_back(num, i);
        } else {
            while ((!stek.empty()) && stek.back().first > num) {
                res[stek.back().second] = i;
                stek.pop_back();
            }
            stek.emplace_back(num, i);
        }
    }
    for (auto elem: res) {
        cout << elem << " ";
    }
    return 0;
}