class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* temp = head, *p = head->next, *q = NULL;
        
        while(p != NULL) {
            
            if(temp->val == p->val) {
                
                q = p;
                p = p->next;
                temp->next = p;
                delete q;
                q = NULL;
                
            } else {
                
                p = p->next;
                temp = temp->next;
            }
        }
        
        return dummy->next;
    }
};