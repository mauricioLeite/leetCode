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
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        ans[0] = nums[0];
        for(int i = 1; i < n - 1; i++) {
            ans[i] = ans[i-1]*nums[i];
        }
        
        int acc = 1;
        for(int i = n - 1; i > 0; i--) {
            if(i != n-1) acc *= nums[i+1];
            ans[i] = ans[i-1]*acc;
        }
        ans[0] = acc*nums[1];
        return ans;

    }
};

int main() {
    Solution* sol = new Solution();
    auto start = high_resolution_clock::now();

    vector<int> vect{1,2,3,4};
    cout << sol->productExceptSelf(vect) << endl;

    vect.assign({-1,1,0,-3,3});
    cout << sol->productExceptSelf(vect) << endl;

    auto elapsed = high_resolution_clock::now() - start;
    long long microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";

    return 0;
}