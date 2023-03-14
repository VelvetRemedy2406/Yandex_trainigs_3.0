#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 10000));

    vector<int> cost;
    cost.resize(n);
    dp[0][0] = 0;
    for (size_t i = 0; i < n; ++i) {
        cin >> cost[i];
    }
    if (n == 1 && cost[0] > 100) {
        cout << cost[0] << endl << "0 0\n";
        return 0;
    }
    for (size_t i = 1; i <= n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            if (cost[i - 1] <= 100) {
                dp[j][i] = min(dp[j + 1][i - 1], dp[j][i - 1] + cost[i - 1]);
            } else {
                if (j > 0) {
                    dp[j][i] = min(dp[j - 1][i - 1] + cost[i - 1], dp[j][i]);
                }
                dp[j][i] = min(dp[j + 1][i - 1], dp[j][i]);

            }
        }
    }
    int res = numeric_limits<int>::max();
    int row;
    for (size_t j = 0; j < n; ++j) {
        if (dp[j][n] <= res) {
            row = j;
            res = dp[j][n];
        }
    }
    if (res != numeric_limits<int>::max()) {
        cout << res << endl;
    } else {
        cout << 0 << endl;
    }

    int i = n;
    vector<int> ans;
    int count_coupouns = 0;
    while (i != 0) {
        if (dp[row + 1][i - 1] == dp[row][i] && (dp[row + 1][i - 1] != 10000)) {
            ans.push_back(i);
            --i;
            ++row;
            count_coupouns++;
        } else if ((row > 0) && (cost[i] + dp[row - 1][i - 1] == dp[row][i])) {
            --i;
            --row;
            count_coupouns++;
        } else {
            --i;
        }

    }
    cout << count_coupouns - ans.size() << " " << ans.size() << endl;
    std::reverse(ans.begin(), ans.end());
    for (auto elem: ans) {
        cout << elem << " ";
    }
    return 0;
}