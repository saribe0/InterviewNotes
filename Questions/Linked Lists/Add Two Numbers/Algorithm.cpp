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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        // Initialize the head of the return list
        int onesDigit = l1->val + l2->val;
        l1 = l1->next;
        l2 = l2->next;
        ListNode* head = new ListNode(onesDigit % 10);
        ListNode* tail = head;
        
        // Keep track of the sum at each digit, seeded w/ the carryover
        int sumAtDigit = onesDigit / 10;
        
        while (l1 || l2 || sumAtDigit > 0) {
            // Determine the sum at the current digit being processed
            if (l1) {
                sumAtDigit += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sumAtDigit += l2->val;
                l2 = l2->next;
            }
            
            // Create the next node in the chain
            tail->next = new ListNode(sumAtDigit % 10);
            tail = tail->next;
            
            // Seed the sum at the next digit with the carryover
            sumAtDigit /= 10;
        }
        
        return head;
    }
};