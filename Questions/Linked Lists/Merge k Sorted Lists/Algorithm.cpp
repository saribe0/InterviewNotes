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

private:
    ListNode* merge2Lists(ListNode* head1, ListNode* head2) {
        
        ListNode* dummyHead = new ListNode();
        ListNode* tail = dummyHead;
        
        while (head1 && head2) {
            if (head1->val < head2->val) {
                tail->next = head1;
                head1 = head1->next;
            }
            else {
                tail->next = head2;
                head2 = head2->next;
            }
            tail = tail->next;
        }
        if (head1) {
            tail->next = head1;
        }
        else if (head2) {
            tail->next = head2;
        }
        
        return dummyHead->next;
    }
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if (lists.size() == 0)
            return nullptr;
        if (lists.size() == 1)
            return lists[0];
        
        ListNode* dummyHead = lists[0];
        
        int node = 1;
        while (node < lists.size()) {
            dummyHead = merge2Lists(dummyHead, lists[node]);
            node++;
        }
        
        return dummyHead;
    }
};