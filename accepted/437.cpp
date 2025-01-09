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
    int total = 0;
    int pathSum(TreeNode* root, int target) {
        if(!root) return 0;

        addPath(root, target, 0);
        
        pathSum(root->left, target);
        pathSum(root->right, target);

        return total;
    }

    void addPath(TreeNode* p, int target, long sum) {
        if(!p) return;
        sum += p->val;
        
        if(sum == target) total++;
        addPath(p->left, target, sum);
        addPath(p->right, target, sum);
    }
};

int main() {
    Solution* sol = new Solution();
    auto start = high_resolution_clock::now();

    // Leaf nodes
    TreeNode t1(3);
    TreeNode t2(2);
    TreeNode t3(1);
    TreeNode t4(11);

    // Left Sub tree
    TreeNode t5(3, &t1, &t2);    
    TreeNode t6(2, nullptr, &t3);
    TreeNode t7(5, &t5, &t6);

    // Right Sub tree
    TreeNode t8(-3, nullptr, &t4);
    
    // Root
    TreeNode t9(10, &t7, &t8);
        
    cout << sol->pathSum(&t9, 8) << endl;


    auto elapsed = high_resolution_clock::now() - start;
    long long microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";

    return 0;
}