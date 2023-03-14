#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

inline bool is_correct(int x, int y, int n, int m) {
    if (x < 0 || x > n) {
        return false;
    }
    else if(y < 0 || y > m)
    {
        return false;
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    char word[1500][1500];
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            cin >> word[i][j];
        }
    }
    vector<vector<int>> grap(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (word[i][j] == '.') {
                int x = i-1;
                int y = j;
                while (is_correct(x,y,n,m))
                {
                    grap[i].push_back()
                }
            }
        }
    }

    return 0;
}