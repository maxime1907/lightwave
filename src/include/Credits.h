/*
** CREDITS.h for Project-Master in /home/tekm/tek1/cpp_gameJam
** 
** Made by leroy_0
** Login   <leroy_0@epitech.eu>
** 
** Started on  Sun Jan 22 03:57:13 2017 leroy_0
** Last update Sun Jan 22 03:57:14 2017 leroy_0
*/

#ifndef __CREDITS_H_
#define __CREDITS_H_

#include <SFML/Graphics.hpp>
#include <string>

class Credits : public sf::Sprite
{
	public:
		Credits(float, float);
		~Credits();

	float 			_initX;
	float 			_initY;
};

#endif	/* __CREDITS_H_ */