#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int, pair<int,int>> mp;
        int m = mat.size(), n = mat[0].size();
        for(int i = 0; i < m; i++) 
            for(int j = 0; j < n; j++)
                mp[mat[i][j]] = {i,j};
        
        int s = arr.size();
        vector<int> freq(m+n, 0);
        for(int i = 0; i < s; i++){
            auto& [r, c] = mp[arr[i]];
            freq[r]++;
            freq[m+c]++;
            if(freq[r] == n || freq[m+c] == m) return i;
        }

        return s;
    }
};

int main() {
    Solution* sol = new Solution();
    auto start = high_resolution_clock::now();

    vector<int> arr{2,8,7,4,1,3,5,6,9};
    vector<vector<int>> mat{{3,2,5},{1,4,6},{8,7,9}};
    cout << sol->firstCompleteIndex(arr, mat) << endl;

    auto elapsed = high_resolution_clock::now() - start;
    long long microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";

    return 0;
}