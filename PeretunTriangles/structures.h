#pragma once

struct Vidrizok;

std::vector<Vidrizok> vectorArray;

struct Vidrizok {
    int startX;
    int endX;
    int startY;
    int endY;
    int vectorPoint[2];

    Vidrizok(int startX, int startY, int endX, int endY) {
        this->startX = startX;
        this->endX = endX;
        this->startY = startY;
        this->endY = endY;

        this->vectorPoint[0] = endX - startX;
        this->vectorPoint[1] = endY - startY;
	
	vectorArray.push_back(*this);
    }
};


class Triangle {

public: 

Vidrizok v1;
Vidrizok v2;
Vidrizok v3;

	Triangle(int X1, int Y1, int X2, int Y2, int X3, int Y3){
		
	v1(X1,Y1,X2,Y2);
	v2(X2,Y2,X3,Y3);
	v3(X3,Y3,X1,Y1);
	
	}

};
