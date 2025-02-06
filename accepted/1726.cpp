#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

#define pii pair<int,int>

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> f;
        int n = nums.size(), count = 0;
        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++) {
                count += f[nums[i]*nums[j]]*8;
                f[nums[i]*nums[j]]++;
            }
        }

        return count;
    }
};

int main() {
    Solution* sol = new Solution();
    auto start = high_resolution_clock::now();

    vector<int> vect{1,2,4,5,10};
    cout << sol->tupleSameProduct(vect) << endl;

    auto elapsed = high_resolution_clock::now() - start;
    long long microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";

    return 0;
}