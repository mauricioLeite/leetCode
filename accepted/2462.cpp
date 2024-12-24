#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

#define INF 0x3F3F3F

class Solution {
public:
    long long totalCost(vector<int>& costs, int round, int range) {
        priority_queue<int, vector<int>, greater<int>> ql, qr;
        int l = 0, r=costs.size()-1;
        long long total = 0;

        while(round--){
            while(ql.size() < range && l <= r){
                ql.push(costs[l++]);
            }
            while(qr.size() < range && l <= r){
                qr.push(costs[r--]);
            }
            
            int val_r = !qr.empty() ? qr.top() : INF;
            int val_l = !ql.empty() ? ql.top() : INF;

            if(val_l <= val_r){
                total += ql.top();
                ql.pop();
            }
            else {
                total += qr.top();
                qr.pop();
            }
        }

        return total; 
    }
};

int main() {
    Solution* sol = new Solution();
    auto start = high_resolution_clock::now();

    vector<int> vect{18,64,12,21,21,78,36,58,88,58,99,26,92,91,53,10,24,25,20,92,73,63,51,65,87,6,17,32,14,42,46,65,43,9,75};
    cout << sol->totalCost(vect, 13, 23 ) << endl;

    vect = {48};
    cout << sol->totalCost(vect, 1, 1) << endl;

    vect = {2,10,6,7,2,1,1,6,7,9,8};
    cout << sol->totalCost(vect, 4, 4) << endl;

    auto elapsed = high_resolution_clock::now() - start;
    long long microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";

    return 0;
}