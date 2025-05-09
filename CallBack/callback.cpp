#include<iostream>

void applyToArray(int* arr,int size, int (*callbacFunc)(int&));

int doubleN (int& a){
return a*2;
}

int addThree(int& a){
return a+3;
}
int makeMinus(int& a){
return a*-1;
}
int printArray(int&a){
std::cout<<a<<std::endl;
return a;
}

int main (){

int numbers[]={1,2,3,4,5};
int size = sizeof(numbers)/sizeof(numbers[0]);
applyToArray(numbers,size,printArray);
applyToArray(numbers ,size, doubleN);
applyToArray(numbers,size,printArray);

applyToArray(numbers,size,makeMinus);
std::cout<<"Minus aaray:"<<std::endl;
applyToArray(numbers,size,printArray);
return 0;
}


void applyToArray(int* arr,int size, int (*callbacFunc)(int&)){
	std::cout<<std::endl;
	for(int i=0;i<size;i++){
	arr[i]=callbacFunc(arr[i]);
	}
}
