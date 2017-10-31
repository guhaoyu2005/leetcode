/*
Date: 2016-09-28
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2)
            return NULL;
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        ListNode* newList;
        ListNode* curr = new ListNode(l1->val>l2->val?l2->val:l1->val);
        newList = curr;
        ListNode* currL1;
        ListNode* currL2;
        if (l1->val>l2->val) {
            currL2 = l2->next;
            currL1 = l1;
            delete l2;
        }
        else {
            currL1 = l1->next;
            currL2 = l2;
            delete l1;
        }
        while (currL1 || currL2) {
            if (currL1 && currL2) {
                if (currL1->val>currL2->val) {
                    curr->next = new ListNode(currL2->val);
                    ListNode* t=currL2->next;
                    delete currL2;
                    currL2 = t;
                }
                else {
                    curr->next = new ListNode(currL1->val);
                    ListNode* t=currL1->next;
                    delete currL1;
                    currL1 = t;
                }
            }
            else if (!currL1) {
                curr->next = new ListNode(currL2->val);
                ListNode* t=currL2->next;
                delete currL2;
                currL2 = t;
            }
            else if (!currL2) {
                curr->next = new ListNode(currL1->val);
                ListNode* t=currL1->next;
                delete currL1;
                currL1 = t;
            }
            curr=curr->next;
        }
        return newList;
    }
};
