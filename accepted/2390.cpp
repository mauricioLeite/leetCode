#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    string removeStars(string s) {
        string r(s.size(), 0);
        int j = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '*'){
                j--;
            } else {
                r[j] = s[i];
                j++;
            }
        }
        r.resize(j);
        return r;
    }
};

int main() {
    Solution* sol = new Solution();
    auto start = high_resolution_clock::now();

    cout << sol->removeStars("leet**cod*e") << endl;
    cout << sol->removeStars("erase*****") << endl;

    auto elapsed = high_resolution_clock::now() - start;
    long long microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";

    return 0;
}