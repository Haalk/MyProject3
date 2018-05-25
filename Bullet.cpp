#include "Bullet.h"
#include <iostream>
#include <conio.h>

Bullet::Bullet(const nDirection::edirection & dir, const COORD & coord) :
						b_dir(dir),b_Coord(coord),isKill(false)
{
}

Bullet::~Bullet()
{
}

bool Bullet::move(Field* field)
{
	//if (field->isTank(b_Coord))
		//GameOver();
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), b_Coord);
	std::cout << " ";
	switch (b_dir)
	{
	case nDirection::edirection::LEFT:
		if (b_Coord.X > 1/*&& !field->isWall(b_Coord.X-1, b_Coord.Y)*/)b_Coord.X -= 1;
		else return false;
		break;
	case nDirection::edirection::RIGHT:
		if (b_Coord.X < SIZE_FIELD - 2 /*&& !field->isWall(b_Coord.X+1, b_Coord.Y)*/)b_Coord.X += 1;
		else return false;
		break;
	case nDirection::edirection::UP:
		if (b_Coord.Y > 1/* && !field->isWall(b_Coord.X, b_Coord.Y-1)*/)b_Coord.Y -= 1;
		else return false;
		break;
	case nDirection::edirection::DOWN:
		if (b_Coord.Y < SIZE_FIELD - 3 /*&& !field->isWall(b_Coord.X, b_Coord.Y+1)*/)b_Coord.Y += 1;
		else return false;
		break;
	default:
		break;
	}

	if (field->isTank(b_Coord))
		GameOver();
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), b_Coord);
	std::cout << ".";
	return true;

}

void Bullet::GameOver()
{
	system("cls");
	std::cout << "\n\n\t\t THANK YOU!!!";
	_getch();
	exit(0);
}