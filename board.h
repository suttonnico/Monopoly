#ifndef BOARD_H
#define BOARD_H
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_audio.h>
#include <allegro5\allegro_acodec.h>

#include "cards.h"
#include "board.h"
#include "player.h"
using namespace std;

#define WIDTH 1000	//FALTARIA HACERLO UN POCO MAS ANCHO PARA PONER LOS DATOS DEL JUEGO, ESTO ES SOLO DE PRUEBA
#define HEIGHT 1000
typedef ALLEGRO_BITMAP* bitmap;
typedef ALLEGRO_DISPLAY* display;
typedef ALLEGRO_EVENT_QUEUE* eventQueue;
typedef ALLEGRO_TIMER* timer;
typedef ALLEGRO_FONT* font;
void main_menu(font);

struct land
{
	string name;
	char group;
	short price, buildCost, rent [6]; //RENT COST PER BUILT BUILDING
};

class board
{
public:
	board ();
	void print(void);
private:
	void initBoard ();
	land boardArray [40];
	bitmap b;
};

#endif