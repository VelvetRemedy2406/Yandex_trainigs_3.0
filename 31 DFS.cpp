
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, ver1, ver2;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    for (size_t i = 0; i < m; ++i) {
        cin >> ver1 >> ver2;
        graph[ver1].push_back(ver2);
        graph[ver2].push_back(ver1);
    }
    vector<bool> used(n + 1, false);
    vector<int> stek;
    stek.push_back(1);
    while (!stek.empty()) {
        int curr = stek.back();
        stek.pop_back();
        if (!used[curr]) {
            used[curr] = true;
            for (auto ver: graph[curr]) {
                stek.push_back(ver);
            }
        }
    }
    vector<int> res;
    for (size_t i = 1; i < n + 1; ++i) {
        if (used[i]) {
            res.push_back(i);
        }
    }
    cout << res.size() << endl;
    for (auto elem: res) {
        cout << elem << " ";
    }

    return 0;
}