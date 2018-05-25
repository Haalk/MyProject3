#pragma once
#include "Player.h"
#include <vector>
#include "Field.h"
#include "Enemy.h"

class Core
{
public:
	Core();
	~Core();
	void execute();
	
private:
	Player mTank;
	Enemy en_Tank;
	std::vector<Bullet> mBullet;
	//std::vector<Bullet> mBullet_en;
	int counter;
	Field *m_field;
	int pl_bullet;
};

