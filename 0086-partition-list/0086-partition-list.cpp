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
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next)
            return head;
        ListNode *smallPrev = NULL;
        ListNode *bigPrev = NULL;
        ListNode *smallCurr = NULL;
        ListNode *bigCurr = NULL;
        ListNode *smallHead=NULL;
        ListNode *bigHead=NULL;
        while(head){
            if(head->val<x){
                if(smallCurr){
                    if(!smallPrev)
                        smallPrev=smallCurr;
                    else{
                        smallPrev->next = smallCurr;
                        smallPrev=smallCurr;
                    }
                    smallCurr=head;
                }
                else{
                    smallCurr=head;
                    smallHead=head;
                }
            }
            else{
                if(bigCurr){
                    if(!bigPrev)
                        bigPrev=bigCurr;
                    else{
                        bigPrev->next = bigCurr;
                        bigPrev=bigCurr;
                    }
                    bigCurr=head;
                }
                else{
                bigCurr=head;
                    bigHead=head;
                }
            }
            head=head->next;
        }
        if(!smallHead)
            return bigHead;
        if(!bigHead){
            return smallHead;
        }
        smallCurr->next=NULL;
        bigCurr->next=NULL;
        if(smallPrev&&smallCurr){
            smallPrev->next=smallCurr;
        }
        if(bigPrev&&bigCurr){
            bigPrev->next=bigCurr;
        }
        
        head=smallHead;
        while(smallHead->next){
            smallHead=smallHead->next;
        }
        smallHead->next=bigHead;
        return head;
    }
};