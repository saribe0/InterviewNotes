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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        vector<ListNode*> nodes;
        
        // Convert the linked list to an array
        ListNode* tail = head;
        while (tail) {
            nodes.push_back(tail);
            tail = tail->next;
        }
        
        // Handle the corner case of the first node being deleted
        if (n == nodes.size())
            return head->next;
        
        // Otherwise, we need to update the nodes and return head
        nodes[nodes.size()-n-1]->next = nodes[nodes.size()-n]->next;
        
        return head;
    }
};
