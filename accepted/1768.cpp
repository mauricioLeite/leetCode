#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int s1 = word1.size(), s2 = word2.size(), i = 0,  j = 0;
        string cum = "";
        
        while(i < s1 || j < s2) {
            if (i < s1) cum += word1[i++];
            if (j < s2) cum += word2[j++];
        }

        return cum;
    }
};

int main() {
    Solution* sol = new Solution();
    auto start = high_resolution_clock::now();

    cout << sol->mergeAlternately("abcd", "pq") << endl;
    
    auto elapsed = high_resolution_clock::now() - start;
    long long microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";
    return 0;
}