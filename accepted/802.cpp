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
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> nodes, safe(n, 0), visit(n, 0);
        for(int i = 0; i < n; i++){
            if(checkPath(i, visit, safe, graph))  nodes.push_back(i);
        }
        
        return nodes;
    }

    bool checkPath(int v, vector<int>& visited, vector<int>& safe, vector<vector<int>>& graph) {
        if(visited[v]) return safe[v] == 1;
        visited[v] = 1;
        for(int u: graph[v]){
            if(!checkPath(u, visited, safe, graph)) return false;
        }
        safe[v] = 1;
        return true;
    }
};

int main() {
    Solution* sol = new Solution();
    auto start = high_resolution_clock::now();

    vector<vector<int>> vec{{1,2},{2,3},{5},{0},{5},{},{}};
    cout << sol->eventualSafeNodes(vec) << endl;

    vec = {{},{0,2,3,4},{3},{4},{}};
    cout << sol->eventualSafeNodes(vec) << endl;

    auto elapsed = high_resolution_clock::now() - start;
    long long microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";

    return 0;
}