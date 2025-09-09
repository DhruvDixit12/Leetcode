class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode dummy(0);  // dummy node as new sorted list head
        dummy.next = head;
        ListNode* sorted = head; // last node of sorted part
        ListNode* curr = head->next; // node to be inserted

        while (curr) {
            if (curr->val >= sorted->val) {
                // Already in correct position
                sorted = sorted->next;
            } else {
                // Find position in sorted part
                ListNode* prev = &dummy;
                while (prev->next->val < curr->val) {
                    prev = prev->next;
                }
                // Insert curr between prev and prev->next
                sorted->next = curr->next;
                curr->next = prev->next;
                prev->next = curr;
            }
            curr = sorted->next;
        }
        return dummy.next;
    }
};
