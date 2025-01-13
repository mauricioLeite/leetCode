#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26, 0);
        int n = s.size();
        for(int i = 0; i < n; i++){
            freq[s[i] - 'a']++;
        }

        int count = 0;
        for(int i = 0; i < 26; i++){
            if(freq[i] == 0) continue;
            if(freq[i] % 2 == 1) count++;
            else count += 2;
        }

        return count;
    }
};

int main() {
    Solution* sol = new Solution();
    auto start = high_resolution_clock::now();

    cout << sol->minimumLength("abaacbcbb") << endl;
    cout << sol->minimumLength("waoji") << endl;

    auto elapsed = high_resolution_clock::now() - start;
    long long microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";

    return 0;
}