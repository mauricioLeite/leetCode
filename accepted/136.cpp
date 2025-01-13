#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int holder = 0;
        for(int i = 0; i < nums.size(); i++){
            holder ^= nums[i];
        }
        return holder;
    }
};

int main() {
    Solution* sol = new Solution();
    auto start = high_resolution_clock::now();

    vector<int> vect{4,1,2,1,2};
    cout << sol->singleNumber(vect) << endl;


    auto elapsed = high_resolution_clock::now() - start;
    long long microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";

    return 0;
}