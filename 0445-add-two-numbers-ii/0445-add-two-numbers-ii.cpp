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
    stack<int> makeStack(ListNode *l1){
        stack<int> st1;
        while(l1){
            st1.push(l1->val);
            l1=l1->next;
        }
        return st1;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1;
        stack<int> st2;
        st1 = makeStack(l1);
        st2 = makeStack(l2);
        int carry=0;
        ListNode *nh = new ListNode(-1);
        int value;
        stack<int> output;
        ListNode *temp=nh;
        while(st1.size()||st2.size()){
            if(!st2.size()){
                value = st1.top()+carry;
                st1.pop();
            }
            else if(!st1.size()){
                value = st2.top()+carry;
                st2.pop();
            }
            else if(st1.size()&&st2.size()){
                value = st1.top()+st2.top()+carry;
                st1.pop();
                st2.pop();
            }
            carry=value/10;
            output.push(value%10);
        }
        if(carry){
            output.push(carry);
        }
        while(output.size()){
            nh->val=output.top();
            output.pop();
            nh->next = new ListNode(-1);
            nh=nh->next;
        }
        ListNode *t=temp;
        while(t->next->val!=-1){
            t=t->next;
        }
        t->next=NULL;
        
        return temp;
        
    }
};