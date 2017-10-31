/*
Date: 2016-09-14
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <stdlib.h>
#include <time.h>
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    ListNode *list;
    Solution(ListNode* head) {
        list= head;
    }

    /** Returns a random node's value. */
    int getRandom() {
        ListNode *l = list;
        int r=l->val;
        int count=1;
        while (l) {
            if (rand()%(count++)==0)
                r = l->val;
            l= l->next;
        }
        return r;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
