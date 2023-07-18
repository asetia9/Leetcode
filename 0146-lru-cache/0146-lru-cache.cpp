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
    void removeFromMiddleAndAddToFirst(int key){
        m[key]->prev->next = m[key]->next;
        m[key]->next->prev = m[key]->prev;
        m[key]->next = first;
        m[key]->prev = NULL;
        first->prev = m[key];
        first = m[key];
    }
    void removeFromLastAndAddToFirst(int key){
        m[key]->prev->next=NULL;
        last=m[key]->prev;
        m[key]->next=first;
        first->prev=m[key];
        m[key]->prev=NULL;
        first=m[key];
    }
    void addExisitingNodeToFirst(int key){
         if(first==last ||  m[key]==first){
                return;
            }
            else if(m[key]==last){
                removeFromLastAndAddToFirst(key);
                return;
            }
            removeFromMiddleAndAddToFirst(key);
            
    }
    int get(int key) {
        if(m.find(key)!=m.end()){
            addExisitingNodeToFirst(key);
            return first->val;
        }
        return -1;
    }
    void makeItFirst(int key, int value){
        first = last = new Node(key,value,NULL,NULL);
        m[key]=first;
    }
    void makeNewNodeAndAddToFirst(int key, int value){
        Node *new_node = new Node(key,value,NULL,first);
        first->prev = new_node;
        first = new_node;
        m[key]=first;
    }
    void put(int key, int value) {
        
        if(m.find(key)!=m.end()){
            
           addExisitingNodeToFirst(key);
           first->val=value; 
            
        }
        else{
            if(m.size()<n){
                
                if(!first){
                    makeItFirst(key,value);
                    return;
                }
                else{
                    makeNewNodeAndAddToFirst(key,value);
                    return;
                }
            }
            else{
                if(first==last){
                    m.erase(first->key);
                    makeItFirst(key,value);
                    return;
                }
                else{
                    m.erase(last->key);
                    last->prev->next=NULL;
                    last=last->prev;
                    makeNewNodeAndAddToFirst(key,value);
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