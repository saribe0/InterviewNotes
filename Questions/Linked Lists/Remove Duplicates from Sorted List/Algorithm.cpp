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
    ListNode* deleteDuplicates(ListNode* head) {
        
        // Keep track of values seen
        unordered_map<int, bool> seenVals;
        
        // Start at the head of the list
        ListNode* tail = head;
        while(tail != nullptr) {
            // Add the value to the list of seen values
            seenVals[tail->val] = true;
            
            // Find the next, valid tail
            ListNode* nextTail = tail->next;
            while (nextTail != nullptr && seenVals.count(nextTail->val)) {
                nextTail = nextTail->next;
            }
            tail->next = nextTail;
            tail = tail->next;
        }
        
        return head;
    }
};