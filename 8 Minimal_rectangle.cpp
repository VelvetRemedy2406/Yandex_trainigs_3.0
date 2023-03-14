
#include <iostream>

using namespace std;


int main() {
    int k;
    cin >> k;
    int x_curr, y_curr;
    int x1, y1, x2, y2;
    cin >> x1 >> y1;
    x2 = x1;
    y2 = y1;
    for (size_t i = 0; i < k - 1; ++i) {
        cin >> x_curr >> y_curr;
        x1 = min(x1, x_curr);
        x2 = max(x2, x_curr);
        y1 = min(y1, y_curr);
        y2 = max(y2, y_curr);
    }
    cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    return 0;
}