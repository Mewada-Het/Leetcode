/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* current1 = headA;
        ListNode* current2 = headB;

        while (current1 != current2) {
            current1 = (current1 == nullptr) ? headB : current1->next;
            current2 = (current2 == nullptr) ? headA : current2->next;
        }
        return current1;
    }
};