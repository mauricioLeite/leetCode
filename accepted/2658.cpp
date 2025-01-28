#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

#define pii pair<int,int>

// Overload ostream out operator to print vector n-dimensional
template <typename S>
ostream& operator<<(ostream& os, const vector<S>& vector){
    os << "[";
    size_t last = vector.size() - 1;
    for (size_t i = 0; i < vector.size(); i++) {
        os << vector[i];
        if (i != last) os << ", ";
    }
    os << "]";
    return os;
}

class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int mx_fish = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] != 0){
                    mx_fish = max(mx_local(i, j, grid), mx_fish);
                }
            }
        }

        return mx_fish;
    }

    int mx_local(int i, int j, vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) return 0;
        int mx = grid[i][j];
        grid[i][j] = 0;
        mx += mx_local(i+1, j, grid);
        mx += mx_local(i-1, j, grid);
        mx += mx_local(i, j+1, grid);
        mx += mx_local(i, j-1, grid);
        return mx;
    }

};

int main() {
    Solution* sol = new Solution();
    auto start = high_resolution_clock::now();

    vector<vector<int>> vect{{0,2,1,0},{4,0,0,3},{1,0,0,4},{0,3,2,0}};
    cout << sol->findMaxFish(vect) << endl;
    
    auto elapsed = high_resolution_clock::now() - start;
    long long microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";

    return 0;
}