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
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums2.size();
        vector<pair<int,int>> nums;
        
        for(int i = 0; i < n; i++){
            nums.push_back(make_pair(nums1[i], nums2[i]));
        }

        sort(nums.begin(), nums.end(), [](pair<int,int> a, pair<int,int> b){return a.second > b.second;});

        priority_queue<int, vector<int>, greater<int>> q;
        long long sum = 0, score = -1;
        for(pair<int,int> el: nums) {
            q.push(el.first);
            sum += el.first;
            if(q.size() > k){
                sum -= q.top();
                q.pop();
            }
            if(q.size() == k) {
                score = max(score, sum*el.second);
            }
        }

        return score;
    }
};

int main() {
    Solution* sol = new Solution();
    auto start = high_resolution_clock::now();

    vector<int> v1{1,3,3,2}, v2{2,1,3,4};

    cout << sol->maxScore(v1, v2, 3) << endl;

    auto elapsed = high_resolution_clock::now() - start;
    long long microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";
    return 0;
}