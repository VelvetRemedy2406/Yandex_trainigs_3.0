
#include <iostream>
#include <set>

using namespace std;

bool has_intersection(const pair<int, int> &left, const pair<int, int> &right) {
    if (left.first > right.second || right.first > left.second) {
        return false;
    }
    return true;
}

int main() {
    int m, n, a, b;
    cin >> m >> n;
    set<pair<int, int>> segments;
    for (size_t i = 0; i < n; ++i) {
        cin >> a >> b;
        auto it = segments.begin();
        while (it != segments.end()) {
            if (has_intersection(*it, {a, b})) {
                auto tmp = it;
                tmp++;
                segments.erase(it);
                it = tmp;
            } else {
                ++it;
            }
        }
        segments.insert({a, b});
    }
    cout << segments.size();
    return 0;
}