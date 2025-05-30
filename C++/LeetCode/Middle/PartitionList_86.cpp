#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* partition(ListNode* head, int x);

    int main(){
        ListNode* head = new ListNode();
        ListNode* cursor = head;
        for (int i = 1; i<5; i++){
           cursor->next = new ListNode(i); 
        }
        head =  partition(head, 2);

        return 0;
    }


ListNode* partition(ListNode* head, int x){
 ListNode* smaller = new ListNode(-1);
        ListNode* smallercur = smaller;
        ListNode* bigger = new ListNode(-1);
        ListNode* biggercur = bigger;
        ListNode* cursor = head;
        while(cursor){
            if(cursor->val<x){
                smallercur->next=cursor;
                smallercur = smallercur->next;
            }else{
                biggercur->next=cursor;
                biggercur = biggercur->next;
            }
            cursor = cursor->next;
        }
        smallercur->next=bigger->next;
        biggercur->next = nullptr;
        return smaller->next;
    }
