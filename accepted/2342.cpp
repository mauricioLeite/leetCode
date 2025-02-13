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
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,vector<int>> mp;
        for(int i = 0; i < n; i++){
            int el = nums[i];
            int acc = 0;
            while(el > 0){
                acc += el % 10;
                el /= 10;
            }
            mp[acc].push_back(nums[i]);
        }
        
        int max_val = -1;
        for(auto el: mp){
            if(el.second.size() > 1){
                sort(el.second.begin(), el.second.end(), greater<int>());
                max_val = max(max_val, el.second[0]+el.second[1]);
            }
        }
        
        return max_val;
    }
};

int main() {
    Solution* sol = new Solution();
    auto start = high_resolution_clock::now();

    vector<int> vec{18,43,36,13,7};
    cout << sol->maximumSum(vec) << endl;

    vec = {10,12,19,14};
    cout << sol->maximumSum(vec) << endl;

    auto elapsed = high_resolution_clock::now() - start;
    long long microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";

    return 0;
}