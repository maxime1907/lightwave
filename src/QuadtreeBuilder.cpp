//
// Created by sadzeih on 21/01/17.
//

#include <SFML/Graphics.hpp>
#include "QuadtreeBuilder.h"

QuadtreeBuilder::QuadtreeBuilder(Point &center, float halfDimension, std::vector<sf::Sprite> map)
_map(map)
{
    _tree = new Quadtree(new Box(center, halfDimension));
}

QuadtreeBuilder::~QuadtreeBuilder()
{

}

void QuadtreeBuilder::build()
{
}
