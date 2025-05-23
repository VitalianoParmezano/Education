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
    
    cout<<"What u wonna do?"<<endl<<"1 - add | 2 - delete | 3 - print list"<<endl;
    int choose=0;
    std::cin >> choose;
    int val, pos;
    SWITCH_LINK:
    switch (choose) {
        case 1: 
        cout<<"position and value:"<<endl;
        cin>>pos>>val;
        insert(pos, val, &head);
        break;
        case 2:
        cout<<"position?";
        cin>>pos;
        deletee(pos, &head);
        break;
        case 3:
        cout<<"Here is a list:"<<endl;
    
        while (head.next != nullptr){
        std::cout<<head.val<<std::endl;
        head = *head.next;
        }
        std::cout<<head.val;
        break;
        
        case 4:
        goto EXIT_LINK;
        
        default:
        cout << "one more time!"<<endl;
        break;
    }
    
    goto SWITCH_LINK;
    
    EXIT_LINK:
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
