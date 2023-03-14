
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int n;
    int ni;
    set<int> notes;
    cin >> n;
    for (size_t i = 0; i < n; ++i) {
        cin >> ni;
        notes.insert(ni);
    }
    vector<int> stikers;
    stikers.reserve(notes.size()+1);
    stikers.push_back(-1);
    for (auto elem: notes) {
        stikers.push_back(elem);
    }
    int k;
    cin >> k;
    for (size_t i = 0; i < k; ++i) {
        cin >> ni;
        int l = 0;
        int r = stikers.size();
        while (r - l > 1) {
            int m = (r+l)/2;
            if(stikers[m] < ni)
            {
                l = m;
            }
            else
            {
                r = m;
            }
        }
        cout << l << endl;
    }
    return 0;
}