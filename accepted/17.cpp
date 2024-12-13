#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

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
    unordered_map<char, vector<char>> mapping = {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}}
    };

    vector<string> ret;
    string sol;
    
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        ret = {};
    
        if(n == 0) return ret;

        backtracking(digits, 0, n);
        return ret;
    }

    void backtracking(string digits, int key, int n) {
        if(sol.size() == n) {
            ret.push_back(sol);
            return;
        }

        for(int i = 0; i < mapping[digits[key]].size(); i++) {
            sol.push_back(mapping[digits[key]][i]);
            
            backtracking(digits, key+1, n);
            
            sol.pop_back();

        }
    }
};

int main() {
    Solution* sol = new Solution();
    auto start = high_resolution_clock::now();

    cout << sol->letterCombinations("23") << endl;
    cout << sol->letterCombinations("") << endl;
    cout << sol->letterCombinations("789") << endl;


    auto elapsed = high_resolution_clock::now() - start;
    long long microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";

    return 0;
}