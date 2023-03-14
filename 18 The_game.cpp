#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    queue<int> player1;
    queue<int> player2;
    int num;
    for (size_t i = 0; i < 5; ++i) {
        cin >> num;
        player1.push(num);
    }
    for (size_t i = 0; i < 5; ++i) {
        cin >> num;
        player2.push(num);
    }
    for (size_t i = 0; i < 1000000; ++i) {
        if (player1.empty()) {
            cout << "second " << i << endl;
            return 0;
        }
        if (player2.empty()) {
            cout << "first " << i << endl;
            return 0;
        }
        int p1 = player1.front();
        player1.pop();
        int p2 = player2.front();
        player2.pop();
        if (p1 == 0 && p2 == 9) {
            player1.push(p1);
            player1.push(p2);
        } else if (p1 == 9 && p2 == 0) {
            player2.push(p1);
            player2.push(p2);
        } else if (p1 > p2) {
            player1.push(p1);
            player1.push(p2);
        } else {
            player2.push(p1);
            player2.push(p2);
        }
    }
    cout << "botva" << endl;
    return 0;
}