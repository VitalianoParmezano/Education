#include <iostream>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

    void PrintList(ListNode* head);
    ListNode* reverseBetween(ListNode* head, int left, int right);
                
int main(){
    ListNode* head = new ListNode();
    ListNode* cursor = head;
    for (int i = 1; i <= 5; i++){
    
        cursor->next = new ListNode(i);
        cursor = cursor->next;        
    }
    PrintList(head);
    reverseBetween(head, 2, 4);
    PrintList(head);
return 0;
}

    ListNode* reverseBetween(ListNode* head, int left, int right) {

        ListNode* dump = new ListNode(-1, head);

        ListNode* Last = dump;
        ListNode* Current = head;  

        ListNode* StartReverse = nullptr;
        ListNode* EndReverse = nullptr;

        int counter = 0;
        while (Current){
            ListNode* nextNode = nullptr;
            if (counter == left){
                StartReverse = Last;
                EndReverse = Current;
            }
            if (counter>left && counter <=right){
               nextNode = Current->next;
               Current->next = Last;
               Last = Current;
               Current = nextNode;

               counter++;
               continue;
            }

            if (counter>right){
            StartReverse->next = Last;
            EndReverse-> next = Current;
            break;
            }

            counter ++;
            Last=Current;
            Current=Current->next;
            

        }
        return head;

    }

            void PrintList(ListNode* head){
            cout << "Here is a list:\n";
            ListNode* temp = head;
            while (temp != nullptr) {
                cout <<"\t" << temp->val << endl;
                temp = temp->next;
            }
            }
