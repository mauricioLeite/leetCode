#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        return n > 0 && !(n & (n - 1));
    }
};

int main() {    
    Solution* sol = new Solution();
    cout << sol->isPowerOfTwo(12) << endl;
    return 0;
}