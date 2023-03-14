#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a, b, c;
    vector<int> dp;
    dp.resize(n);
    a.resize(n);
    b.resize(n);
    c.resize(n);
    for (size_t i = 0; i < n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
    }
    dp[0] = a[0];
    if (n == 1) {
        cout << dp[0];
        return 0;
    }
    dp[1] = min(a[0] + a[1], b[0]);
    if (n == 2) {
        cout << dp[1];
        return 0;
    }
    dp[2] = min(a[0] + a[1] + a[2], min(a[0] + b[1], min(c[0], b[0] + a[2])));
    if (n == 3) {
        cout << dp[2];
        return 0;
    }
    for (size_t i = 3; i < n; ++i) {
        dp[i] = min(dp[i - 1] + a[i], min(dp[i - 2] + b[i - 1], dp[i - 3] + c[i - 2]));
    }
    cout << dp[n - 1];
    return 0;
}