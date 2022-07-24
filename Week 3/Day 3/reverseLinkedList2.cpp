class Solution {
public:
    
    ListNode* reverse(ListNode* head) {
        
        ListNode* p = head, *q = NULL, *r = NULL;
        
        while(p != NULL) {
            
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
        
        return q;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(head == NULL || head->next == NULL)
            return head;
        
        
        ListNode* p = head, *prev = NULL;
        
        int count = 1;
        
        while(count != left) {
            
            prev = p;
            p = p->next;
            count++;
        }
        
        ListNode* q = p, *temp = NULL;
        
        while(count != right) {
            
            q = q->next;
            count++;   
        }
        
        temp = q->next;
        q->next = NULL;
        
        ListNode* newHead = reverse(p);
        
        if(prev != NULL)
            prev->next = newHead;
        
        q = newHead;
        while(q->next != NULL) {
            q = q->next;
        }
        
        q->next = temp;
        
        if(left == 1)
            return newHead;
        
        return head;
        
    }
};