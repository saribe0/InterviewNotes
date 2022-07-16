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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if (!head || k == 0)
            return head;
        
        ListNode* tail = head;
        ListNode* lastNode = head;
            
        // Count the nodes
        int count = 0;
        while(tail) {
            count++;
            lastNode = tail;
            tail = tail->next;
        }
        
        if (count == 1 || k % count == 0)
            return head;
                
        // Determine the new head node
        // -> this is #nodes - #nodes % k + 1
        int newHeadIndex = count - (k % count) + 1;
        
        // Reset the tail and move to the next head
        ListNode* tailParent = head;
        tail = head;
        count = 1;
        while(tail && count < newHeadIndex) {
            tailParent = tail;
            tail = tail->next;
            count++;
        }
        
        // Tail now points to the new head
        tailParent->next = nullptr;
        lastNode->next = head;
        
        return tail;
    }
};