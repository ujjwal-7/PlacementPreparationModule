class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        
        ListNode *fast = head, *slow = head;
        while(fast != NULL && fast->next != NULL) {
            
            fast = fast->next->next;
            slow = slow->next;
            
            if(fast == slow) {
                slow = head;
                while(fast != slow) {
                    fast = fast->next;
                    slow = slow->next;
                }
                return fast;
            }
        }
        return NULL;
    }
};