#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<string, int> r;
        string key;
        for(int i = 0; i < n; i++) {
            key = "";
            for(int j = 0; j < n; j++){
                key += to_string(grid[i][j]);
                key += ".";
            }
            r[key]++;
        }

        int total = 0;
        for(int i = 0; i < n; i++) {
            key = "";
            for(int j = 0; j < n; j++){
                key += to_string(grid[j][i]);
                key += ".";
            }
            if(r[key] != 0) total += r[key];
        }

        return total;
    }
};

int main() {
    Solution* sol = new Solution();
    auto start = high_resolution_clock::now();

    vector<vector<int>> vec{{3,2,1},{1,7,6},{2,7,7}};
    cout << sol->equalPairs(vec) << endl;

    auto elapsed = high_resolution_clock::now() - start;
    long long microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";

    return 0;
}