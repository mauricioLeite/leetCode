#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

#define MP make_pair

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
    vector<int> dailyTemperatures(vector<int>& temps) {
        int n = temps.size(), aux = 0;
        stack<int> stk;
        vector<int> ret(n, 0);
        for(int i = n-1; i >= 0; i--){
            while(!stk.empty() && temps[stk.top()] <= temps[i]){
                stk.pop();
            }
            
            if(!stk.empty()) ret[i] = stk.top() - i;
            stk.push(i);

        }
        return ret;

    }
};

int main() {
    Solution* sol = new Solution();
    auto start = high_resolution_clock::now();

    vector<int> vect = {73,74,75,71,69,72,76,73};
    cout << sol->dailyTemperatures(vect) << endl;

    vect = {30,40,50,60};
    cout << sol->dailyTemperatures(vect) << endl;

    vect = {30,60,90};
    cout << sol->dailyTemperatures(vect) << endl;

    auto elapsed = high_resolution_clock::now() - start;
    long long microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";

    return 0;
}