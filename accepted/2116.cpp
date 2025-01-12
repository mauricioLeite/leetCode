#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if(n % 2 != 0) return false;

        stack<int> open, unlocked;
        
        for(int i = 0; i < n; i++){
            if(locked[i] == '0') {
                unlocked.push(i);
            } else if(s[i] == '(') {
                open.push(i);
            } else {
                if(!open.empty()) {
                    open.pop();
                } else if(!unlocked.empty()) {
                    unlocked.pop();
                } else {
                    return false;
                }
            }
        }
        
        while(!open.empty() && !unlocked.empty() && (open.top() < unlocked.top())) {
            open.pop();
            unlocked.pop();
        }

        return open.empty();
    }
};

int main() {
    Solution* sol = new Solution();
    auto start = high_resolution_clock::now();

    cout << sol->canBeValid("))()))", "010100") << endl;
    // cout << sol->canBeValid(")))(((", "010010") << endl;
    // cout << sol->canBeValid("())()))()(()(((())(()()))))((((()())(())", "1011101100010001001011000000110010100101") << endl;

    auto elapsed = high_resolution_clock::now() - start;
    long long microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";

    return 0;
}