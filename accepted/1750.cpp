#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    int minimumLength(string s) {
        int i = 0, j = s.size() - 1;
        while(i < j) {
            if(s[i] != s[j]) break;
            while(s[i] == s[i+1] && i < s.size() - 1) i++;
            while(s[j] == s[j-1] && j >= i) j--;
            i++;
            j--;
        }
        return (i > j) ? 0 : j - i + 1;
    }
};

int main() {
    Solution* sol = new Solution();
    auto start = high_resolution_clock::now();

    cout << sol->minimumLength("ca") << endl;
    cout << sol->minimumLength("cabaabac") << endl;
    cout << sol->minimumLength("aabccabba") << endl;
    cout << sol->minimumLength("bbbbbbbbbbbbbbbbbbbbbbbbbbbabbbbbbbbbbbbbbbccbcbcbccbbabbb") << endl;
    
    auto elapsed = high_resolution_clock::now() - start;
    long long microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";
    return 0;
}