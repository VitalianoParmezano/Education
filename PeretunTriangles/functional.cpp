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



bool ProectForTriangles(Triangle* a, Triangle* b){

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
