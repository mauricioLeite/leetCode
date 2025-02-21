#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

//Top-Down Solution
class Solution {
public:
    int dp[38];
    int tribonacci(int n) {
        if(dp[n] != 0) return dp[n];
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;
        return dp[n] = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
    }
};

//Bottom-Up Solution
// class Solution {
// public:
//     int tribonacci(int n) {
//         int dp[4];
//         dp[0] = 0;
//         dp[1] = dp[2] = 1;
//         for(int i = 3; i <= n; i++){
//             dp[i % 4] = dp[(i-1)%4] + dp[(i-2)%4] + dp[(i-3)%4];
//         }
//         return dp[n%4];
//     }
// };

int main() {
    Solution* sol = new Solution();
    auto start = high_resolution_clock::now();

    cout << sol->tribonacci(1) << endl;
    cout << sol->tribonacci(2) << endl;
    cout << sol->tribonacci(3) << endl;
    cout << sol->tribonacci(25) << endl;
    cout << sol->tribonacci(37) << endl;
    
    auto elapsed = high_resolution_clock::now() - start;
    long long microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";

    return 0;
}