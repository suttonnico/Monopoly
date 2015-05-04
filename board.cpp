#include "board.h"

board::board (bitmap b)
{
	this -> b = b;
	initBoard ();
}

void board::initBoard ()
{
	//...
}

void board::print (void)
{
	al_draw_scaled_bitmap (b, 0, 0, 1494, 1494, 0, 0, HEIGHT, HEIGHT, 0);
}