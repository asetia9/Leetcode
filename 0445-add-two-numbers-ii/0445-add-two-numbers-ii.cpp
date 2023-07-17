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
    ListNode *reverse(ListNode *head){
        ListNode *curr=head;
        ListNode *prev=NULL;
        while(curr){
            ListNode *next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    void add(ListNode *l1, ListNode *l2, int carry, ListNode *nhead){
        if(!l1&&!l2){
            if(carry){
                nhead->val=carry;
                nhead->next=new ListNode(-1);
                nhead=nhead->next;
            }
            return;
        }
        else if(!l1){
            nhead->val = (l2->val +carry)%10;
            carry = (l2->val+carry)/10;
            nhead->next = new ListNode(-1);
            nhead=nhead->next;
            add(l1,l2->next,carry,nhead); 
        }
        else if(!l2){
            nhead->val = (l1->val+carry)%10;
            carry = (l1->val+carry)/10;
            nhead->next = new ListNode(-1);
            nhead=nhead->next;
            add(l1->next,l2,carry,nhead);
        }
        else{
            nhead->val = (l1->val+l2->val +carry)%10;
            carry = (l1->val+l2->val+carry)/10;
            nhead->next = new ListNode(-1);
            nhead=nhead->next;
            add(l1->next,l2->next,carry,nhead);
        }
        
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverse(l1);
        // return l1;
        l2=reverse(l2);
        // return l2;
        ListNode *nhead = new ListNode(-1);
        
        add(l1,l2,0,nhead);
        // cout<<nhead->next->val<<endl;
        
        return reverse(nhead)->next;
    }
};