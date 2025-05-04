#include<iostream>
#include "drawer.h"
#include<vector>
#include"structures.h"





bool isPeretun(Vidrizok*, Vidrizok*);

int max(int a, int b){
	if(a>b){return a;}
	else{return b;}
}
int min (int a, int b){
	if(a>b){return b;}
	else{return a;}
}

int PsevdoScalyar(Vidrizok* a, Vidrizok* b){
		int first = a->vectorPoint[0]*b->vectorPoint[1]; 
		int secound = b->vectorPoint[0]*a->vectorPoint[1];
	return first-secound;	
}
bool ProectCheck(Vidrizok* a, Vidrizok*b){
	
	bool X = false;
	bool Y = false;

	int aMaxY = max(a->startY,a->endY);
	int aMinY = min(a->startY,a->endY);
	int bMaxY = max(b->startY,b->endY);
	int bMinY = min(b->startY,b->endY);

	int aMaxX = max(a->startX,a->endX);
	int aMinX = min(a->startX,a->endX);
	int bMaxX = max(b->startX,b->endX);
	int bMinX = min(b->startX,b->endX);

	if(min(bMaxX,aMaxX) >=  max(aMinX,bMinX)){X=true;}
	else{return false;}
	
	if(min(bMaxY,aMaxY) >= max (aMinY,bMinY)){Y=true;}
	else{return false;}

	return true;	
}
int main(){

int a,b,c,d;

std::cout<<"Alfa:"<<std::endl;
std::cin>>a;std::cin>>b;std::cin>>c;std::cin>>d;
Vidrizok alfa(a,b,c,d);

std::cout<<"Bravo:"<<std::endl;
std::cin>>a;std::cin>>b;std::cin>>c;std::cin>>d;
Vidrizok bravo(a,b,c,d);

std::vector<Vidrizok> vectorArray;

vectorArray.push_back(alfa);
vectorArray.push_back(bravo);

int s = PsevdoScalyar(&alfa, &bravo);
bool r = ProectCheck(&alfa, &bravo); 
std::cout<<r<<std::endl;

std::cout<<"Skalyar: "<<s<<std::endl;
std::cout<<"Alfa points: "<<alfa.vectorPoint[0]<<alfa.vectorPoint[1]<<std::endl;
std::cout<<"Bravo points: "<<bravo.vectorPoint[0]<<bravo.vectorPoint[1]<<std::endl;
std::cout<<-2*3<<std::endl<<std::endl<<std::endl;
std::cout<<"PeretunVidrizkiv: "<<isPeretun(&alfa,&bravo)<<std::endl;

drawLine(&vectorArray);

return 0;
}

bool isPeretun(Vidrizok* a, Vidrizok* b){

	bool scalarCheck2 = false;
	bool scalarCheck1 = false;
	bool proectCheck = false;

	Vidrizok temp1(a->startX,a->startY,b->startX,b->startY);
	Vidrizok temp2(a->startX,a->startY,b->endX,b->endY);
	
	int scalarResult1 = PsevdoScalyar(a,&temp1);
	int scalarResult2 = PsevdoScalyar(a,&temp2);

	if (scalarResult1 ^ scalarResult2 < 0){
	scalarCheck1 = true;}
	else{return false;}
	
	Vidrizok temp3(b->startX,b->startY,a->startX,a->startY);
	Vidrizok temp4(b->startX,b->startY,a->endX,a->endY);
	
	scalarResult1 = PsevdoScalyar(b,&temp3);
	scalarResult2 = PsevdoScalyar(b,&temp4);
	
	int debug = scalarResult1 ^ scalarResult2; 
	if (debug < 0){
	scalarCheck2 = true;}
	else{return false;}

	proectCheck =  ProectCheck(a,b);

	if(proectCheck&&scalarCheck1&&scalarCheck2){
	return true;
	}
	return false;
}


