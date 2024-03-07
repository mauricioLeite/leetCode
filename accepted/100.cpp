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

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (p && q && p->val == q->val) return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        return false;
    }
};

int main() {
    Solution* sol = new Solution();
    auto start = high_resolution_clock::now();
    TreeNode t2(2);
    TreeNode t3(3);
    TreeNode t4(4);
    TreeNode t1(1, &t2, 0);
    TreeNode t5(1, 0, &t2);

    cout << sol->isSameTree(&t1, &t1) << endl;
    
    auto elapsed = high_resolution_clock::now() - start;
    long long microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";
    return 0;
}