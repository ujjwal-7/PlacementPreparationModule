class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* p = head, *q = head, *temp = NULL;
        
        for(int i = 0; i < n; i++)
            p = p->next;
        
        if(p == NULL) {
            
            temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        
        while(p != NULL) {
            
            p = p->next;
            temp = q;
            q = q->next;
            
        }
        
        temp->next = q->next;
        delete q;
        
        return head;
    }
};