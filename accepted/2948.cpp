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
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) { 
        int n = nums.size(), current = 0;
        unordered_map<int, int> group_map;
        map<int, queue<int>> groups;
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        groups[current].push(sorted[0]);
        group_map[sorted[0]] = current;

        for(int i = 1; i < n ; i++){
            if(sorted[i] - groups[current].back() > limit){
                current++;
            }
            groups[current].push(sorted[i]);
            group_map[sorted[i]] = current;
        }

        for(int i = 0; i < n ; i++){
            int key = group_map[nums[i]];
            nums[i] = groups[key].front();
            groups[key].pop();
        }

        return nums;
    }
};

int main() {
    Solution* sol = new Solution();
    auto start = high_resolution_clock::now();

    vector<int> vec{1,7,6,18,2,1};
    cout << sol->lexicographicallySmallestArray(vec, 3) << endl;

    vec = {1,5,3,9,8};
    cout << sol->lexicographicallySmallestArray(vec, 2) << endl;
    
    auto elapsed = high_resolution_clock::now() - start;
    long long microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";

    return 0;
}