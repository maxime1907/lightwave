//
// Created by sadzeih on 21/01/17.
//

#ifndef CPP_GAMEJAM_QUADTREEBUILDER_H
#define CPP_GAMEJAM_QUADTREEBUILDER_H


class QuadtreeBuilder {
private:
    Quadtree *_tree;
    std::vector<sf::Sprite> _map;

public:
    QuadtreeBuilder(Point &center, float halfDimension, std::vector<sf::Sprite> map);
    ~QuadtreeBuilder();

    void build();
};


#endif //CPP_GAMEJAM_QUADTREEBUILDER_H
