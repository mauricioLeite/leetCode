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
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();
        queue<pii> q;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++)
                if(isWater[i][j] == 1) q.push({i, j});
        }

        int height = 0;
        while(!q.empty()){
            int s = q.size();
            while(s--){
                auto [x, y] = q.front();
                q.pop();
                if(visited[x][y]) continue;
                visited[x][y] = 1;
                isWater[x][y] = height;
                for(int i = 0; i < 4; i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]){
                        q.push({nx, ny});
                    }
                }
            }
            height++;
        }
        
        return isWater;
    }
};

int main() {
    Solution* sol = new Solution();
    auto start = high_resolution_clock::now();

    vector<vector<int>> vec{{0, 1},{0, 0}};
    cout << sol->highestPeak(vec) << endl;

    vec = {{0,0,1},{1,0,0},{0,0,0}};
    cout << sol->highestPeak(vec) << endl;

    auto elapsed = high_resolution_clock::now() - start;
    long long microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";

    return 0;
}