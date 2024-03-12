#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    int maxArea(vector<int>& h) {
        int l = 0, r = h.size() -  1, maxA = 0;
        while(l < r) {
            int testA = (r - l)*min(h[r], h[l]);
            if(testA > maxA) {
                maxA = testA;
            }
            (h[l] < h[r]) ? l++ : r--;                    
        }
        return maxA;
    }
};

int main() {
    Solution* sol = new Solution();
    auto start = high_resolution_clock::now();

    vector<int> vect{1,8,6,2,5,4,8,3,7};
    cout << sol->maxArea(vect) << endl;

    vect.assign({1,1});
    cout << sol->maxArea(vect) << endl;

    vect.assign({2,3,4,5,18,17,6});
    cout << sol->maxArea(vect) << endl;

    auto elapsed = high_resolution_clock::now() - start;
    long long microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";

    return 0;
}