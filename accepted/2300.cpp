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
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long target) {
        int n = spells.size(), m = potions.size(), opt;
        long long prod;
        vector<int> result(n, 0);
        sort(potions.begin(), potions.end());
        for(int i = 0; i < n; i++) {
            int l = 0, r = m - 1;
            while(l <= r){
                int mid = (l+r) / 2;
                prod = (long long) spells[i]* (long long) potions[mid];
                if(prod >= target) r = mid-1;
                else l = mid+1;
            }

            result[i] = m - l;
        }
        return result;
    }
};

int main() {
    Solution* sol = new Solution();
    auto start = high_resolution_clock::now();

    vector<int> s{5, 1, 3}, p{1,2,3,4,5};
    cout << sol->successfulPairs(s, p, 7) << endl;

    s = {3,1,2}, p = {8, 3, 3, 3, 3, 8, 1, 8};
    cout << sol->successfulPairs(s, p, 16) << endl;

    auto elapsed = high_resolution_clock::now() - start;
    long long microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";

    return 0;
}