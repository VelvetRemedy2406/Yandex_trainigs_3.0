
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> stek;
    int curr_carriage = 1;
    int n,new_carriage;
    cin >> n;

    for(size_t i = 0; i < n; ++ i)
    {
        cin >> new_carriage;
        stek.push_back(new_carriage);
        while ((!stek.empty()) && stek.back() == curr_carriage)
        {
            stek.pop_back();
            curr_carriage +=1;
        }
    }
    while ((!stek.empty()) && stek.back() == curr_carriage)
    {
        stek.pop_back();
        curr_carriage +=1;
    }
    if(stek.empty())
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}