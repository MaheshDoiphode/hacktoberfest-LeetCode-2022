/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        ListNode* pointer = head;
        while(pointer != NULL && pointer->next != NULL)
        {
            if(pointer->val == pointer->next->val)
            {
                pointer->next = pointer->next->next; //if the val of current node is equals to the val of next node then skip the node
            }
            else
            {
                pointer = pointer->next;
            }
        }
        return head;
    }
};