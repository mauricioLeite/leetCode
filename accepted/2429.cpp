#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    int minimizeXor(int n1, int n2) {
        int b1 = __builtin_popcount(n1), b2 = __builtin_popcount(n2);
        if(b1 == b2) return n1;
        
        for(int i = 0; i < 32; i++){
            if(b1 == b2) return n1;
            if(b1 > b2 && (n1 & (1<<i))) {
                n1 ^= (1<<i);
                b1--;
            }
            if(b1 < b2 && !(n1 & (1<<i))){ 
                n1 ^= (1<<i);
                b1++;
            }
        }

        return n1;
    }
};

int main() {
    Solution* sol = new Solution();
    auto start = high_resolution_clock::now();

    cout << sol->minimizeXor(1, 12) << endl;

    auto elapsed = high_resolution_clock::now() - start;
    long long microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";

    return 0;
}