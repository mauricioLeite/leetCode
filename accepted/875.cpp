#include <bits/stdc++.h>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int l = 1, r = *max_element(piles.begin(), piles.end()), k;

        while(l < r) {
            k = l+(r-l)/2;
            if(cond(piles, k, h)) r = k;
            else l = k+1;
        }
        return r;
    }

    bool cond(vector<int> &piles, int k, int h) {
        int time = 0;
        for(int i = 0; i < piles.size(); i++){
            time += piles[i] / k;
            if(piles[i] % k != 0) time++;
            if (time > h) return false;
        }
        return true;
    }
};

int main() {
    Solution* sol = new Solution();
    auto start = high_resolution_clock::now();

    vector<int> vect={3,6,7,11};
    cout << sol->minEatingSpeed(vect, 8) << endl;

    vect = {332484035,524908576,855865114,632922376,222257295,690155293,112677673,679580077,337406589,290818316,877337160,901728858,679284947,688210097,692137887,718203285,629455728,941802184};
    cout << sol->minEatingSpeed(vect, 823855818) << endl;


    auto elapsed = high_resolution_clock::now() - start;
    long long microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";

    return 0;
}