#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

#define pii pair<int,int>

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
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> freqMax(26, 0);
        for(string w2 : words2){
            vector<int> freq(26, 0);
            for(char c : w2) freq[c-'a']++;

            for(int i = 0; i < 26; i++) freqMax[i] = max(freqMax[i], freq[i]);
        }

        vector<string> u;
        for(string w1 : words1){
            vector<int> freq(26, 0);
            for(char c : w1) freq[c-'a']++;
            bool universal = true;
            for(int i = 0; i < 26; i++) if(freqMax[i] > freq[i]) universal = false;
            if(universal) u.push_back(w1);
        }

        return u;
    }
};

int main() {
    Solution* sol = new Solution();
    auto start = high_resolution_clock::now();

    vector<string> w1{"amazon","apple","facebook","google","leetcode"};
    vector<string> w2{"e","o"};
    cout << sol->wordSubsets(w1, w2) << endl;

    auto elapsed = high_resolution_clock::now() - start;
    long long microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";

    return 0;
}