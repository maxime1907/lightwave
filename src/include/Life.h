/*
** Life.h for Project-Master in /home/tekm/tek1/cpp_gameJam
** 
** Made by leroy_0
** Login   <leroy_0@epitech.eu>
** 
** Started on  Sun Jan 22 01:32:25 2017 leroy_0
** Last update Sun Jan 22 01:32:26 2017 leroy_0
*/

#ifndef __LIFE_H_
#define __LIFE_H_

#include <SFML/Graphics.hpp>
#include <string>

class Life
{
	public:
		Life(const sf::Vector2f & positon);
		~Life();

	float 		getLife() const;
	void 		setLife(float life);
	void 		manageLife();
	sf::Sprite 	getLifeBar();
	void 		setLifePosition(const sf::Vector2f position);

private:
	float 		_life;
	sf::Sprite 	*_life_bar;
};

#endif 	/* __LIFE_H_ */