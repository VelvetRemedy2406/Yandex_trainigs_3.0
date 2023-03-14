
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<long long> dp;
    int n;
    cin >> n;
    dp.resize(n + 3);
    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 4;
    for (size_t i = 3; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    cout << dp[n] << endl;
    return 0;
}