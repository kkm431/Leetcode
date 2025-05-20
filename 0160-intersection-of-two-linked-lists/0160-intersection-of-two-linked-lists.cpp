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
        unordered_map<ListNode *, int> intersectionNode;
        for(auto node= headA; node!= NULL; node=node->next)
        {
            intersectionNode[node]= node->val;
        }

        for(auto node= headB; node!= NULL; node=node->next)
        {
            if(intersectionNode.find(node) != intersectionNode.end())
                return node;
        }
        return NULL;
    }
};