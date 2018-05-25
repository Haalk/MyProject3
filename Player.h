#pragma once
#include "Helper.h"
#include "Field.h"
#include "Bullet.h"
#include <Windows.h>

class Player
{
public:
	Player();
	~Player();
	void move(const nDirection::edirection&,Field*); //Field*
	//void control();
	Bullet fire();
	COORD coord_pl();
private:
	nDirection::edirection m_dir;
	//Bullet m_bullet;
	//int coord_x;
	//int coord_y;
	COORD m_Coord;

};

