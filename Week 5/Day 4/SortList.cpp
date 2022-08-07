/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeList(ListNode* p, ListNode* q) {
        
        ListNode* dummy = new ListNode(-1);
        ListNode* tempHead = dummy;
        
        while(p != NULL && q != NULL) {
            
            if(p->val <= q->val) {
                tempHead->next = p;
                p = p->next;
            } else {
                tempHead->next = q;
                q = q->next;
            }
            tempHead = tempHead->next;
        }
        
        if(p == NULL) {
            tempHead->next = q;
        }
        
        if(q == NULL) {
            tempHead->next = p;
        }
        return dummy->next;
    }
    
    ListNode* sortList(ListNode* head) {
        
        if(head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode* p = head, *q = head, *temp = NULL;
        while(p != NULL && p->next != NULL) {
            temp = q;
            p = p->next->next;
            q = q->next;
        }
        
        temp->next = NULL;
        
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(q);
        
        head = mergeList(l1, l2);
        return head;
    }
};