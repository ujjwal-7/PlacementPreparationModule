class Solution {
public:
    
    void merge(ListNode* p, ListNode* l1, ListNode* l2) {
        
        while(l1!=NULL && l2!=NULL) {
            
            if(l1->val <= l2->val) {
                
                p->next = l1;
                p=p->next;
                l1=l1->next;
            }
            
            else if(l1->val > l2->val) {
                
                p->next= l2;
                p=p->next;
                l2=l2->next;
            }
        }
        
        while(l1!=NULL) {
            p->next = l1;
            p=p->next;
            l1=l1->next;
        }
        
        while(l2!=NULL) {
            p->next= l2;
            p=p->next;
            l2=l2->next;
        }
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode* dummy = new ListNode(-1);
        ListNode* p = dummy;
        
        merge(p, l1, l2);
        
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};