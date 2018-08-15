//
// Created by sadzeih on 21/01/17.
//

#ifndef CPP_GAMEJAM_POINT_H
#define CPP_GAMEJAM_POINT_H


class Point {
private:
    float _x;
    float _y;

public:
    Point(float x, float y);
    ~Point();

    float getX();
    float getY();
    void setX(float x);
    void setY(float y);

};


#endif //CPP_GAMEJAM_POINT_H
