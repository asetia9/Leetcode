class Node{
    public:
    int key,val;
    Node *next;
    Node *prev;
    Node(int key, int val, Node *prev, Node *next){
        this->key=key;
        this->val=val;
        this->prev=prev;
        this->next=next;
    }
    
};
class LRUCache {
public:
    int n;
    unordered_map<int,Node *> m;
    Node *first = NULL;
    Node *last = NULL;
    LRUCache(int capacity) {
        n=capacity;
    }
    void print(Node *nh){
        while(nh){
            cout<<nh->val<<endl;
            nh=nh->next;
        }
    }
    int get(int key) {
        if(m.find(key)!=m.end()){
            if(first==m[key]){
                return first->val;
            }
            else if(m[key]==last){
                m[key]->prev->next=NULL;
                last=m[key]->prev;
                m[key]->prev=NULL;
                m[key]->next=first;
                first->prev=m[key];
                first=m[key];
                // print(first);
                return first->val;
            }
            m[key]->prev->next = m[key]->next;
            m[key]->next->prev = m[key]->prev;
            m[key]->next = first;
            first->prev=m[key];
            m[key]->prev=NULL;
            first=m[key];
            return first->val;
            
        }
        return -1;
    }
   
    void put(int key, int value) {
        // print(first);
        if(m.find(key)!=m.end()){
            if(first==last ||  m[key]==first){
                m[key]->val=value;
                return;
            }
            else if(m[key]==last){
                m[key]->prev->next=NULL;
                last=m[key]->prev;
                m[key]->next=first;
                first->prev=m[key];
                m[key]->prev=NULL;
                first=m[key];
                m[key]->val=value;
                
                return;
            }
            m[key]->prev->next = m[key]->next;
            m[key]->next->prev = m[key]->prev;
            m[key]->next = first;
            m[key]->prev = NULL;
            first->prev = m[key];
            first = m[key];
            first->val=value;
        }
        else{
            if(m.size()<n){
                if(!first){
                    first = last = new Node(key,value,NULL,NULL);
                    m[key]=first;
                    return;
                }
                else{
                    Node *new_node = new Node(key,value,NULL,first);
                    first->prev = new_node;
                    first = new_node;
                    m[key]=first;
                    return;
                }
            }
            else{
                if(first==last){
                    m.erase(first->key);
                    first = last = new Node(key,value,NULL,NULL);
                    m[key]=first;
                    return;
                }
                else{
                    m.erase(last->key);
                    last->prev->next=NULL;
                    last=last->prev;
                    Node *new_node = new Node(key,value,NULL,first);
                    first->prev = new_node;
                    first = new_node;
                    m[key]=first;
                    // print(first);
                }
                
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */