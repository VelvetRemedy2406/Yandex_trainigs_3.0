#include <iostream>
#include <vector>
#include <list>

using namespace std;

class dek {
public:
    void push_front(int n) {
        ldek.push_front(n);
        cout << "ok" << endl;
    }

    void push_back(int n) {
        ldek.push_back(n);
        cout << "ok" << endl;
    }

    void pop_front() {
        if (ldek.empty()) {
            cout << "error" << endl;
            return;
        }
        cout << ldek.front() << endl;
        ldek.pop_front();
    }

    void pop_back() {
        if (ldek.empty()) {
            cout << "error" << endl;
            return;
        }
        cout << ldek.back() << endl;
        ldek.pop_back();
    }

    void front() {
        if (ldek.empty()) {
            cout << "error" << endl;
            return;
        }
        cout << ldek.front() << endl;

    }

    void back() {
        if (ldek.empty()) {
            cout << "error" << endl;
            return;
        }
        cout << ldek.back() << endl;

    }

    void clear() {
        ldek.clear();
        cout << "ok" << endl;
    }

    void size() const noexcept {
        cout << ldek.size() << endl;
    }


private:
    list<int> ldek;
};

int main() {
    dek deque;
    int num;
    string s;
    while (cin >> s) {
        if (s == "exit") {
            cout << "bye" << endl;
            return 0;
        } else if (s == "front") {
            deque.front();
        } else if (s == "back") {
            deque.back();
        } else if (s == "size") {
            deque.size();
        } else if(s == "clear")
        {
            deque.clear();
        }else if(s == "pop_back")
        {
            deque.pop_back();
        }
        else if(s == "pop_front")
        {
            deque.pop_front();
        } else if(s == "push_back")
        {
            cin >> num;
            deque.push_back(num);
        }
        else if(s == "push_front")
        {
            cin >> num;
            deque.push_front(num);
        }

    }
    return 0;
}