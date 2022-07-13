class Solution {
public:
    
    void reverse(ListNode* start, ListNode* end) {
        
        ListNode* p = start, *q = NULL, *r = NULL, *temp = end->next;
        
        while(p != temp) {
            
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
        
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        
       if(head == NULL || head->next == NULL || k == 1)
           return head;
      
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* beforeStart = dummy, *end = head;
        int count = 0;
        
        while(end != NULL) {
            
            count++;
            if(count % k == 0) {
                
                ListNode* start = beforeStart->next, *temp = end->next;
                reverse(start, end);
                beforeStart->next = end;
                start->next = temp;
                beforeStart = start;
                end = temp;
                
            } else {
                
                end = end->next;
                
            }
        }
        
        return dummy->next;
      
    }
};