class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      

        
        ListNode* p = headA, *q= headB;
        
        if(p == NULL || q == NULL)
            return NULL;
        
        while(p != NULL && q!= NULL && p!=q) {
            
            p = p->next;
            q = q->next;
            
            if(p == q)
                return p;
            
            if(p == NULL)
                p = headB;
            
            if(q == NULL)
                q = headA;
                
        }
        
        return p;
    }
};