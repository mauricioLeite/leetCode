#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

#define NEG_INF -0x3F3F3F3F

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;

        if(root == q || root == p) return root;

        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);

        if(l && r) return root;
        else if (r) return r;
        else return l;
    }
}; 

int main() {
    Solution* sol = new Solution();
    auto start = high_resolution_clock::now();

    // Leaf nodes
    TreeNode t1(6);
    TreeNode t2(7);
    TreeNode t3(4);
    TreeNode t4(0);
    TreeNode t5(8);    

    // Left Sub tree
    TreeNode t6(2, &t2, &t3);
    TreeNode t7(5, &t1, &t6);

    // Right Sub tree
    TreeNode t8(1, &t4, &t5);
    
    // Root
    TreeNode t9(3, &t7, &t8);
        
    cout << sol->lowestCommonAncestor(&t9, &t7, &t8) << endl;
    cout << sol->lowestCommonAncestor(&t9, &t7, &t3) << endl;

    auto elapsed = high_resolution_clock::now() - start;
    long long microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";

    return 0;
}