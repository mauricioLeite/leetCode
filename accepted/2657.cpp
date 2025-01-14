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
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size(), count = 0;
        vector<int> freq(51), ret(n);
        for(int i = 0; i < n; i++){
            freq[A[i]]++;
            if(freq[A[i]] == 2) count++;

            freq[B[i]]++;
            if(freq[B[i]] == 2) count++;

            ret[i] = count;
        }

        return ret;
    }
};

int main() {
    Solution* sol = new Solution();
    auto start = high_resolution_clock::now();

    vector<int> vec1{1,3,2,4}, vec2{3,1,2,4};
    cout << sol->findThePrefixCommonArray(vec1, vec2) << endl;

    auto elapsed = high_resolution_clock::now() - start;
    long long microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";

    return 0;
}