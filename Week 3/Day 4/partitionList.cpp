class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* less = new ListNode(-1);
        ListNode* greater = new ListNode(-1);
        
        ListNode *lessTail = less, *greaterTail = greater;
        ListNode* cur = head;
        
        while(cur != NULL) {
            
            if(cur->val < x) {
                
                lessTail->next = cur;
                lessTail = lessTail->next;
                
                
            } else {
                
                greaterTail->next = cur;
                greaterTail = greaterTail->next;
                
            }
            
            cur = cur->next;
        }
        
        lessTail->next = greater->next;
        greaterTail->next = NULL;
        return less->next;
    }
};