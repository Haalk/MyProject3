#include "Player.h"
#include <conio.h>
#include <iostream>

Player::Player() : m_dir(nDirection::DOWN)
{
	m_Coord.X = 7;
	m_Coord.Y = 10;
}


Player::~Player()
{

}

void Player::move(const nDirection::edirection& direction, Field * field) //Field * field
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_Coord);
	std::cout << " ";
	//coord_x = m_Coord.X;
	//coord_y = m_Coord.Y;
	switch (direction)
	{
	case nDirection::edirection::LEFT:
		m_dir = nDirection::edirection::LEFT;
		if (m_Coord.X > 1)
		//if (m_Coord.X > 1 && !(field->isWall(m_Coord.X -1 , m_Coord.Y)))
			//std::cout << m_Coord.X << std::endl;
			m_Coord.X -= 1;
		break;
	case nDirection::edirection::RIGHT:
		m_dir = nDirection::edirection::RIGHT;
		if (m_Coord.X < SIZE_FIELD - 2)
		//if (m_Coord.X < SIZE_FIELD - 2 && !(field->isWall(m_Coord.X + 1, m_Coord.Y)))
			m_Coord.X += 1;
		break;
	case nDirection::edirection::UP:
		m_dir = nDirection::edirection::UP;
		if (m_Coord.Y > 1)
		//if (m_Coord.Y > 1 && !(field->isWall(m_Coord.X, m_Coord.Y - 1)))
			m_Coord.Y -= 1;
		break;
	case nDirection::edirection::DOWN:
		m_dir = nDirection::edirection::DOWN;
		if (m_Coord.Y < SIZE_FIELD - 3)
		//if (m_Coord.Y < SIZE_FIELD - 3 && !(field->isWall(m_Coord.X, m_Coord.Y + 1)))
			m_Coord.Y += 1;
		break;
	default:
		break;
	}
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_Coord);
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
	std::cout << "*";
	//std::cout << m_Coord.X << "," << m_Coord.Y << std::endl;

	/*if (_kbhit())
	{
		int key = _getch();
		field->setPoint(coord_x, coord_y, ' ');
		if (key == nButtons::UP && !field->isWall(coord_x - 1, coord_y))
		{
			m_dir = nDirection::UP;
			--coord_x;
		}
		else if (key == nButtons::DOWN && !field->isWall(coord_x + 1, coord_y))
		{
			m_dir = nDirection::DOWN;
			++coord_x;
		}
		else if (key == nButtons::LEFT && !field->isWall(coord_x, coord_y-1))
		{
			m_dir = nDirection::LEFT;
			--coord_y;
		}
		else if (key == nButtons::RIGHT && !field->isWall(coord_x , coord_y + 1))
		{
			m_dir = nDirection::RIGHT;
			++coord_y;
		}
	}
	field->setPoint(coord_x, coord_y, '@');*/
}

/*void Player::control()
{
	char button = '0';
	if (true == _kbhit())
	{
		button = _getch();
		switch (_getch())
		{
		case nButtons::LEFT:
			if (m_Coord.X > 1) 
				move(nDirection::edirection::LEFT);
			break;
		case nButtons::RIGHT:
			if(m_Coord.X < SIZE_FIELD - 2)
				move(nDirection::edirection::RIGHT);
			break;
		case nButtons::UP:
			if(m_Coord.Y>1)
				move(nDirection::edirection::UP);
			break;
		case nButtons::DOWN:
			if(m_Coord.Y < SIZE_FIELD - 3)
				move(nDirection::edirection::DOWN);
			break;
	//	case nButtons::SPACE:
			//m_bullet.push_back(mTank.shot());
			//break;
		default:
			break;
		}
	}
}*/

Bullet Player::fire()
{
	return Bullet(m_dir, m_Coord);
}

COORD Player::coord_pl()
{
	return m_Coord;
}
