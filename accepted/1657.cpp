#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

// First solution using hashmap and set
// class Solution {
// public:
//     bool closeStrings(string word1, string word2) {
//         if(word1.length() != word2.length()) return false;
        
//         map<char, int> count_1, count_2;
//         set<char> chars_1, chars_2;

//         for(char ch : word1) {
//             count_1[ch]++;
//             chars_1.insert(ch);
//         }
        
//         for(char ch : word2) {
//             count_2[ch]++;
//             chars_2.insert(ch);
//         }

//         if(chars_1 != chars_2) return false;

//         map<int, int> w1, w2;
//         for(pair<char, int> el : count_1) w1[el.second]++;
        
//         for(pair<char, int> el : count_2) w2[el.second]++;

//         for(auto el : w1) {
//             if(el.second != w2[el.first]) return false;
//         }
//         return true;
//     }
// };


// Optimized solution using only freq vector
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length() != word2.length()) return false;
        
        vector<int> count_1(26, 0);
        vector<int> count_2(26, 0);

        for(int i = 0; i < word1.size(); i++) {
            count_1[word1[i]-'a']++;
            count_2[word2[i]-'a']++;
        }

        for(int i = 0; i< 26; i++) {
            if((count_1[i] == 0 && count_2[i] != 0) || (count_1[i] != 0 && count_2[i] == 0)) return false;
        }

        sort(count_1.begin(), count_1.end());
        sort(count_2.begin(), count_2.end());

        for(int i = 0; i < 26; i++){
            if(count_1[i] != count_2[i]) return false;
        }
        return true;
    }
};

int main() {
    Solution* sol = new Solution();
    auto start = high_resolution_clock::now();

    cout << sol->closeStrings("abc", "bca") << endl;
    cout << sol->closeStrings("a", "aa") << endl;
    cout << sol->closeStrings("cabbba", "abbccc") << endl;

    auto elapsed = high_resolution_clock::now() - start;
    long long microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";

    return 0;
}