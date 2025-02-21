#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    int memo[1001][1001];
    int longestCommonSubsequence(string text1, string text2) {
        memset(memo, -1, sizeof(int)*1001*1001);
        return solve(text1.size()-1, text2.size()-1, text1, text2);
    }

    int solve(int i, int j, string& text1, string& text2) {
        if(i == -1 || j == -1) return 0;
        if (memo[i][j] != -1 ) return memo[i][j];

        if(text1[i] == text2[j]) {
            return memo[i][j] = solve(i-1, j-1, text1, text2) + 1;
        }
        return memo[i][j] = max(solve(i-1, j, text1, text2), solve(i, j-1, text1, text2));
    }
};

int main() {
    Solution* sol = new Solution();
    auto start = high_resolution_clock::now();
    
    cout << sol->longestCommonSubsequence("ylqpejqbalahwr", "yrkzavgdmdgtqpg") << endl;
    cout << sol->longestCommonSubsequence("abc", "abc") << endl;
    cout << sol->longestCommonSubsequence("abcd", "efgh") << endl;
    
    auto elapsed = high_resolution_clock::now() - start;
    long long microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";

    return 0;
}