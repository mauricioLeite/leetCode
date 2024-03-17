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
    int sumOfEncryptedInt(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            int max = -1, n = nums[i], pos = 0;
            while(n > 9) {
                if(max < n % 10) max = n% 10;
                n /= 10; 
                pos++;
            }
            
            if(max < n) max = n;
            n = max;
            while(pos--) {
                max = (max*10) + n;
            }
            sum += max;
        }
        return sum;
    }
};

int main() {
    Solution* sol = new Solution();
    auto start = high_resolution_clock::now();

    vector<int> vect{1,2,3};
    cout << sol->sumOfEncryptedInt(vect) << endl;

    vect.assign({10, 21, 31});
    cout << sol->sumOfEncryptedInt(vect) << endl;

    vect.assign({1120, 2122, 313});
    cout << sol->sumOfEncryptedInt(vect) << endl;

    auto elapsed = high_resolution_clock::now() - start;
    long long microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";

    return 0;
}