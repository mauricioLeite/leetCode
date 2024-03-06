#include <bits/stdc++.h>
using namespace std;

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
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int j = -1;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                j = i;
                break;
            }
        }
        if(j != -1){
            for(int i = j + 1; i < n; i++) {
                if(nums[i] != 0) {
                    swap(nums[i], nums[j]);
                    j++;
                }
            }
        }
    }
};

int main() {
    Solution* sol = new Solution();
    vector<int> vect{1, 3, 0,0,0,0, 0,1,0,3,12};

    sol->moveZeroes(vect);
    cout << vect << endl;
    return 0;

}