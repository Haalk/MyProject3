#pragma once
#include "Helper.h"
#include "Field.h"
#include "Bullet.h"

class Enemy
{
public:
	Enemy();
	~Enemy(); 
	Bullet en_fire();
	COORD coord_en();
	void move(const nDirection::edirection&,Field*);
	Bullet fire();
	nDirection::edirection getDir();
	void setDir(nDirection::edirection);
private:
	nDirection::edirection en_dir;
	COORD en_Coord;
};

