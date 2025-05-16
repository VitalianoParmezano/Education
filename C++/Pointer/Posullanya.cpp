#include<iostream>

void addFive(int& a){
a +=5;
}


int main(){

	int a;
	int& avk = a;
	std::cout<<"Vvedit chuslo"<<std::endl;
	std::cin>>a;
	addFive(avk);
	std::cout<<"Result: avk = "<<avk<<std::endl;
	std::cout<<"Result a: "<<a<<std::endl;
	

return 0;
}

