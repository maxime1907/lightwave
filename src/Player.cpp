//
// Created by sadzeih on 20/01/17.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Collision.h"
#include "Map.h"

using namespace std;
using namespace sf;

Player::Player(const std::string & player_sprite, const float posX, const float posY)
	: Sprite() , Animation(player_sprite, 36, 36, 16, 4), Life(sf::Vector2f(posX + 6, posY - 4))
{
	for (unsigned int i = 0; i < _nbSprite ; i++)
		_vector[i].setPosition(posX, posY);

	this->speedX = 0.16f;
	this->speedY = 0.16f;
	this->_view = new View(Vector2f(posX + 5, posY + 10), Vector2f(620, 350));
	where = DOWN;

	clock = new Clock;

	_invicible = false;
	setPosition(posX, posY);

	_lightTexture.loadFromFile("../src/assets/light_perso_pixel.png");
	_lightTexture.setSmooth(true);
	_light.setTexture(_lightTexture);
	_isAttack = false;
	_TimeAttack = new Clock();
	_tmp = new Animation("../src/assets/player_move.png", 36, 36, 16, 4);
	_attack = new Animation("../src/assets/player_sword.png", 36, 36, 16, 4);

	_light.setPosition(this->getPosition().x + 10, this->getPosition().y + 15);
	_light.setOrigin(sf::Vector2f(136, 136));

	_lightGrow = false;
	_lightFadeOut = false;
	_lightFadeIn = false;
}

Player::~Player()
{

}

bool Player::getInvicible()
{
	return _invicible;
}

void Player::setInvicible(bool val)
{
	_invicible = val;
}

void Player::setWave(bool val)
{
	_lightGrow = val;
}

void Player::lightEffects()
{
	if (clock->getElapsedTime().asSeconds() >= 1.f) {
		_invicible = false;
		clock->restart();
	}
	if (_invicible) {
		_vector[_move].setColor(sf::Color(255, 50, 50, 255));
	} else {
		_vector[_move].setColor(sf::Color(255, 255, 255, 255));
	}
	if (_lightGrow)
	{
		_light.setScale(_light.getScale().x * 1.001, _light.getScale().y * 1.001);
		if (_light.getScale().x >= 3) {
			_lightGrow = false;
			_lightFadeOut = true;
		}
	}
	if (_lightFadeOut)
	{
		sf::Color color = _light.getColor();
		if (color.a - 1 <= 0)
		{
			_lightFadeOut = false;
			_lightFadeIn = true;
			color.a = 0;
		}
		else
			color.a = color.a - 1;
		_light.setColor(color);
	}
	if (_lightFadeIn)
	{
		_light.setScale(sf::Vector2f(1, 1));
		sf::Color color = _light.getColor();
		if (color.a + 1 >= 255)
		{
			_lightFadeIn = false;
			color.a = 255;
		}
		else
			color.a = color.a + 1;
		_light.setColor(color);
	}
}

bool Player::getWave()
{
	return _lightGrow;
}

void      Player::setLightPosition(Direction dir) {
	(void) dir;
	_light.setPosition(this->getPosition().x + 15, this->getPosition().y + 15);
}

View &		Player::getView()
{
	return (*_view);
}

void 			Player::cameraLeft()
{
	if ((this->getView().getCenter().x - (this->getView().getSize().x / 2) >= 0 && this->getPosition().x < this->getView().getCenter().x))
		this->getView().move(-speedX, 0);
}

void 			Player::cameraRight(float backgroundX)
{
	if ((this->getView().getCenter().x + (this->getView().getSize().x / 2) <= backgroundX && this->getPosition().x > this->getView().getCenter().x))
		this->getView().move(speedX, 0);
}

void 			Player::cameraUp()
{
	if ((this->getView().getCenter().y - (this->getView().getSize().y / 2) >= 0 && this->getPosition().y < this->getView().getCenter().y))
		this->getView().move(0, -speedY);
}

void			Player::cameraDown(float backgroundY)
{
	if ((this->getView().getCenter().y + (this->getView().getSize().y / 2) <= backgroundY && this->getPosition().y > this->getView().getCenter().y))
		this->getView().move(0, speedY);
}

void 			Player::movePlayerLeft()
{
	sf::Transformable::move(-speedX, 0);
	for (unsigned int i = 0; i < _nbSprite ; i++)
		_vector[i].move(-speedX, 0);
	moveLeft();
	cameraLeft();
}

void 			Player::movePlayerRight(float backgroundX)
{
	sf::Transformable::move(speedX, 0);
	for (unsigned int i = 0; i < _nbSprite ; i++)
		_vector[i].move(speedX, 0);
	moveRight();
	cameraRight(backgroundX);
}

void 			Player::movePlayerUp()
{
	sf::Transformable::move(0, -speedY);
	for (unsigned int i = 0; i < _nbSprite ; i++)
		_vector[i].move(0, -speedY);
	cameraUp();
	moveUp();
}

void 			Player::movePlayerDown(float backgroundY)
{
	sf::Transformable::move(0, speedY);
	for (unsigned int i = 0; i < _nbSprite ; i++)
		_vector[i].move(0, speedY);
	cameraDown(backgroundY);
	moveDown();
}

void			Player::movePlayerDownLeft(float backgroundY)
{
	sf::Transformable::move(-speedX, speedY);
	for (unsigned int i = 0; i < _nbSprite ; i++)
		_vector[i].move(-speedX, speedY);
	cameraDown(backgroundY);
	cameraLeft();
	moveDown();
}

void 			Player::movePlayerDownRight(float backgroundX, float backgroundY)
{
	sf::Transformable::move(speedX, speedY);
	for (unsigned int i = 0; i < _nbSprite ; i++)
		_vector[i].move(speedX, speedY);
	cameraDown(backgroundY);
	cameraRight(backgroundX);
	moveDown();
}

void 			Player::movePlayerUpLeft()
{
	sf::Transformable::move(-speedX, -speedY);
	for (unsigned int i = 0; i < _nbSprite ; i++)
		_vector[i].move(-speedX, -speedY);
	cameraUp();
	cameraLeft();
	moveUp();
}

void 			Player::movePlayerUpRight(float backgroundX)
{
	sf::Transformable::move(speedX, -speedY);
	for (unsigned int i = 0; i < _nbSprite ; i++)
		_vector[i].move(speedX, -speedY);
	cameraUp();
	cameraRight(backgroundX);
	moveUp();
}

void			Player::manageInputs(Env::Map & map, float backgroundX, float backgroundY)
{
	if (Keyboard::isKeyPressed(Keyboard::Space))
	{
		sf::SoundBuffer buffer;
		sf::Sound sound;
		buffer.loadFromFile("../src/assets/weapon-swing.wav");
	    sound.setBuffer(buffer);
		sound.setVolume(100);
		sound.play();
		buffer.loadFromFile("../src/assets/weapon-swing-voice.wav");
	    sound.setBuffer(buffer);
		sound.setVolume(100);
		sound.play();
		_isAttack = true;
		for (int i = 0; i < 15 ; i++)
		{
			_attack->_vector[i].setPosition(getPosition().x, getPosition().y);
			_vector[i] = _attack->_vector[i];
		}
		if (where == DOWN)
			moveDown();
		if (where == LEFT)
			moveLeft();
		if (where == RIGHT)
			moveRight();
		if (where == UP)
			moveUp();
	}
	if (_TimeAttack->getElapsedTime().asSeconds() > 0.5f)
	{
		_isAttack = false;
		for (int i = 0; i < 15 ; i++)
		{
			_tmp->_vector[i].setPosition(getPosition().x, getPosition().y);
			_vector[i] = _tmp->_vector[i];
		}
		_TimeAttack->restart();
	}
	if (Keyboard::isKeyPressed(Keyboard::Left) && !Env::Collision::Collide(*this, map.wall(), -speedX - 1, 0))
	{
		_isAttack = false;
		for (int i = 0; i < 15 ; i++)
		{
			_tmp->_vector[i].setPosition(getPosition().x, getPosition().y);
			_vector[i] = _tmp->_vector[i];
		}
		if (Keyboard::isKeyPressed(Keyboard::Down) && !Env::Collision::Collide(*this, map.wall(), 0, speedY + 1))
			this->move(DOWN_LEFT, backgroundX, backgroundY);
		else if (Keyboard::isKeyPressed(Keyboard::Up) && !Env::Collision::Collide(*this, map.wall(), 0, -speedY - 1))
			this->move(UP_LEFT, backgroundX, backgroundY);
		else
			this->move(LEFT, backgroundX, backgroundY);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right) && !Env::Collision::Collide(*this, map.wall(), speedX + 1, 0))
	{
		_isAttack = false;
		for (int i = 0; i < 15 ; i++)
		{
			_tmp->_vector[i].setPosition(getPosition().x, getPosition().y);
			_vector[i] = _tmp->_vector[i];
		}
		if (Keyboard::isKeyPressed(Keyboard::Down) && !Env::Collision::Collide(*this, map.wall(), 0, speedY + 1))
			this->move(DOWN_RIGHT, backgroundX, backgroundY);
		else if (Keyboard::isKeyPressed(Keyboard::Up) && !Env::Collision::Collide(*this, map.wall(), 0, -speedY - 1))
			this->move(UP_RIGHT, backgroundX, backgroundY);
		else
			this->move(RIGHT, backgroundX, backgroundY);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Up) && !Env::Collision::Collide(*this, map.wall(), 0, -speedY - 1))
	{
		_isAttack = false;
		for (int i = 0; i < 15 ; i++)
		{
			_tmp->_vector[i].setPosition(getPosition().x, getPosition().y);
			_vector[i] = _tmp->_vector[i];
		}
		this->move(UP, backgroundX, backgroundY);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Down) && !Env::Collision::Collide(*this, map.wall(), 0, speedY + 1))
	{
		_isAttack = false;
		for (int i = 0; i < 15 ; i++)
		{
			_tmp->_vector[i].setPosition(getPosition().x, getPosition().y);
			_vector[i] = _tmp->_vector[i];
		}
		this->move(DOWN, backgroundX, backgroundY);
	}

	if (Joystick::isConnected(0))
	{
		float x = Joystick::getAxisPosition(0, Joystick::X) / 100;
		float y = Joystick::getAxisPosition(0, Joystick::Y) / 100;

		if (x > 0.2f && !Env::Collision::Collide(*this, map.wall(), x * speedX + 1, 0))
			this->move(RIGHT, backgroundX, backgroundY);
		if (y > 0.2f && !Env::Collision::Collide(*this, map.wall(), 0, y * speedY + 1))
			this->move(DOWN, backgroundX, backgroundY);
		if (x < -0.2f && !Env::Collision::Collide(*this, map.wall(), x * speedX - 1, 0))
			this->move(LEFT, backgroundX, backgroundY);
		if (y < -0.2f && !Env::Collision::Collide(*this, map.wall(), 0, speedY *y - 1))
			this->move(UP, backgroundX, backgroundY);
	}
}

void 			Player::move(Direction dir, float backgroundX, float backgroundY)
{
  this->setLightPosition(dir);
	switch(dir)
	{
		case LEFT:
			where = LEFT;
			movePlayerLeft();
			break;
		case RIGHT:
			where = RIGHT;
			movePlayerRight(backgroundX);
			break;
		case UP:
			where = UP;
			movePlayerUp();
			break;
		case DOWN:
			where = DOWN;
			movePlayerDown(backgroundY);
			break;
		case DOWN_LEFT:
			movePlayerDownLeft(backgroundX);
			break;
		case DOWN_RIGHT:
			movePlayerDownRight(backgroundX, backgroundY);
			break;
		case UP_LEFT:
			movePlayerUpLeft();
			break;
		case UP_RIGHT:
			movePlayerUpRight(backgroundX);
			break;
	}
	setLifePosition(sf::Vector2f(getPosition().x + 6, getPosition().y - 4));
}

bool Player::takeDamage(int val)
{
	if (_invicible)
		return true;
	sf::Sound 					sound;
	sf::SoundBuffer 			buffer;
    setLife(getLife() - val);
	_invicible = true;
	if (getLife() <= 0) {
		buffer.loadFromFile("../src/assets/death.wav");
	    sound.setBuffer(buffer);
		sound.setVolume(100);
		sound.play();
		return false;
	}
	buffer.loadFromFile("../src/assets/hit.wav");
    sound.setBuffer(buffer);
	sound.setVolume(100);
	sound.play();
	return true;
}
