#pragma once

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
    }
};


