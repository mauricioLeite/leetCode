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

class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<int> deg(n, 0);
        for(int i = 0; i < n; i++) deg[favorite[i]]++;

        queue<int> q;
        for(int i = 0; i < n; i++) if(deg[i]==0) q.push(i);

        int lvl = 1;
        vector<int> chain(n, 1);
        while(!q.empty()){
            int s = q.size();
            while(s--){
                int u = q.front();
                q.pop();
                int v = favorite[u];
                chain[v] = max(lvl+1, chain[v]);
                if(--deg[v] == 0) q.push(v);
            }
            lvl++;
        }

        int cycle = 0, join_cycle = 0;
        for(int i = 0; i < n; i++) {
            if(deg[i]==0) continue;
            int len = 0, v = i;
            while(deg[v]!=0){
                len++;
                deg[v] = 0;
                v = favorite[v];
            }

            if(len > 2) cycle = max(cycle, len);
            else join_cycle += chain[i] + chain[favorite[i]];
        }

        return max(cycle, join_cycle);
    }
};

int main() {
    Solution* sol = new Solution();
    auto start = high_resolution_clock::now();

    vector<int> vect{2,2,1,2};
    cout << sol->maximumInvitations(vect) << endl;

    vect = {1,0,0,2,1,4,7,8,9,6,7,10,8};
    cout << sol->maximumInvitations(vect) << endl;
    
    auto elapsed = high_resolution_clock::now() - start;
    long long microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";

    return 0;
}