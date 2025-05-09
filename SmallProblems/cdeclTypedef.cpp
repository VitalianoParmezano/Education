//func takes x, int func(&a)`
#include<iostream>
int plus(int& x);
int minus(int& x);

int(*GetMinusFunc())(int& a){
return minus;}

int main(){
int x = 5;
std::cout<<plus( x)<<std::endl;
int b = 5;
int(*Fptr)(int& a);

Fptr = GetMinusFunc();
Fptr = plus;

b = Fptr(b);

std::cout<<b<<std::endl;

}

int plus(int& x){
return x+1;
}

int minus(int& x){
return x-1;
}
