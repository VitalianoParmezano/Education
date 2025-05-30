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
    ListNode*rotateRightRecurce(ListNode* head, int k);

int main()
{
    ListNode* head = new ListNode(0);
    ListNode* cursor = head;
    for(int i = 1;i<10;i++){
        cursor->next = new ListNode(i);
        cursor=cursor->next;
    }
    printList(head);
    head = rotateRightRecurce(head, 9);
    //head = rotateRight (head, 2);
    printList(head);
    return 0;
}

ListNode*rotateRightRecurce(ListNode* head, int k){
    if (k <= 0||head->next==nullptr){return head;}
    ListNode* cursor = new ListNode(-1);
    cursor->next = head;
    
    while(cursor->next->next){
    cursor=cursor->next;
    }

    ListNode*temp = cursor->next;
    cursor->next = nullptr;
    temp->next=head;
    return rotateRightRecurce(temp,k-1);

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
