//
// Menu.cpp for Project-Master in /home/tekm/tek1/cpp_gameJam
// 
// Made by leroy_0
// Login   <leroy_0@epitech.eu>
// 
// Started on  Sun Jan 22 03:57:07 2017 leroy_0
// Last update Sun Jan 22 03:57:07 2017 leroy_0
//

#include "Menu.h"
#include <string>
#include <iostream>

Menu::Menu(float backgroundX, float backgroundY)
{
	sf::Texture 	*menu = new sf::Texture();
	sf::Texture 	*cursor_texture = new sf::Texture();

	_initX = backgroundX / 2 - 200;
	_initY = backgroundY / 2 + 80;

	cursor = new sf::Sprite();
	menu->loadFromFile("../src/assets/menu.jpg");
	setTexture(*menu);
	setScale(backgroundX / menu->getSize().x , backgroundY / menu->getSize().y);
	setPosition(sf::Vector2f(0, 0));
	cursor_texture->loadFromFile("../src/assets/curseur.png");
	cursor->setTexture(*cursor_texture);
	cursor->setPosition(sf::Vector2f(_initX, _initY));
}

Menu::~Menu()
{

}