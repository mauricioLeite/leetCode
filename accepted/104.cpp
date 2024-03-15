#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

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
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return 1 + max(left, right);
    }
};

int main() {
    Solution* sol = new Solution();
    auto start = high_resolution_clock::now();
    TreeNode t5(5);
    TreeNode t4(4);
    TreeNode t3(3, &t4, &t5);
    TreeNode t2(2);
    TreeNode t1(1, &t2, &t3);

    cout << sol->maxDepth(&t1) << endl;
    
    auto elapsed = high_resolution_clock::now() - start;
    long long microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";
    return 0;
}