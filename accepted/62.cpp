#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Top-Down Solution
class Solution {
public:
    int dp[101][101];
    int uniquePaths(int n, int m) {
        if(dp[n][m] != 0) return dp[n][m];
        if(n == 1 || m == 1) return 1;
        return dp[n][m] = uniquePaths(n-1, m) + uniquePaths(n, m-1);
    }
};

//Bottom-Up Solution
// class Solution {
// public:
//     int uniquePaths(int n, int m) {
//         int dp[n+1][m+1];
//         for(int i = 1; i <= n; i++) dp[i][1] = 1;
//         for(int i = 1; i <= m; i++) dp[1][i] = 1;

//         for(int i = 2; i <= n; i++) {
//             for(int j = 2; j <= m; j++) {
//                 dp[i][j] = dp[i-1][j] + dp[i][j-1];
//             }
//         }
//         return dp[n][m];
//     }
// };

int main() {
    Solution* sol = new Solution();
    auto start = high_resolution_clock::now();

    cout << sol->uniquePaths(18, 6) << endl;
    cout << sol->uniquePaths(3, 7) << endl;
    
    auto elapsed = high_resolution_clock::now() - start;
    long long microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";

    return 0;
}