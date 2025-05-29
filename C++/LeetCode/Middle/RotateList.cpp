#include <iostream>

 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
  
    ListNode* rotateRight(ListNode* head, int k);
    void printList(ListNode* head);

int main()
{
    ListNode* head = new ListNode(0);
    ListNode* cursor = head;
    for(int i = 1;i<4;i++){
        cursor->next = new ListNode(i);
        cursor=cursor->next;
    }
    printList(head);
    head = rotateRight (head, 2);
    printList(head);
    return 0;
}

ListNode* rotateRight(ListNode* head, int k) {
        ListNode* cursor = head;
        int counter = 0;

        while (cursor->next){
            counter++;
            cursor = cursor->next;
        }
        counter -= k;

        cursor = head;
        for(int i = 0; i<counter; i++){
            cursor = cursor->next;
        }

        ListNode* tail = cursor->next;
        ListNode* NewHead = cursor->next;
        cursor->next=nullptr; 

        while(tail->next){
            tail=tail->next;
        } 
        tail->next=head;

        return NewHead;
}
       

void printList(ListNode* head){
    ListNode* cursor = head;
    
    while(cursor){
        std::cout<<"\t"<<cursor->val<<std::endl;
        cursor=cursor->next;
    }
    std::cout<<std::endl;
}
