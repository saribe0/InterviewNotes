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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        // Deal with empty lists
        if (list1 == nullptr && list2 == nullptr)
            return nullptr;
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;
            
        ListNode* mergedHead;
        ListNode* mergedTail;
        
        // Initialize the merged list
        if (list1->val > list2->val) {
            mergedHead = list2;
            list2 = list2->next;
        }
        else {
            mergedHead = list1;
            list1 = list1->next;
        }
        
        mergedTail = mergedHead;
        
        while (list1 != nullptr && list2 != nullptr) {
            // Attach the next lowest to the merged list
            if (list1->val > list2->val) {
                mergedTail->next = list2;
                mergedTail = list2;
                list2 = list2->next;
            }
            else {
                mergedTail->next = list1;
                mergedTail = list1;
                list1 = list1->next;
            }
        };
        
        
        // Add the other list to the end and return
        if (list1 == nullptr) {
            mergedTail->next = list2;
            return mergedHead;
        }
        else {
            mergedTail->next = list1;
            return mergedHead;
        }
    }
};