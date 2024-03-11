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
    vector<int> asteroidCollision(vector<int>& ast) {
        vector<int> ans;
        for(int i = 0; i < ast.size(); i++) {
            if(ans.size() > 0) {
                if(ans.back() > 0 && ast[i] < 0) {
                    int back = ans.back();
                    if(abs(back) <= abs(ast[i])) ans.pop_back();
                    if(abs(back) < abs(ast[i])) i--;
                    continue;
                }
            }
            ans.push_back(ast[i]);
        }
        return ans;
    }
};

int main() {
    Solution* sol = new Solution();
    auto start = high_resolution_clock::now();

    vector<int> vect{10,2,-5};

    cout << sol->asteroidCollision(vect) << endl;

    vect.assign({8, -8});
    cout << sol->asteroidCollision(vect) << endl;

    auto elapsed = high_resolution_clock::now() - start;
    long long microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";

    return 0;
}