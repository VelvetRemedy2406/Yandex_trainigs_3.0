
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> dfs(vector<vector<int>> &graph, int n, int start, vector<int> &used) {
    static int num = 1;
    vector<int> stek;
    stek.push_back(start);
    if (graph[start].empty()) {
        num++;
        return {start};
    }
    while (!stek.empty()) {
        int curr = stek.back();
        stek.pop_back();
        if (!used[curr]) {
            used[curr] = num;
            for (auto ver: graph[curr]) {
                stek.push_back(ver);
            }
        }
    }
    vector<int> res;
    for (size_t i = 1; i < n + 1; ++i) {
        if (used[i] == num) {
            res.push_back(i);
        }
    }
    num++;
    return res;

}

int main() {
    int n, m, ver1, ver2;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    for (size_t i = 0; i < m; ++i) {
        cin >> ver1 >> ver2;
        graph[ver1].push_back(ver2);
        graph[ver2].push_back(ver1);
    }
    vector<int> used(n + 1, 0);
    vector<vector<int>> ans;
    for (size_t i = 1; i < n + 1; ++i) {
        if (!used[i]) {
            ans.push_back(dfs(graph, n, i, used));
        }
    }
    cout << ans.size() << endl;
    for (auto &vec: ans) {
        cout << vec.size() << endl;
        for (auto elem: vec) {
            cout << elem << " ";
        }
        cout << endl;
    }
    return 0;
}