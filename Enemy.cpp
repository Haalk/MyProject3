#include "Enemy.h"
#include <iostream>
#include <random>
#include <ctime>

Enemy::Enemy() : en_dir(nDirection::RIGHT)
{
	en_Coord.X = 2;
	en_Coord.Y = 2;
	srand(time(0));
}


Enemy::~Enemy()
{
}

Bullet Enemy::en_fire()
{
	return Bullet(en_dir, en_Coord);
}

COORD Enemy::coord_en()
{
	return en_Coord;
}

void Enemy::move(const nDirection::edirection&direction,Field *)
{
	//Sleep(150);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), en_Coord);
	std::cout << " ";
	
	switch (direction)
	{
	case nDirection::edirection::LEFT:
		en_dir = nDirection::edirection::LEFT;
		if (en_Coord.X > 1)
			//if (m_Coord.X > 1 && !(field->isWall(m_Coord.X -1 , m_Coord.Y)))
			//std::cout << m_Coord.X << std::endl;
			en_Coord.X -= 1;
		break;
	case nDirection::edirection::RIGHT:
		en_dir = nDirection::edirection::RIGHT;
		if (en_Coord.X < SIZE_FIELD - 2)
			//if (m_Coord.X < SIZE_FIELD - 2 && !(field->isWall(m_Coord.X + 1, m_Coord.Y)))
			en_Coord.X += 1;
		break;
	case nDirection::edirection::UP:
		en_dir = nDirection::edirection::UP;
		if (en_Coord.Y > 1)
			//if (m_Coord.Y > 1 && !(field->isWall(m_Coord.X, m_Coord.Y - 1)))
			en_Coord.Y -= 1;
		break;
	case nDirection::edirection::DOWN:
		en_dir = nDirection::edirection::DOWN;
		if (en_Coord.Y < SIZE_FIELD - 3)
			//if (m_Coord.Y < SIZE_FIELD - 3 && !(field->isWall(m_Coord.X, m_Coord.Y + 1)))
			en_Coord.Y += 1;
		break;
	default:
		break;
	}

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), en_Coord);
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
	std::cout << "@";
	
}

Bullet Enemy::fire()
{
	return Bullet(en_dir, en_Coord);
}

nDirection::edirection Enemy::getDir()
{
	return en_dir;
}

void Enemy::setDir(nDirection::edirection dir)
{
	en_dir = dir;
}