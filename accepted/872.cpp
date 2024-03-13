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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2;
        fillStacks(root1, &v1);
        fillStacks(root2, &v2);
        if(v1 == v2) return true;
        return false;   
    }
private:
    void fillStacks(TreeNode* r, vector<int>* v) {
        if(r != NULL){
            fillStacks(r->left, v);
            fillStacks(r->right, v);
            
            if(r->left == NULL && r->right == NULL) v->push_back(r->val);
        }
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

    cout << sol->leafSimilar(&t1, &t1) << endl;
    
    auto elapsed = high_resolution_clock::now() - start;
    long long microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";
    return 0;
}