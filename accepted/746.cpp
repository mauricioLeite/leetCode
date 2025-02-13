#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    // Botton-Up Solution
    int minCostClimbingStairs(vector<int>& cost) {
        int i_1 = cost[1], i_2 = cost[0], curr; 
        for(int i = 2; i < cost.size(); i++){
            curr = min(i_1, i_2) + cost[i];
            i_2 = i_1;
            i_1 = curr;
        }

        return min(i_1, i_2);
    }
    // Top-Down Solution
    // int minCostClimbingStairs(vector<int>& cost) {
    //     vector<int> dp(cost.size(), -1);
    //     return min(solve(cost.size()-1, cost, dp), solve(cost.size()-2, cost, dp));
    // }

    // int solve(int i, vector<int> &cost, vector<int> &dp){
    //     if(i < 2) return cost[i];
    //     if(dp[i] != -1) return dp[i];
    //     return dp[i] = min(solve(i-1, cost, dp), solve(i-2, cost, dp)) + cost[i];
    // }
};

int main() {
    Solution* sol = new Solution();
    auto start = high_resolution_clock::now();

    vector<int> vect{1,100,1,1,1,100,1,1,100,1};
    cout << sol->minCostClimbingStairs(vect) << endl;

    auto elapsed = high_resolution_clock::now() - start;
    long long microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";

    return 0;
}