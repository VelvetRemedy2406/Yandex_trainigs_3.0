
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> heap;
    int n, num;
    cin >> n;
    auto cmp = std::greater<int>();
    for (size_t i = 0; i < n; ++i) {
        cin >> num;
        heap.push_back(num);
        push_heap(heap.begin(), heap.end(), cmp);
    }
    for (size_t i = 0; i < n; ++i) {
        pop_heap(heap.begin(), heap.end(), cmp);
        cout << heap.back() << " ";
        heap.pop_back();
    }
    return 0;
}