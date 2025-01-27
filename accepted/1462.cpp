#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

#define PB push_back

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
    vector<bool> checkIfPrerequisite(int nodes, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector<vector<int>> graph(nodes); 
        int n = edges.size();
        for(int i = 0; i < n; i++) graph[edges[i][0]].PB(edges[i][1]);
        
        vector<vector<bool>> memo(nodes, vector<bool>(nodes, false));
        for(int i = 0; i < nodes; i++){
            dfs(i, i, graph, memo);
        }

        int qs = queries.size();
        vector<bool> result(qs);
        for(int i = 0; i < qs; i++){
            int u = queries[i][0], v = queries[i][1];
            result[i] = memo[u][v];
        }
        return  result;
    }

    void dfs(int v, int ref, vector<vector<int>>& graph, vector<vector<bool>>& memo){
        if(memo[ref][v]) return;
        if(ref != v) memo[ref][v] = true;
        for(int i = 0; i < graph[v].size(); i++){
            dfs(graph[v][i], ref, graph, memo);
        }
    }
};

int main() {
    Solution* sol = new Solution();
    auto start = high_resolution_clock::now();

    vector<vector<int>> pre{{1,2},{1,0},{2,0}};
    vector<vector<int>> queries{{1,0},{1,2}};
    cout << sol->checkIfPrerequisite(3, pre, queries) << endl;

    pre = {{0,1},{1,2},{2,3},{3,4}};
    queries = {{0,4},{4,0},{1,3},{3,1}};
    cout << sol->checkIfPrerequisite(5, pre, queries) << endl;


    auto elapsed = high_resolution_clock::now() - start;
    long long microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";

    return 0;
}