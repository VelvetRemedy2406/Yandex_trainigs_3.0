#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    vector<int> first;
    vector<int> second;
    cin >> n;
    first.resize(n);
    for (size_t i = 0; i < n; ++i) {
        cin >> first[i];
    }
    cin >> m;
    second.resize(m);
    for (size_t i = 0; i < m; ++i) {
        cin >> second[i];
    }
    vector<vector<int>> dp(n, vector<int>(m, -1));
    if (first[0] == second[0]) {
        dp[0][0] = 1;
    } else {
        dp[0][0] = 0;
    }
    for (size_t i = 1; i < n; ++i) {
        if (second[0] == first[i]) {
            dp[i][0] = 1;
        } else {
            dp[i][0] = dp[i - 1][0];
        }
    }
    for (size_t i = 1; i < m; ++i) {
        if (second[i] == first[0]) {
            dp[0][i] = 1;
        } else {
            dp[0][i] = dp[0][i - 1];
        }
    }
    for (size_t i = 1; i < n; ++i) {
        for (size_t j = 1; j < m; ++j) {
            if (first[i] == second[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

    }
    int i = n - 1;
    int j = m - 1;
    vector<int> ans;
    while (dp[i][j] != 0) {
        if (i > 0 && j > 0) {
            if (dp[i][j] == (dp[i - 1][j - 1] + 1) && first[i] == second[j]) {
                ans.push_back(first[i]);
                i--;
                j--;
            } else if (dp[i - 1][j] == dp[i][j]) {
                i--;
            } else {
                j--;
            }
        } else if (i > 0) {
            if (dp[i][j] == (dp[i - 1][j] + 1) && first[i] == second[j]) {
                ans.push_back(first[i]);
            }
            i--;
        } else {
            if (dp[i][j] == (dp[i][j - 1] + 1) && first[i] == second[j]) {
                ans.push_back(first[i]);
            }
            j--;
        }
    }
    std::reverse(ans.begin(), ans.end());
    for (auto path: ans) {
        cout << path << " ";
    }
    return 0;
}