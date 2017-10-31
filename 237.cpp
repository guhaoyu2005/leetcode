/*
Date: 2016-09-15
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
    void deleteNode(ListNode* node) {
        currNode = node;
        while (true) {
            nextNode = currNode->next;
            currNode->val = nextNode->val;
            if (!nextNode->next) {
                currNode->next = NULL;
                break;
            }
            currNode = nextNode;
        }
    }
private:
    ListNode* nextNode;
    ListNode* currNode;
};
