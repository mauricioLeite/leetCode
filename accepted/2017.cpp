#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

#define ll long long

class Solution {
public:
    ll gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        ll up = reduce(grid[0].begin(), grid[0].end(), 0LL), down = 0LL, path2 = LONG_LONG_MAX;
        for(int i = 0; i < n; i++){
            up -= grid[0][i];
            path2 = min(path2, max(up, down));
            down += grid[1][i];
        }  
        return path2;
    }
};

int main() {
    Solution* sol = new Solution();
    auto start = high_resolution_clock::now();

    vector<vector<int>> vec{{1,3,1,15},{1,3,3,1}};
    cout << sol->gridGame(vec) << endl;

    vec = {{5,2,2,4,3,4},{3,2,1,3,4,1}};
    cout << sol->gridGame(vec) << endl;

    auto elapsed = high_resolution_clock::now() - start;
    ll microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";

    return 0;
}