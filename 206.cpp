/*
Date:2016-09-19
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
    ListNode* reverseList(ListNode* head) {
        ListNode* curr= head;
        ListNode* origOld=NULL;
        ListNode* old=NULL;
        if (!head)
            return NULL;
        while (curr != NULL) {
            ListNode *nn = new ListNode(curr->val);
            nn->next = old;
            old = nn;
            origOld = curr;
            curr = curr->next;
            delete origOld;
        }
        return old;
    }
};
