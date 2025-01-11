#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();
        if(n < k) return false;
        if(n == k) return true;

        unordered_map<char,int> mp;
        for(int i = 0; i < n; i++){
            mp[s[i]]++;
        }

        int odds = 0;
        for(auto el : mp){
            odds += el.second & 1;
        }

        return (odds <= k);
    }
};

int main() {
    Solution* sol = new Solution();
    auto start = high_resolution_clock::now();
    
    cout << sol->canConstruct("annabelle", 2) << endl;
    cout << sol->canConstruct("leetcode", 3) << endl;
    cout << sol->canConstruct("true", 4) << endl;

    auto elapsed = high_resolution_clock::now() - start;
    long long microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";
    return 0;
}