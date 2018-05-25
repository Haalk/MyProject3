#pragma once
#include <vector>
#include "Helper.h"
#include <Windows.h>

class Field
{
public:
	Field();
	void loadField();
	void drawField();
	char getPoint(int, int) const;
	void setPoint(int, int,char);
	bool isWall(COORD);
	bool isTank(COORD);
	void Win();
	void setCOORD(COORD p, COORD e);
	~Field();
private:
	std::vector < std::vector<char >> m_field;
	COORD player;
	COORD enemy;
};

