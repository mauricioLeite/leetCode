#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Overload ostream out operator to print vector n-dimensional
template <typename S>
ostream& operator<<(ostream& os, const vector<S>& vector){
    os << "[";
    size_t last = vector.size() - 1;
    for(size_t i = 0; i < vector.size(); i++) {
        os << vector[i];
        if(i != last) os << ", ";
    }
    cout << "]";
    return os;
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if(root == nullptr) return 0;

        queue<TreeNode*> q;
        TreeNode* u;
        int level = 1, min_lvl = 1, max_val = -0x3F3F3F3F;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            int sum = 0;
            while(n--){
                u = q.front();
                q.pop();
                sum += u->val;
                if(u->left != nullptr) q.push(u->left);
                if(u->right != nullptr) q.push(u->right);
            }
            if(max_val < sum) {
                max_val = sum;
                min_lvl = level;
            }
            level++;
        }
        return min_lvl;
    }
};

int main() {
    Solution* sol = new Solution();
    auto start = high_resolution_clock::now();

    // Leaf nodes
    TreeNode t1(7);
    TreeNode t2(-8);

    // Left Sub tree
    TreeNode t3(7, &t1, &t2);
    // Right Sub tree
    TreeNode t4(0);
    
    // Root
    TreeNode t5(1, &t3, &t4);
        
    cout << sol->maxLevelSum(&t5) << endl;


    auto elapsed = high_resolution_clock::now() - start;
    long long microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";

    return 0;
}