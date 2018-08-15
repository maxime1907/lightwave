//
// Created by sadzeih on 21/01/17.
//

#include "../include/Box.h"
#include "../include/Point.h"

Box::Box(Point &point, float halfDimension)
: _center(point), _halfDimension(halfDimension)
{

}

Box::~Box()
{

}

bool Box::containsPoint(Point *point) {
    if (!(point->getX() >= getWest() && point->getX() <= getEast()))
        return false;
    if (!(point->getY() >= getNorth() && point->getY() <= getSouth()))
        return false;
    return true;
}

bool Box::intersectsBox(Box &box) {
    if (containsPoint(new Point(box.getWest(), box.getNorth())))
        return true;
    if (containsPoint(new Point(box.getEast(), box.getNorth())))
        return true;
    if (containsPoint(new Point(box.getWest(), box.getSouth())))
        return true;
    if (containsPoint(new Point(box.getEast(), box.getSouth())))
        return true;
    return false;
}

Point &Box::getCenter() {
    return _center;
}

float Box::getHalfDimension() {
    return _halfDimension;
}

float Box::getEast() {
    return _center.getX() + _halfDimension;
}

float Box::getWest() {
    return _center.getX() - _halfDimension;
}

float Box::getNorth() {
    return _center.getY() - _halfDimension;
}

float Box::getSouth() {
    return _center.getY() + _halfDimension;
}