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
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxInitial = 0, n = candies.size();
        vector<bool> ans(n, false);

        for(int i = 0; i < n; i++) {
            maxInitial = max(maxInitial, candies[i]);
        }

        for(int i = 0; i < n; i++) {
            ans[i] = (candies[i] + extraCandies >= maxInitial);
        }
        return ans;
    }
};

int main() {
    Solution* sol = new Solution();
    auto start = high_resolution_clock::now();

    vector<int> vect{2,3,5,1,3};
    cout << sol->kidsWithCandies(vect, 3) << endl;

    vect.assign({4,2,1,1,2});
    cout << sol->kidsWithCandies(vect, 1) << endl;

    vect.assign({12,1,12});
    cout << sol->kidsWithCandies(vect, 10) << endl;
    
    auto elapsed = high_resolution_clock::now() - start;
    long long microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";

    return 0;
}