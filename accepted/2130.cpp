#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int pairSum(ListNode* head) {
        int maxVal = 0;
        ListNode *s = head, *f = head;

        while(f->next->next){
            s = s->next;
            f = f->next->next;
        }
        
        ListNode* rev = reverse(s->next);

        while(rev){
            maxVal = max(maxVal, head->val + rev->val);
            head = head->next;
            rev = rev->next;
        }

        return maxVal;
    }

    ListNode* reverse(ListNode* node) {
        ListNode *next = node, *curr=nullptr, *prev=nullptr;
        while(next != nullptr) {
            curr = next;
            next = next->next;
            curr->next = prev;
            prev = curr;
        }
        return prev;
    }
};

int main() {
    Solution* sol = new Solution();
    auto start = high_resolution_clock::now();

    ListNode n1(1);
    ListNode n2(2, &n1);
    ListNode n3(4, &n2);
    ListNode n4(5, &n3);
    cout << sol->pairSum(&n4) << endl;

    auto elapsed = high_resolution_clock::now() - start;
    long long microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";

    return 0;
}