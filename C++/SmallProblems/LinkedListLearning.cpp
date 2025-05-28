#include <iostream>
using namespace std;

struct Lisst{
    int val;
    Lisst* next = nullptr;
};

Lisst* reverse (Lisst* ls);
void deletee(int position, Lisst* Head);
int lenght_of_list(Lisst* Head);
void insert(int position, int val, Lisst* ls);


int main()
{
    Lisst* head =new Lisst();
    Lisst* tail =  head;
    
    tail->val=0;
    
    for(int i = 1;i<5;i++){
        tail->next = new Lisst();
        tail = tail->next;
        tail->val = i;
        
    }
            cout << "Here is a list:\n";
            Lisst* temp = head;
            while (temp != nullptr) {
                cout << temp->val << endl;
                temp = temp->next;
            }
    
   bool running = true;

while (running) {
    cout << "What u wanna do?\n1 - add | 2 - delete | 3 - print list | 4 - exit | 5 - lenght | 6 - reverse \n";
    int choose;
    cin >> choose;

    switch (choose) {
        case 1: {
            cout << "Position and value:\n";
            int pos, val;
            cin >> pos >> val;
            insert(pos, val, head);
            break;
        }
        case 2: {
            cout << "Position?\n";
            int pos;
            cin >> pos;
            deletee(pos, head);
            break;
        }
        case 3: {
            cout << "Here is a list:\n";
            Lisst* temp = head;
            while (temp != nullptr) {
                cout <<"\t" << temp->val << endl;
                temp = temp->next;
            }
            break;
        }
        case 4:
            running = false;
            break;
        case 5:
            cout<<"Lenght: "<<lenght_of_list(head)<<endl;
            break;
        case 6:
            cout<<"Reverse! "<<std::endl;
            head = reverse(head);

            break;

    //    default:
         //   cout << "Try again!\n";
       //     break;
    }
}

    return 0;
}

int lenght_of_list(Lisst* Head){
    int counter = 1;
    Lisst* cursor = Head;
    while(cursor->next!=nullptr){
        cursor=cursor->next;
        counter++;
    }
    return counter;
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
        if(cursor->next==nullptr){
           cursor->next=new Lisst();
        }
        cursor = cursor->next;
    }
    nextNext = cursor->next;
    
    newvalue->next = nextNext;
        
    cursor->next= newvalue;   
    
    

    //cursor->val = value;
}
Lisst* reverse (Lisst* ls){
    Lisst* lastNode = nullptr;
    Lisst* curr = ls;
    Lisst* next = nullptr;
        while(curr!=nullptr){
            next = curr->next;
            curr->next = lastNode;
            lastNode = curr;
            curr = next;
        }
        return lastNode;
}







