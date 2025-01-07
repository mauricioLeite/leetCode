#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>> intervals) {
        sort(intervals.begin(), intervals.end());
        int count = 0;
        int prev = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] < prev) {
                count++;
                if(intervals[i][1] < prev) prev = intervals[i][1];
                continue;
            }
            prev = intervals[i][1];
        }

        return count;
    }
};

int main() {
    Solution* sol = new Solution();
    auto start = high_resolution_clock::now();

    vector<vector<int>> vect = {{1,2}, {2,3}, {3,4}, {1,3}};
    // cout << sol->eraseOverlapIntervals(vect) << endl;

    vect = {{0,2}, {1,3}, {2,4}, {3,5}, {4,6}};
    cout << sol->eraseOverlapIntervals(vect) << endl;

    auto elapsed = high_resolution_clock::now() - start;
    long long microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";

    return 0;
}