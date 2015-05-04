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

board::board ()
{
	initBoard ();
	b = al_load_bitmap("Resources\\board.jpg");
}

void board::initBoard ()
{
	//...
}

void board::print(void)
{
	al_draw_scaled_bitmap(b, 0, 0, 1494, 1494, 0, 0, WIDTH, HEIGHT, 0);
}