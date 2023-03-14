
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k, num;
    cin >> n >> m >> k;
    vector<int> new_row;
    new_row.reserve(m + 1);
    vector<vector<int>> get_sum(1, vector<int>(m + 1, 0));
    for (size_t i = 0; i < n; ++i) {

        new_row.push_back(0);
        for (size_t j = 0; j < m; ++j) {
            cin >> num;
            new_row.push_back(new_row[j] + num + get_sum[i][j + 1] - get_sum[i][j]);
        }

        get_sum.push_back(new_row);
        new_row.clear();
    }
    int x1, y1, x2, y2;
    for (size_t i = 0; i < k; ++i) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << get_sum[x2][y2] - get_sum[x2][y1 - 1] - get_sum[x1 - 1][y2] + get_sum[x1 - 1][y1 - 1] << endl;
    }
    return 0;
}