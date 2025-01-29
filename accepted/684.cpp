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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        
        // union-find
        vector<int> ans;
        for(int i = 0; i < n; i++){
            int u = find(edges[i][0]-1, parent);
            int v = find(edges[i][1]-1, parent);
            if(u == v) ans = edges[i];
            else parent[u] = v;

        }
        return ans;
    }

    int find(int u, vector<int>& parent){
        if(parent[u] == u) return u;
        return parent[u] = find(parent[u], parent);
    }
};

int main() {
    Solution* sol = new Solution();
    auto start = high_resolution_clock::now();

    vector<vector<int>> vec{{1,2},{1,3},{2,3}};
    cout << sol->findRedundantConnection(vec) << endl;

    vec = {{9,10},{5,8},{2,6},{1,5},{3,8},{4,9},{8,10},{4,10},{6,8},{7,9}};
    cout << sol->findRedundantConnection(vec) << endl;

    auto elapsed = high_resolution_clock::now() - start;
    long long microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";

    return 0;
}