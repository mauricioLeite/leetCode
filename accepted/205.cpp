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
    bool isIsomorphic(string s, string t) {
        map<int, int> mp_s, mp_t;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(mp_s.find(s[i]) == mp_s.end()) mp_s[s[i]] = i;
            if(mp_t.find(t[i]) == mp_t.end()) mp_t[t[i]] = i;
            if(mp_s[s[i]] != mp_t[t[i]]) return false;
        }

        return true;
    }
};

int main() {
    Solution* sol = new Solution();
    auto start = high_resolution_clock::now();

    cout << sol->isIsomorphic("egg", "add") << endl;

    auto elapsed = high_resolution_clock::now() - start;
    long long microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";

    return 0;
}