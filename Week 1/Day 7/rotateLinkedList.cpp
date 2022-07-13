
class Solution {
    
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head == NULL || head->next == NULL || k == 0)
            return head;
        
       ListNode* tail = head;
       int len = 1;
       
        while(tail->next != NULL) {
            
            tail = tail->next;
            len += 1;
            
        }
        
        tail->next = head;
        k = k % len;
        
        int end = len - k;
        while(end > 0) {
            
            tail = tail->next;
            end--;
        }
        
        head = tail->next;
        tail->next = NULL;
        return head;
        
    }
};