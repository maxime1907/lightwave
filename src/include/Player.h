//
// Created by sadzeih on 20/01/17.
//

#ifndef CPP_GAMEJAM_PLAYER_H
#define CPP_GAMEJAM_PLAYER_H

#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "typedef.h"
#include "Map.h"
#include "Life.h"

using namespace sf;
using namespace std;

class Player: public Sprite , public Animation, public Life
{
public:
    Player(const std::string & player_sprite, const float posX, const float posY);
    ~Player();

    sf::View &			getView();

    void			setLightPosition(Direction);

    void			cameraRight(float);
    void 			cameraLeft();
    void 			cameraUp();
    void 			cameraDown(float);

    void 			movePlayerLeft();
    void 			movePlayerRight(float);
    void 			movePlayerUp();
    void 			movePlayerDown(float);
    void 			movePlayerDownLeft(float);
    void 			movePlayerDownRight(float, float);
    void 			movePlayerUpLeft();
    void 			movePlayerUpRight(float);
	Direction		where;

    void 			manageInputs(Env::Map & map, float backgroundX, float backgroundY);
    virtual void 	move(Direction dir, float backgroundX, float backgroundY);

    void lightEffects();

    bool getWave();
    void setWave(bool val);
    bool takeDamage(int val);
    bool getInvicible();
    void setInvicible(bool val);
public:
	  float               speedX;
	  float               speedY;
	  sf::Sprite		_light;
	bool				_isAttack;
	Animation			*_attack;
	Animation			*_tmp;
	Clock				*_TimeAttack;


private:
    bool _invicible;
    Clock *clock;
   	sf::View		*_view;
	sf::Texture		_lightTexture;
    bool _lightGrow;
    bool _lightFadeOut;
    bool _lightFadeIn;
    sf::Sprite      *_life;
};

#endif //CPP_GAMEJAM_PLAYER_H
