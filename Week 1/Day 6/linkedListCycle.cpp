class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        
        ListNode *p = head, *q = head;
        
        while(p!=NULL && p->next!=NULL) {
            
            p = p->next->next;
            q = q->next;
            
            if(p == q)
                return true;
        }
        
        return false;
        
    }
};