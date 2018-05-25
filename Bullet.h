#pragma once
#include "Helper.h"
#include "Field.h"
#include <Windows.h>

class Bullet
{
public:
	Bullet(const nDirection::edirection&,const COORD&);
	~Bullet();
	bool move(Field *);
	void GameOver();
private:
	nDirection::edirection b_dir;
	COORD b_Coord;
	bool isKill;
};

