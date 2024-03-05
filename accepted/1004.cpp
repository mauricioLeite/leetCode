#include <bits/stdc++.h>
using namespace std;

// Solution using sliding windows with reset of position
// class Solution {
// public:
//     int longestOnes(vector<int>& nums, int k) {
//         int window = 0, aux = k, max_val = 0;
//         for(int i = 0; i < nums.size(); i++) {
//             if(nums[i]) window++;
//             if(nums[i] == 0) {
//                 if(aux > 0) {
//                     window++;
//                     aux--;
//                 } else {
//                     if(nums[i-window] != 0){
//                         i -= window;
//                         window = 0;
//                         aux = k;
//                     }
//                 }
//             }
//             max_val = max(max_val, window);
//         }

//         return max_val;
//     }
// };

// Optimized solution with time O(n)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0;
        while(right < nums.size()) {
            if(nums[right] != 1) {
                k--;
            }
            if(k < 0) {
                if(nums[left] != 1) {
                    k++;
                }
                left++;
            }
            right++;
        }
        return right - left;
    }
};

int main() {
    Solution* sol = new Solution();
    vector<int> vect{0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    cout << sol->longestOnes(vect, 3) << endl;
    return 0;

}