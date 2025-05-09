//func takes x, int func(&a)`
#include<iostream>
int plus(int& x);
int minus(int& x);

int(*GetSomeFunc(bool M))(int&){
if (M){
return minus;}
return plus;
}

int main(){

int b = 10;
int(*Fptr)(int& x);
Fptr = plus;

Fptr = GetSomeFunc(0);
int a = Fptr(b);


std::cout<<a<<std::endl;



}
int plus(int& x){
return x+1;
}

int minus(int& x){
return x-1;
}
