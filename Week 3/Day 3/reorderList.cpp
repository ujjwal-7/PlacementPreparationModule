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
    
    void reorderList(ListNode* head) {
        
        if(head == NULL || head->next == NULL)
            return;
        
        ListNode* p = head, *q = head;
        
        while(p != NULL && p->next != NULL) {
            
            p = p->next->next;
            q = q->next;
        }
        
        ListNode* head1 = head;
        ListNode* head2 = q->next;
        q->next = NULL;
        
        head2 = reverse(head2);
        
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        
        while(head1 || head2) {
            
            if(head1) {
                cur->next = head1;
                cur = cur->next;
                head1 = head1->next;
            }
            
            if(head2) {
                cur->next = head2;
                cur = cur->next;
                head2 = head2->next;
            }
        }
        
        head = dummy->next;
        delete dummy;
        
       
    }
};