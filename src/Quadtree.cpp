//
// Created by sadzeih on 21/01/17.
//

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Quadtree.h"
#include "Box.h"
#include "Point.h"

Quadtree::Quadtree(Box &box, std::vector<sf::Sprite> map, Quadtree *parent)
: _box(box), _map(map), _parent(parent)
{
    init();
}

Quadtree::Quadtree(Box *box, std::vector<sf::Sprite> map, Quadtree *parent)
: _box(*box), _map(map), _parent(parent)
{
    init();
}

void Quadtree::init()
{
    northEast = NULL;
    northWest = NULL;
    southEast = NULL;
    southWest = NULL;
    bool intersect = false;
    for (size_t i = 0; i < _map.size(); i++) {
        sf::FloatRect wallBounds = _map[i].getGlobalBounds();
        float halfDimension = wallBounds.width / 2;
        Point center(wallBounds.left + halfDimension, wallBounds.top + halfDimension);
        Box wallBox(center, halfDimension);
        if (wallBox.intersectsBox(_box))
            intersect = true;
    }
    if (intersect)
    {
        _obstacle = BOTH;
        subdivide();
    } else {
        _obstacle = EMPTY;
    }
}

Quadtree::~Quadtree()
{
    if (northWest)
        delete northWest;
    if (northEast)
        delete northEast;
    if (southWest)
        delete southWest;
    if (southEast)
        delete southEast;
}

bool Quadtree::subdivide()
{
    float newHalfDimension = _box.getHalfDimension() / 2;
    if (newHalfDimension <= 4)
    {
        _obstacle = FULL;
        return false;
    }
    Point centerNorthWest(_box.getCenter().getX() - newHalfDimension, _box.getCenter().getY() - newHalfDimension);
    Point centerNorthEast(_box.getCenter().getX() + newHalfDimension, _box.getCenter().getY() - newHalfDimension);
    Point centerSouthWest(_box.getCenter().getX() - newHalfDimension, _box.getCenter().getY() + newHalfDimension);
    Point centerSouthEast(_box.getCenter().getX() + newHalfDimension, _box.getCenter().getY() + newHalfDimension);
    northWest = new Quadtree(new Box(centerNorthWest, newHalfDimension), _map, this);
    northEast = new Quadtree(new Box(centerNorthEast, newHalfDimension), _map, this);
    southWest = new Quadtree(new Box(centerSouthWest, newHalfDimension), _map, this);
    southEast = new Quadtree(new Box(centerSouthEast, newHalfDimension), _map, this);
    return true;
}

bool Quadtree::hasChildren()
{
    return (northWest && northEast && southWest && southEast);
}

Quadtree::Quadrant Quadtree::quadrant()
{
    if (_parent)
    {
        if (_parent->northWest == this)
            return NORTHWEST;
        else if (_parent->northEast == this)
            return NORTHEAST;
        else if (_parent->southWest == this)
            return SOUTHWEST;
        else
            return SOUTHEAST;
    }
    return ERROR;
}

Quadtree *Quadtree::neighbor(Side side)
{
    if (_parent && )
    {
        _parent->neighbor(side))
    }
}

Quadtree *Quadtree::neighbor(Side side, Quadrant quadrant)
{
    if (Side == NORTH)
    {
        if (quadrant == NORTHWEST)
        {

        }
    }
}

Quadtree *Quadtree::find(Point &point)
{
    Quadtree *quad = this;

    if (!_box.containsPoint(&point))
        return NULL;

    while (quad->hasChildren())
    {
        Point center(quad->_box.getWest() + quad->_box.getHalfDimension(), quad->_box.getNorth() + quad->_box.getHalfDimension());
        if (point.getX() < center.getX())
        {
            if (point.getY() < center.getY()) {
                quad = northWest;
            } else {
                quad = southWest;
            }
        } else {
            if (point.getY() < center.getY()) {
                quad = northEast;
            } else {
                quad = southEast;
            }
        }
    }
    return quad;
}

void Quadtree::toString()
{
    std::cout << "QUADTREE:" << std::endl;
    std::cout << "\tNorth West:" << std::endl;
    std::cout << "\t\tx:" << _box.getWest() << std::endl;
    std::cout << "\t\ty:" << _box.getNorth() << std::endl;
    std::cout << "\tNorth East:" << std::endl;
    std::cout << "\t\tx:" << _box.getEast() << std::endl;
    std::cout << "\t\ty:" << _box.getNorth() << std::endl;
    std::cout << "\tSouth West:" << std::endl;
    std::cout << "\t\tx:" << _box.getWest() << std::endl;
    std::cout << "\t\ty:" << _box.getSouth() << std::endl;
    std::cout << "\tSouth East:" << std::endl;
    std::cout << "\t\tx:" << _box.getEast() << std::endl;
    std::cout << "\t\ty:" << _box.getSouth() << std::endl;
}
