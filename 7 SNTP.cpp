
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class ttime {
public:
    ttime() = default;

    ttime(const string &stime) {
        sec = atoi(stime.substr(0, 2).c_str()) * 3600;
        sec += atoi(stime.substr(3, 2).c_str()) * 60;
        sec += atoi(stime.substr(6, 2).c_str());
    }

    void print() {
        cout << setfill('0') << setw(2) << sec / 3600 << ":" << setfill('0') << setw(2) << (sec % 3600) / 60 << ":"
             << setfill('0')
             << setw(2) << sec % 60 << endl;
    }


    ttime &operator+=(const ttime &obj) {
        sec += obj.sec;
        sec %= 24 * 3600;
        return *this;
    }

    ttime &operator-=(const ttime &obj) {
        sec -= obj.sec;
        sec += 24 * 3600;
        sec %= 24 * 3600;
        return *this;
    }

    ttime &operator/=(int a) {
        double tmp = sec / (double) a;
        if (abs(tmp - int(tmp) >= 0.5)) {
            tmp += 1;
        }
        sec = int(tmp);
        sec %= 24 * 3600;
        return *this;
    }


private:

    int sec;
};

int main() {
    string time1, time2, time3;
    cin >> time1 >> time2 >> time3;
    ttime ttime1(time1);
    ttime ttime2(time2);
    ttime ttime3(time3);
    ttime3 -= ttime1;
    ttime3 /= 2;
    ttime2 += ttime3;
    ttime2.print();
}