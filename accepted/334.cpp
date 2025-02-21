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
    bool increasingTriplet(vector<int>& n) {
        int l = INT_MAX, r = INT_MAX;
        for(int i = 0; i < n.size(); i++) {
            if(r < n[i]) return true;
            else if(l < n[i]) r = n[i];
            else if(n[i] < l) l = n[i];
        }
        return false;
    }
};

int main() {
    Solution* sol = new Solution();
    auto start = high_resolution_clock::now();

    vector<int> vect{1,2,3,4,5};
    cout << sol->increasingTriplet(vect) << endl;

    vect.assign({5,4,3,2,1});
    cout << sol->increasingTriplet(vect) << endl;

    vect.assign({2,1,5,0,4,6});
    cout << sol->increasingTriplet(vect) << endl;

    vect.assign({2147483646,2147483647,2147483647});
    cout << sol->increasingTriplet(vect) << endl;

    auto elapsed = high_resolution_clock::now() - start;
    long long microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";

    return 0;
}