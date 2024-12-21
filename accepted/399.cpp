#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

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

// Overload ostream out operator to print pairs
template <typename S, typename T>
ostream& operator<<(ostream& os, const pair<S,T>& p){
    os << "(" << p.first << ","<< p.second << ")";
    return os;
}

// Overload ostream out operator to print pairs
template <typename S, typename T>
ostream& operator<<(ostream& os, const unordered_map<S,T>& m){
    os << "{";
    int pos = 0, last = m.size() - 1;
    for (auto el : m) {
        os << el;
        if (pos++ < last) os << ", ";
    }
    os << "}";
    return os;
}

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();

        unordered_map<string, vector<pair<string, double>>> graph;
        string s, t;
        for(int i = 0; i < n; i++) { 
            s = equations[i][0];
            t = equations[i][1];
            graph[s].push_back(make_pair(t, values[i]));
            graph[t].push_back(make_pair(s, 1/values[i]));
        }
        
        vector<double> result;
        map<string, bool> visit;
        for(vector<string> q : queries){
            if(q[0] == q[1] && graph[q[0]].size() > 0){
                result.push_back(1);
                continue;
            }
            else if(graph[q[0]].size() == 0 || graph[q[1]].size() == 0) {
                result.push_back(-1);
                continue;
            }

            result.push_back(dfs(q[0], q[1], graph, visit));
            visit.clear();
        }
         
        return result;
    }

    double dfs(string s, string t, unordered_map<string, vector<pair<string, double>>>& graph, map<string, bool>& visit) {
        if(visit[s]) return 0;
        if(s == t) return 1;
        visit[s] = true;

        double cum;
        for(auto [adj,val] : graph[s]) {
            cum = dfs(adj, t, graph, visit);
            if(cum > 0) return cum * val;
        }
        return -1;
    }
};

int main() {
    Solution* sol = new Solution();
    auto start = high_resolution_clock::now();


    vector<vector<string>> eq{{"a","b"},{"b","c"}};
    vector<double> vals{2.0, 3.0};
    vector<vector<string>> q{{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};

    cout << sol->calcEquation(eq, vals, q) << endl;

    auto elapsed = high_resolution_clock::now() - start;
    long long microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";
    return 0;
}