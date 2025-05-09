#include <vector>
#include "structures.h"



int max(int a, int b){
	if(a>b){return a;}
	else{return b;}
}
int min (int a, int b){
	if(a>b){return b;}
	else{return a;}
}
//for triangles
int max(int a, int b, int c){
	if(a>b&&a>c){return a;}
	if(b>a&&b>c){return b;}
	return c;
}
int min (int a, int b, int c){
	if(a<b&&a<c){return a;}
	if(b<a&&b<c){return b;}
	return c;
}



bool ProectCheck(Triangle* a, Triangle* b){

	bool X = false;
	bool Y = false;
	int buffer;	
	
	//max values
	int aMaxX = max(a->v1.startX, a->v2.startX, a->v3.startX);
	buffer = max(a->v1.endX, a->v2.endX, a->v3.endX);
	aMaxX = max(aMaxX, buffer);
	
	int aMaxY = max(a->v1.startY, a->v2.startY, a->v3.startY);
	buffer = max(a->v1.endY, a->v2.endY, a->v3.endY);
	aMaxY = max(aMaxY, buffer);
	
	int bMaxX = max(b->v1.startX, b->v2.startX, b->v3.startX);
	buffer = max(b->v1.endX, b->v2.endX, b->v3.endX);
	bMaxX = max(bMaxX, buffer);
	
	int bMaxY = max(b->v1.startY, b->v2.startY, b->v3.startY);
	buffer = max(b->v1.endY, b->v2.endY, b->v3.endY);
	bMaxY = max(bMaxY, buffer);
	//min values	
	
	int aMinX = min(a->v1.startX, a->v2.startX, a->v3.startX);
	buffer = min(a->v1.endX, a->v2.endX, a->v3.endX);
	aMinX = min(aMinX, buffer);
	
	int aMinY = min(a->v1.startY, a->v2.startY, a->v3.startY);
	buffer = min(a->v1.endY, a->v2.endY, a->v3.endY);
	aMinY = min(aMinY, buffer);

	int bMinX = min(b->v1.startX, b->v2.startX, b->v3.startX);
	buffer = min(b->v1.endX, b->v2.endX, b->v3.endX);
	bMinX = min(bMinX, buffer);


	int bMinY = min(b->v1.startY, b->v2.startY, b->v3.startY);
	buffer = min(b->v1.endY, b->v2.endY, b->v3.endY);
	bMinY = min(bMinY, buffer);

	if(min(bMaxX,aMaxX) >=  max(aMinX,bMinX)){X=true;}
	
	if(min(bMaxY,aMaxY) >=  max(aMinY,bMinY)){Y=true;}

	if (X&&Y){return true;}
	
	return false;
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

int PsevdoScalyar(Vidrizok* a, Vidrizok* b){
	int first = a->vectorPoint[0]*b->vectorPoint[1]; 
	int secound = b->vectorPoint[0]*a->vectorPoint[1];
	return first-secound;	
}

bool isPeretun(Vidrizok* a, Vidrizok* b){

	bool scalarCheck2 = false;
	bool scalarCheck1 = false;
	bool proectCheck = false;

	Vidrizok temp1(a->startX,a->startY,b->startX,b->startY,false);
	Vidrizok temp2(a->startX,a->startY,b->endX,b->endY,false);
	
	int scalarResult1 = PsevdoScalyar(a,&temp1);
	int scalarResult2 = PsevdoScalyar(a,&temp2);

	if (scalarResult1 ^ scalarResult2 < 0){
	scalarCheck1 = true;}
	else{return false;}
	
	Vidrizok temp3(b->startX,b->startY,a->startX,a->startY,false);
	Vidrizok temp4(b->startX,b->startY,a->endX,a->endY,false);
	
	scalarResult1 = PsevdoScalyar(b,&temp3);
	scalarResult2 = PsevdoScalyar(b,&temp4);
	
	int debug = scalarResult1 ^ scalarResult2; 
	if (debug < 0){
	scalarCheck2 = true;}
	else{return false;}

	proectCheck =  ProectCheck( a, b);

	if(proectCheck&&scalarCheck1&&scalarCheck2){
	return true;
	}
	return false;
}

bool isPeretun (Triangle* a, Triangle* b){
	
	bool ProectForTriangles = ProectCheck(a,b);	
	if (!ProectForTriangles){return false;}
	bool ScalarCheck = false;

	Vidrizok* arrA[3]={ &(a->v1),&( a->v2),&( a->v3)  };	
	Vidrizok* arrB[3]={ &(b->v1),&( b->v2),&( b->v3)  };

	for(int i = 0; i<3; i++){
		for (int j = 0; j<3; j++){
			if (isPeretun(arrA[i],arrB[j])==true){
			return true;
			}
		}
	} 		
	return false; 
}

