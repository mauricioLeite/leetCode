#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> c(m+n, 0);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++) {
                if(grid[i][j] != 1) continue;
                c[i]++;
                c[m+j]++;
            }
        }

        int count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++) 
                if(grid[i][j] == 1 && (c[i] > 1 || c[m+j] > 1)) count++;
        }

        return count;
    }
};

int main() {
    Solution* sol = new Solution();
    auto start = high_resolution_clock::now();

    vector<vector<int>> vec{{1,1,0,0},{0,0,1,0},{0,0,1,0},{0,0,0,1}};
    cout << sol->countServers(vec) << endl;

    vec = {{1, 0}, {1,1}};
    cout << sol->countServers(vec) << endl;

    auto elapsed = high_resolution_clock::now() - start;
    long long microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";

    return 0;
}