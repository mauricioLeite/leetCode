#include <bits/stdc++.h>
using namespace std;

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
    int longestSubarray(vector<int>& nums) {
        int left = 0, right = 0, pos = -1, max_window = 0;
        while(right < nums.size()) {
            if(nums[right] != 1) {
                max_window = max(max_window, right - left);
                left = pos + 1;
                pos = right;
            }
            right++;
        }
        max_window = max(max_window, right - left) - 1;
        return max_window;
    }
};

int main() {
    Solution* sol = new Solution();
    vector<int> vect{0,1,1,1,0,1,1,0,1};
    cout << sol->longestSubarray(vect) << endl;
    return 0;

}