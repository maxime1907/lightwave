/*
** Menu.h for Project-Master in /home/tekm/tek1/cpp_gameJam
** 
** Made by leroy_0
** Login   <leroy_0@epitech.eu>
** 
** Started on  Sun Jan 22 03:57:13 2017 leroy_0
** Last update Sun Jan 22 03:57:14 2017 leroy_0
*/

#ifndef __MENU_H_
#define __MENU_H_

#include <SFML/Graphics.hpp>
#include <string>

class Menu : public sf::Sprite
{
	public:
		Menu(float, float);
		~Menu();

	sf::Sprite 		*cursor;
	float 			_initX;
	float 			_initY;
};

#endif	/* __MENU_H_ */