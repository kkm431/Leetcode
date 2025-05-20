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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        // if at end k element unavailable than return pointer from there
        ListNode* currCheck = head;
    
        for(int i = 0; i < k; i++)
        {
            if(currCheck == NULL)
                return head;

            currCheck = currCheck->next;
        }
        
        // reverse k grp element in linked list
        ListNode* curr= head;
        ListNode* prev= NULL;
        ListNode* temp= NULL;
        int count = 0;
        while(curr != NULL && count<k)
        {
            temp = curr->next;
            curr->next = prev;
            prev= curr;
            curr= temp;
            count++;
        }
        
        // make conncection between k reverse grps
        if(temp!= NULL)
            head->next = reverseKGroup(temp,k);
        
        // return prev
        return prev;
    }
};