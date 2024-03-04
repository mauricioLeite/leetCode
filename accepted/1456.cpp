#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        int max_val = 0, current_max = 0;
        for(int i = 0; i < k; i++) {
            current_max += isVowel(s[i]);
        }
        
        max_val = current_max;
        for(int i = k; i < s.size(); i++) {
            current_max -= isVowel(s[i-k]);
            current_max += isVowel(s[i]);
            max_val = max(current_max, max_val);
        }
        
        return max_val;
    }

private:
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
};

int main() {
    Solution* sol = new Solution();
    cout << sol->maxVowels("abciiidef", 3) << endl;
    cout << sol->maxVowels("aeiou", 2) << endl;
    cout << sol->maxVowels("leetcode", 3) << endl;
    cout << sol->maxVowels("weallloveyou", 7) << endl;
    return 0;

}