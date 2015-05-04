#include "player.h"

#define P0X 880
#define P0Y 875
#define P1	800,875
#define D	80/10

player::player (bitmap p)
{
	pos = 0;
	this -> p = p;
	x = P0X;
	y = P0X;
	print ();
}

void player::print (void)
{
	al_draw_bitmap (p, x, y, 0);
}

