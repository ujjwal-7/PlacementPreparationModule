class Solution {
public:
    
    ListNode* findMid(ListNode* head) {
        
        ListNode* p =head, *q = head;
        
        while(p && p->next) {
            
            p = p->next->next;
            q = q->next;
            
        }
        return q;
        
    }
    
    ListNode* reverse(ListNode* head) {
        ListNode* curr = head, *prev = NULL, *temp = NULL;
        
        while(curr != NULL){
            
            temp = prev;
            prev = curr;
            curr = curr->next;
            prev->next = temp;
        }
        return prev;
    } 
    
    bool compareList(ListNode* p, ListNode* q) {
        
        while(p && q) {
            
            if(p->val != q->val)
                return false;
            
            p = p->next;
            q = q->next;
        }
        
        return true;
    }
    bool isPalindrome(ListNode* head) {
        
        ListNode* p = head, *q = head;
        
        ListNode *mid = findMid(head);
        ListNode* h = reverse(mid);
        return compareList(head, h);
    }
};