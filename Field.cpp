#include "Field.h"
#include "Helper.h"
#include <conio.h>
#include <iostream>
#include <fstream>


Field::Field()
{
	m_field.resize(SIZE_FIELD);
	for (int i = 0; i < SIZE_FIELD; i++)
		m_field[i].resize(SIZE_FIELD);
}

void Field::loadField()
{
	std::ifstream fin("field.txt");
	if (!fin.is_open())
	{
		std::cout << "Error field.txt";
		_getch();
		exit(0);
	}
	int x=0;
	int y=0;
	char ch;
	while (fin)
	{
		ch = fin.get();
		m_field[x][y] = ch;
		y++;
		if (y == SIZE_FIELD)
		{
			y = 0;
			x++;
		}
	}
}

void Field::drawField()
{
	system("cls");
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, 15);
	for (int i = 0; i < SIZE_FIELD; i++)
	{
		for (int j = 0; j < SIZE_FIELD; j++) 
		{
			if ((player.X == i && player.Y == j) || (enemy.X == i && enemy.Y == j));
			/*if (m_field[i][j]=='*')
			{
				SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
				std::cout << m_field[i][j];
				SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | 15);
			}*/
			else 
				std::cout << m_field[i][j];
		}
	}
}

char Field::getPoint(int x, int y) const
{
	return m_field[x][y];
}

void Field::setPoint(int x , int y, char ch)
{
	m_field[x][y] = ch;
}

bool Field::isWall(COORD iswall)
{
	//std::cout << m_field[x][y] <<std::endl;
	if (m_field[iswall.X][iswall.Y] == '#')
		return true;
	else
		return false;
}

bool Field::isTank(COORD tank)
{
	//if ((m_field[x][y] == '@' || m_field[c1.X][c1.Y]=='*') && m_field[c1.X][c1.Y]!='#')
		//return true;
	if ((tank.X == player.X && tank.Y==player.Y) || (tank.X == enemy.X && tank.Y == enemy.Y))
		return true;
	else
		return false;
}

void Field::Win()
{
	system("cls");
	std::cout << "\n\n\t\t CONGRATULATION!!! YOU WIN!!!";
	exit(0);
}

void Field::setCOORD(COORD pl, COORD en)
{
	player.X = pl.X;
	player.Y = pl.Y;
	enemy.X = en.X;
	enemy.Y = en.Y;
}


Field::~Field()
{
}
