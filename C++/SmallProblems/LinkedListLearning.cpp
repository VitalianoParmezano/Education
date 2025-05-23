/******************************************************************************

                              Online C++ Debugger.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Debug" button to debug it.

*******************************************************************************/

#include <iostream>
using namespace std;

struct Lisst{
    int val;
    Lisst* next = nullptr;
};

void deletee(int position, Lisst* Head);

void insert(int position, int val, Lisst* ls);


int main()
{
    Lisst head = Lisst();
    Lisst* tail = & head;
    
    tail->val=0;
    
    for(int i = 1;i<8;i++){
        tail->next = new Lisst();
        tail = tail->next;
        tail->val = i;
        
    }
    
    //insert(6,6,&head);
    deletee(5,&head); 
    //std::cout<<head.next->next->val;

    cout<<"Here is a list:"<<endl;
    
        while (head.next != nullptr){
        std::cout<<head.val<<std::endl;
        head = *head.next;
    }
    std::cout<<head.val;
    
   bool running = true;
while (running) {
    cout << "What u wanna do?\n1 - add | 2 - delete | 3 - print list | 4 - exit\n";
    int choose;
    cin >> choose;

    switch (choose) {
        case 1: {
            cout << "Position and value:\n";
            int pos, val;
            cin >> pos >> val;
            insert(pos, val, &head);
            break;
        }
        case 2: {
            cout << "Position?\n";
            int pos;
            cin >> pos;
            deletee(pos, &head);
            break;
        }
        case 3: {
            cout << "Here is a list:\n";
            Lisst* temp = &head;
            while (temp != nullptr) {
                cout << temp->val << endl;
                temp = temp->next;
            }
            break;
        }
        case 4:
            running = false;
            break;
        default:
            cout << "Try again!\n";
    }
}

    return 0;
}

void deletee(int position, Lisst* Head){
    
    Lisst* cursor = Head;  
    
    for(int i = 0; i < position-1; i++){
       cursor=cursor->next; 
    }
    cursor->next=cursor->next->next;
}

void insert(int position, int value, Lisst* ls) {
    
    Lisst* newvalue = new Lisst();
    newvalue->val=value;

    Lisst* nextNext;
    
    Lisst* cursor = ls;

    for (int i = 0; i < position-1; i++) {
        cursor = cursor->next;
    }
    nextNext = cursor->next;
    
    newvalue->next = nextNext;
        
    cursor->next= newvalue;   
    
    

    //cursor->val = value;
}
