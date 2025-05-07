#include<iostream>
#include<vector>
#include "drawer.h"
#include "structures.h"

std::vector<Vidrizok> vectorArray;







//bool isPeretunForTriangle(Triangle* t1,Triangle* t2){
 //
//	bool check = isPeretun(&(t1->v1),&(t2->v2));
	
	
//return check;

//}

int main(){

int a,b,c,d;

//	std::cout<<"Alfa:"<<std::endl;
//	std::cin>>a;std::cin>>b;std::cin>>c;std::cin>>d;
//	Vidrizok alfa(a,b,c,d);
//
//	std::cout<<"Bravo:"<<std::endl;
//	std::cin>>a;std::cin>>b;std::cin>>c;std::cin>>d;
//	Vidrizok bravo(a,b,c,d);
//
//	int s = PsevdoScalyar(&alfa, &bravo);
//	bool r = ProectCheck(&alfa, &bravo); 
//	std::cout<<r<<std::endl;
//
//	std::cout<<"Skalyar: "<<s<<std::endl;
//	std::cout<<"Alfa points: "<<alfa.vectorPoint[0]<<alfa.vectorPoint[1]<<std::endl;
//	std::cout<<"Bravo points: "<<bravo.vectorPoint[0]<<bravo.vectorPoint[1]<<std::endl;
//	std::cout<<-2*3<<std::endl<<std::endl<<std::endl;
//	std::cout<<"PeretunVidrizkiv: "<<isPeretun(&alfa,&bravo)<<std::endl;

Triangle tr1(5,1,7,4,9,1);
Triangle tr2(5,4,7,9,9,4);
std::cout<<isPeretun(&tr1,&tr2)<<std::endl;

drawLine(&vectorArray);

return 0;
}


