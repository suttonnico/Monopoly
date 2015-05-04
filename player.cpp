#include "player.h"
#include <string>
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_audio.h>
#include <allegro5\allegro_acodec.h>

typedef ALLEGRO_BITMAP* bitmap;
typedef ALLEGRO_DISPLAY* display;
typedef ALLEGRO_EVENT_QUEUE* eventQueue;
typedef ALLEGRO_TIMER* timer;
typedef ALLEGRO_FONT* font;
using namespace std;

#define P0X 880
#define P0Y 875
#define P1	800,875
#define D	80/10

player::player(bitmap p)
{
	pos = 0;
	this->p = p;
	x = P0X;
	y = P0X;
	print();
}

void player::print(void)
{
	al_draw_bitmap(p, x, y, 0);
}

