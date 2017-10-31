/*
Date: 2016-09-27
*/
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        if (!curr)
            return NULL;
        while (curr->next) {
            if (curr->val == curr->next->val) {
                ListNode *ln = curr->next;
                curr->next = curr->next->next;
                delete ln;
            }
            else {
                curr= curr->next;
            }
        }
        return head;
    }
};
