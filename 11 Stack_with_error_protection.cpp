
#include <iostream>
#include <vector>

using namespace std;

class stek {
public:
    stek() = default;

    void push(int n) {
        stekk.push_back(n);
        cout << "ok" << endl;
    }

    void clear() {
        stekk.clear();
        cout << "ok" << endl;
    }

    void size() {
        cout << stekk.size() << endl;
    }

    void back() {
        if (stekk.empty()) {
            cout << "error" << endl;
            return;
        }
        cout << stekk.back() << endl;
    }

    void pop() {
        if (stekk.empty()) {
            cout << "error" << endl;
            return;
        }
        cout << stekk.back() << endl;
        stekk.pop_back();
    }

private:
    vector<int> stekk;
};

int main() {
    string command;
    stek stekk;
    int num;
    while (command != "exit") {
        cin >> command;
        if (command == "push") {
            cin >> num;
            stekk.push(num);
        } else if (command == "back") {
            stekk.back();
        } else if (command == "pop") {
            stekk.pop();
        } else if (command == "size") {
            stekk.size();
        } else if (command == "clear") {
            stekk.clear();
        }
    }
    cout << "bye" << endl;
    return 0;
}