
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> table(n, vector<int>(m));
    vector<vector<int>> dp(n, vector<int>(m, 10000));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            cin >> table[i][j];
        }
    }
    dp[0][0] = table[0][0];
    for (size_t i = 1; i < n; ++i) {
        dp[i][0] = dp[i - 1][0] + table[i][0];
    }
    for (size_t i = 1; i < m; ++i) {
        dp[0][i] = dp[0][i - 1] + table[0][i];
    }
    for (size_t i = 1; i < n; ++i) {
        for (size_t j = 1; j < m; ++j) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + table[i][j];
        }
    }
    cout << dp[n - 1][m - 1];
    return 0;
}