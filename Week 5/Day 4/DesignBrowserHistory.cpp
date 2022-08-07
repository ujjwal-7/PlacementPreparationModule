class node {
    public:
        string webPage;
        node *next;
        node* prev;
    
        node(string page) {
            webPage = page;
            next = NULL;
            prev = NULL;
        }
    
};

class BrowserHistory {
public:
    node* head, *tail, *cur;
    BrowserHistory(string homepage) {
        
            head = new node(homepage);
            cur = head;
    }
    
    void visit(string url) {
        
        node* temp = new node(url);
        
        cur->next = temp;
        temp->prev = cur;
        cur = temp;
    }
    
    string back(int steps) {
        
        node* temp = cur;
        while(temp->prev != NULL && steps > 0) {
            
            temp = temp->prev;
            steps -= 1;
        }
        cur = temp;
        return temp->webPage;
    }
    
    string forward(int steps) {
        
        node* temp = cur;
        while(temp->next != NULL && steps > 0) {
            
            temp = temp->next;
            steps -= 1;
        }
        cur = temp;
        return temp->webPage;
    }
};
