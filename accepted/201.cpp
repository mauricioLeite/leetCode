#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int count = 0;
        while(left != right) {
            left = left >> 1;
            right = right >> 1;
            count++;
        }

        if(left == 0) {
            return 0;
        }

        return left << count;
    }
};

int main() {    
    Solution* sol = new Solution();
    cout << sol->rangeBitwiseAnd(100, 2147483644) << endl;
    return 0;
}