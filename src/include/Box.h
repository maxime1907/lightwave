//
// Created by sadzeih on 21/01/17.
//

#ifndef CPP_GAMEJAM_BOX_H
#define CPP_GAMEJAM_BOX_H

#include "Point.h"

class Box {
private:
    Point _center;
    float _halfDimension;

public:
    Box(Point &point, float halfDimension);
    ~Box();

    bool containsPoint(Point *point);
    bool intersectsBox(Box &box);

    Point &getCenter();
    float getHalfDimension();

    float getEast();
    float getWest();
    float getNorth();
    float getSouth();
};


#endif //CPP_GAMEJAM_BOX_H
