#include<iostream>

void replace(int* aptr, int* bptr);

int main(){

	int a;
	int b;
	int* aptr = &a;
	int* bptr = &b;

	std::cout<<"Vvedit a"<<std::endl;	
	std::cin>>a;
	std::cout<<"Vvedit b"<<std::endl;
	std::cin>>b;
	
	replace(aptr, bptr);

	std::cout<<"Result:"<<std::endl<<"a = "<<a<<std::endl<<"b = "<<b<<std::endl;

return 0;
}

void replace(int* aptr, int* bptr){
int c = *bptr;

*bptr = *aptr;
*aptr = c;


}
