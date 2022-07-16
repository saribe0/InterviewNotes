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
    ListNode* swapPairs(ListNode* head) {
        
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* tail = dummyHead;
        
        // Switch all even nodes w/ odd ones
        while (tail && tail->next && tail->next->next) {
        
            // Save the next two nodes
            ListNode* swapLeft = tail->next;
            ListNode* swapRight = tail->next->next;
            ListNode* nextHead = tail->next->next->next;
            
            // Swap the nodes
            swapLeft->next = nextHead;
            swapRight->next = swapLeft;
            tail->next = swapRight;
            
            // Update the tail to the next head
            tail = tail->next->next;
        }
        
        return dummyHead->next;
    }
};