#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

#define PB push_back

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
    bool doesValidArrayExist(vector<int>& t) {
        int sum = 0, n = t.size();
        for(int i = 0; i < n; i++){
            sum ^= t[i];
        }
        
        return !sum;
    }
};

int main() {
    Solution* sol = new Solution();
    auto start = high_resolution_clock::now();

    vector<int> vec{1,0};
    cout << sol->doesValidArrayExist(vec) << endl;

    vec = {0,1,1,1,0,1,1,1,0,0,0,1,0,0,0,0,1,1,1,1,0,1};
    cout << sol->doesValidArrayExist(vec) << endl;

    auto elapsed = high_resolution_clock::now() - start;
    long long microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";

    return 0;
}