/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return NULL;
        Node *HEAD=head;
        while(HEAD){
            Node *next=HEAD->next;
            HEAD->next = new Node(HEAD->val);
            HEAD->next->next=next;
            HEAD=next;
        }
        HEAD=head;
        Node *ans=head->next;
        while(HEAD){
            if(HEAD->random)
                HEAD->next->random= HEAD->random->next;
           
            HEAD=HEAD->next->next;
        }
        HEAD=head;
        ans=HEAD->next;
        while(HEAD){
            Node *NEXT=HEAD->next->next;
            if(NEXT){
                HEAD->next->next=NEXT->next;
                HEAD->next=NEXT;
                HEAD=NEXT;
            }
            else{
                HEAD->next=NULL;
                break;
            }
        }
        
        return ans;
    }
};