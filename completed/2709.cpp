#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

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
    // DSU structure
    int parent[100001], size[100001];

    void make(int v) {
        parent[v] = v;
        size[v] = 1;
    }

    void union_sets(int v1, int v2) {
        v1 = find(v1);
        v2 = find(v2);
        if(v1 == v2) return;

        if(size[v1] < size[v2]) swap(v1, v2);
        parent[v2] = v1;
        size[v1] += size[v2];
    }

    int find(int v) {
        if(parent[v] == v) return v;
        return parent[v] =  find(parent[v]);
    }

    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return true;
        
        // Initialize DSU
        memset(parent, 0, sizeof(int) * n);
        memset(size, 0, sizeof(int) * n);
        for(int i = 0; i < n; i++) make(i);

        // Mapping first index for each prime factors
        unordered_map<int, int> prime_group;
        
        // Iterate to find common prime factors and execute Union
        for(int i = 0; i < n; i++) {
            int n = nums[i];
            if(n == 1) return false;

            // Iterate through prime factors of x
            for(int j = 2; j*j <= n; ++j) {
                if(n % j == 0) {
                    // Merge sets if factors is encountered before
                    if(prime_group.count(j)){
                        union_sets(i, prime_group[j]);
                    } else {
                        // Store the index for this prime
                        prime_group[j] = i;
                    }
                    
                    while(n % j == 0) {
                        n /= j;
                    }
                }
            }

            // Handle for prime numbers
            if(n > 1) {
                if(prime_group.count(n)){
                    union_sets(i, prime_group[n]);
                } else {
                    prime_group[n] = i;
                }
            }
        }

        // All elements need to belong to the same connected 
        return (size[find(0)] == n);
    }
};

int main() {
    Solution* sol = new Solution();
    auto start = high_resolution_clock::now();
    vector<int> vect{4,3,12,8};

    cout << sol->canTraverseAllPairs(vect) << endl;
    
    auto elapsed = high_resolution_clock::now() - start;
    long long microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";
    return 0;
}