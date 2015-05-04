#ifndef PLAYER_H
#define PLAYER_H
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
typedef struct
{
	float x;
	float y;
}coords;

using namespace std;

class player
{
public:
	
	player(bitmap );
	void print(void);
	int pos;
	float x;
	float y;
private:
	bitmap p;


};

#endif