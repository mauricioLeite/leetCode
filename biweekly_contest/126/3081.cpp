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

int INF = (1<<30);

class Solution {
public:
    string minimizeStringValue(string s) {
        vector<int> mp(26, 0);
        int count = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != '?') {
                mp[s[i]-97]++;
            } else {
                count++;
            }
        }

        string lowers = "";
        while(count--) {
            lowers += findLower(mp);
        }
        sort(lowers.begin(), lowers.end());
        
        int pos = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '?') s[i] = lowers[pos++];
        }
        return s;
    }
private:
    char findLower(vector<int>& mp) {
        int l = INF, pos = -1;
        for(int i = 0; i < 26; i++) {
            if(mp[i] < l) {
                l = mp[i];
                pos = i;
            }
        }
        mp[pos]++;
        return pos + 97;
    }
};

int main() {
    Solution* sol = new Solution();
    auto start = high_resolution_clock::now();

    cout << sol->minimizeStringValue("???") << endl;

    cout << sol->minimizeStringValue("a?a?") << endl;

    cout << sol->minimizeStringValue("abcdefghijklmnopqrstuvwxy??") << endl;


    auto elapsed = high_resolution_clock::now() - start;
    long long microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";

    return 0;
}