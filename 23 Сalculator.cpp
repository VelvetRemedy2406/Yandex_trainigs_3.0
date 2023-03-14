
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> dp;
    int n;
    cin >> n;
    dp.resize(1500000);
    dp[1] = 0;
    for (size_t i = 2; i < 1100000; ++i) {
        dp[i] = dp[i - 1] + 1;
        if (i % 2 == 0) {
            dp[i] = min(dp[i / 2] + 1, dp[i]);
        }
        if (i % 3 == 0) {
            dp[i] = min(dp[i / 3] + 1, dp[i]);
        }
    }
    cout << dp[n] << endl;
    vector<int> res;
    while (n > 1) {
        res.push_back(n);
        if (n % 2 == 0 && dp[n / 2] == dp[n] - 1) {
            n /= 2;
            continue;
        }
        if (n % 3 == 0 && dp[n / 3] == dp[n] - 1) {
            n /= 3;
            continue;
        }
        if (dp[n - 1] == dp[n] - 1) {
            n -= 1;
            continue;
        }
    }
    res.push_back(1);
    reverse(res.begin(), res.end());
    for (int re: res) {
        cout << re << " ";
    }
    return 0;
}