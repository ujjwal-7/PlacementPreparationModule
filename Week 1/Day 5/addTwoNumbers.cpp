class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* head = NULL, *prev = NULL;
        int carry = 0;
        
        while(l1 != NULL || l2 != NULL) {
            
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;
            
            int sum = val1 + val2 + carry;
            carry = sum / 10;
            int value = sum % 10;
            
            if(head == NULL) {
                
                head = new ListNode(value);
                prev = head;
                
            } else {
                
                prev->next = new ListNode(value);
                prev = prev->next; 
            }
            
            if(l1)
                l1 = l1->next;
            
            if(l2)
                l2 = l2->next;
        }
        
        if(carry) {
            
            prev->next = new ListNode(carry);
        }
        
        return head;
    }
};