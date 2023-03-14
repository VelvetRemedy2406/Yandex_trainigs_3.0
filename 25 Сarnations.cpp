#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, num;
    vector<int> vec;
    vec.reserve(n);
    cin >> n;
    for (size_t i = 0; i < n; ++i) {
        cin >> num;
        vec.push_back(num);
    }
    sort(vec.begin(), vec.end());
    vector<int> dp;
    dp.resize(n + 1, 1000000);

    dp[1] = vec[1] - vec[0];
    for (size_t i = 2; i < n; ++i) {
        dp[i] = min(dp[i - 2], dp[i - 1]) + vec[i] - vec[i - 1];
    }
    cout << dp[n - 1];
    return 0;
}