#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    // Top-Down Solution
    // int rob(vector<int>& nums) {
    //     int n = nums.size();
        
    //     vector<int> dp(n, -1);
    //     return solveDP(n-1, nums, dp);
    // }

    // int solveDP(int i, vector<int> &nums, vector<int> &dp) {
    //     if(i < 0) return 0;
    //     if(dp[i] != -1) return dp[i];
    //     return dp[i] = max(nums[i] + solveDP(i-2, nums, dp), solveDP(i-1, nums, dp));
    // }

    // Bottom-Up Solution
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        vector<int> dp(n, -1);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < n; i++){
            dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
        }

        return dp[n-1];
    }
};

int main() {
    Solution* sol = new Solution();
    auto start = high_resolution_clock::now();

    vector<int> vect{6,3,10,8,2,10,3,5,10,5,3};
    cout << sol->rob(vect) << endl;

    auto elapsed = high_resolution_clock::now() - start;
    long long microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";

    return 0;
}