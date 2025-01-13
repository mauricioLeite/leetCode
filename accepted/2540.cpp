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

// Two pointers solution (Slower)
// class Solution {
// public:
//     int getCommon(vector<int>& v1, vector<int>& v2) {
//         int i = 0, j = 0, s1 = v1.size(), s2 = v2.size();
//         while(i < s1 && j < s2) {
//             if(v1[i] == v2[j]) return v1[i];
//             if(v1[i] < v2[j]) i++;
//             if(v2[j] < v1[i]) j++;
//         }
//         return -1;
//     }
// };


// Binary Search solution
class Solution {
public:
    int getCommon(vector<int>& v1, vector<int>& v2) {
        if(v1.size() > v2.size()) swap(v1, v2);
        for(int i = 0; i< v1.size(); i++) {
            if(binary_search(v2, v1[i])) return v1[i];
        }
        return -1;
    }
private:
    bool binary_search(vector<int>& n, int key) {
        int l = 0, r = n.size();
        while(l <= r) {
            int m = floor(l + (r - l) / 2);
            if(n[m] == key) return true;
            if(n[m] < key) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return false;
    }
};

int main() {
    Solution* sol = new Solution();
    auto start = high_resolution_clock::now();

    vector<int> v1{1, 2, 3};
    vector<int> v2{2, 4};
    cout << sol->getCommon(v1, v2) << endl;
    
    v1.assign({1, 2, 3, 6});
    v2.assign({2, 3, 4, 5});
    cout << sol->getCommon(v1, v2) << endl;

    auto elapsed = high_resolution_clock::now() - start;
    long long microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";

    return 0;
}