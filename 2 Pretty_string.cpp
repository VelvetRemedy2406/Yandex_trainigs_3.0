
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int k;
    cin >> k;
    string str;
    cin >> str;
    int ans = 0;
    for (char letter = 'a'; letter <= 'z'; ++letter) {
        int left = 0;
        int right = 1;
        int curr_letter = 0;
        for (; right <= str.size(); ++right) {
            if (str[right - 1] == letter) {
                curr_letter++;
            } else {
                while (curr_letter + k < right - left) {
                    left++;
                    if (str[left - 1] == letter) {
                        curr_letter--;
                    }
                }
            }
            ans = max(ans, right - left);
        }

    }
    cout << ans;
    return 0;
}