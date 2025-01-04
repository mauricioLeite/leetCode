#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1 == word2) return 0;
        int m = word1.size(), n = word2.size();
        if(m == 0 || n == 0) return max(m, n);
        vector<vector<int>> dp(word1.size(), vector<int> (word2.size(), -1));
        return solve(0, 0, word1, word2, dp);
    }

    int solve(int p1, int p2, string& w1, string& w2, vector<vector<int>>& dp) {
        if(p1 == w1.size()) return w2.size() - p2;
        if(p2 == w2.size()) return w1.size() - p1;
        
        if(dp[p1][p2] != -1) return dp[p1][p2];

        if(w1[p1] == w2[p2]) return dp[p1][p2] = solve(p1+1, p2+1, w1, w2, dp);
        return dp[p1][p2] = min({solve(p1+1, p2+1, w1, w2, dp), solve(p1, p2+1, w1, w2, dp), solve(p1+1, p2, w1, w2, dp)}) + 1;
    }
};

int main() {
    Solution* sol = new Solution();
    auto start = high_resolution_clock::now();
    
    cout << sol->minDistance("intention", "execution") << endl;
    cout << sol->minDistance("sea", "eat") << endl;

    auto elapsed = high_resolution_clock::now() - start;
    long long microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";
    return 0;
}