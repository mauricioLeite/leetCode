#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visit(n, false);
        dfs(0, rooms, visit);

        return std::all_of(visit.begin(), visit.end(), [](bool v){return v;});
    }

    void dfs(int v, vector<vector<int>>& graph, vector<bool>& visit){
        if(visit[v]) return;

        visit[v] = true;
        for(int i = 0; i < graph[v].size(); i++){
            dfs(graph[v][i], graph, visit);
        }
    }
};

int main() {
    Solution* sol = new Solution();
    auto start = high_resolution_clock::now();

    vector<vector<int>> vect{{1},{2},{3},{}};
    cout << sol->canVisitAllRooms(vect) << endl;

    auto elapsed = high_resolution_clock::now() - start;
    long long microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";

    return 0;
}