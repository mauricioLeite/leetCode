#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL, *next;
        while(head != NULL) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};

int main() {
    Solution* sol = new Solution();
    auto start = high_resolution_clock::now();
    ListNode t1(1), t2(2), t3(3), t4(4), t5(5);
    
    t1.next = &t2;
    t2.next = &t3;
    t3.next = &t4;
    t4.next = &t5;

    cout << sol->reverseList(&t1) << endl;

    ListNode *aux = &t5;
    while(aux->next != NULL) {
        cout << aux->val << ", ";
        aux = aux->next;
    }
    cout << aux->val << endl;

    
    auto elapsed = high_resolution_clock::now() - start;
    long long microseconds = duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << microseconds << " us to run.\n";
    return 0;
}