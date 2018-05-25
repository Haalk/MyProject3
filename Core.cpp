#include "Core.h"
#include <conio.h>
#include <iostream>


Core::Core() :mTank(), mBullet(), counter(0),en_Tank(), pl_bullet (0)
{
	m_field = new Field;
	m_field->loadField();
	m_field->drawField();
	
}


Core::~Core()
{
	delete m_field;
	m_field = nullptr;
}

void Core::execute()
{
	
	//char button = '0';
	if (true == _kbhit())
	{
		//button = _getch();
		switch (_getch())
		{
		case nButtons::LEFT:
			mTank.move(nDirection::edirection::LEFT,m_field);
			break;
		case nButtons::RIGHT:
			mTank.move(nDirection::edirection::RIGHT, m_field);
			break;
		case nButtons::UP:
			mTank.move(nDirection::edirection::UP, m_field);
			break;
		case nButtons::DOWN:
			mTank.move(nDirection::edirection::DOWN, m_field);
			break;
		case nButtons::SPACE:
			mBullet.push_back(mTank.fire());
			++counter;
			++pl_bullet;
			break;
		default:
			break;
		}
	}
	

	COORD en = en_Tank.coord_en();
	COORD pl = mTank.coord_pl();
	

	if (mBullet.size()==0 || pl_bullet==1)
	{
		if ((en.Y == pl.Y) && (en.X > pl.X))
		{
			en_Tank.setDir(nDirection::edirection::LEFT);
			mBullet.push_back(en_Tank.fire());
			counter++;
			//en_Tank.move(en_Tank.getDir(), m_field);
		}
		else if ((en.Y == pl.Y) && (en.X < pl.X))
		{
			en_Tank.setDir(nDirection::edirection::RIGHT);
			mBullet.push_back(en_Tank.fire());
			counter++;
			//en_Tank.move(en_Tank.getDir(), m_field);
		}
		else if ((en.Y > pl.Y) && (en.X == pl.X))
		{
			en_Tank.setDir(nDirection::edirection::UP);
			mBullet.push_back(en_Tank.fire());
			counter++;
			//en_Tank.move(en_Tank.getDir(), m_field);
		}
		else if ((en.Y < pl.Y) && (en.X == pl.X))
		{
			en_Tank.setDir(nDirection::edirection::DOWN);
			mBullet.push_back(en_Tank.fire());
			counter++;
			//en_Tank.move(en_Tank.getDir(), m_field);
		}
		//++en_bullet;
	}
	//else
		//--en_bullet;
	int magic_num = rand();
	

	if (magic_num >0 && magic_num <5)
	{
		int move = rand() % 5;
		switch (move)
		{

		case 0:
			en_Tank.move(nDirection::edirection::LEFT, m_field);
			break;
		case 1:
			en_Tank.move(nDirection::edirection::RIGHT, m_field);
			break;
		case 2:
			en_Tank.move(nDirection::edirection::UP, m_field);
			break;
		case 3:
			en_Tank.move(nDirection::edirection::DOWN, m_field);
			break;
		default:
			break;
			//Sleep(50);
		}
	}


	if (!mBullet.empty())
	{
		for (int i = 0; i < counter; i++)
		{
			if (mBullet[i].move(m_field));
			else
			{
				mBullet.erase(mBullet.begin() + i);
				--counter;
				pl_bullet = 0;
			}
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), en_Tank.coord_en());
			std::cout << "@";
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), mTank.coord_pl());
			std::cout << "*";
		}
		Sleep(50);
	}
	//Sleep(100);
	//if()
	m_field->setCOORD(mTank.coord_pl(), en_Tank.coord_en());
}

