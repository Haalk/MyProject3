#pragma once

namespace nDirection
{
	const enum edirection { UP, DOWN, LEFT, RIGHT };
}
namespace nButtons
{
	const int LEFT = 75;
	const int RIGHT = 77;
	const int DOWN = 80;
	const int UP = 72;
	const int SPACE = 32;
}

const int SIZE_FIELD = 25;

struct Position
{
	int x;
	int y;
};

enum nOwner
{
	USER,
	ENEMY
};