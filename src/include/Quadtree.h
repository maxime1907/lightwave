//
// Created by sadzeih on 21/01/17.
//

#ifndef CPP_GAMEJAM_QUADTREE_H
#define CPP_GAMEJAM_QUADTREE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Box.h"
#include "Point.h"

class Quadtree {
public:
    enum Obstacle {
        EMPTY,
        BOTH,
        FULL
    };

    enum Side {
        NORTH,
        SOUTH,
        WEST,
        EAST
    };

    enum Quadrant {
        NORTHWEST,
        SOUTHEAST,
        SOUTHWEST,
        NORTHEAST,
        ERROR,
    };
private:
    Box _box;
    std::vector<sf::Sprite> _map;

    Obstacle _obstacle;

    Quadtree *_parent;

    Quadtree *northWest;
    Quadtree *northEast;
    Quadtree *southWest;
    Quadtree *southEast;

    void init();

public:

    Quadtree(Box &box, std::vector<sf::Sprite> map, Quadtree *parent);
    Quadtree(Box *box, std::vector<sf::Sprite> map, Quadtree *parent);
    ~Quadtree();

    bool subdivide();
    bool hasChildren();

    Quadrant quadrant();

    Quadtree *neighbor(Side side);
    Quadtree *neighbor(Side side, Quadrant quadrant);
    Quadtree *find(Point &point);

    void toString();
};


#endif //CPP_GAMEJAM_QUADTREE_H
