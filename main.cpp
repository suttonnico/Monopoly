#include <cstdio>
#include <cstdlib>
#include <cstdlib>
#include <ctime>
#include <iostream>
#define  ALLEGRO_STATICLINK
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_font.h>
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
#define D	7.8
typedef ALLEGRO_BITMAP* bitmap;
typedef ALLEGRO_DISPLAY* display;
typedef ALLEGRO_EVENT_QUEUE* eventQueue;
typedef ALLEGRO_TIMER* timer;
typedef ALLEGRO_FONT* font;

void move1(player*,player,board);
void main_menu (font);
void update_display(player p1, player p2, board b);
void movex(player*p1, player p2, board b, int x);

void main (void)
{
	bitmap icon, board;
	display display;
	eventQueue eventQueue;
	timer timer;
	font font;
	srand (time (NULL));
	if (al_init ())
	{
		if (al_init_image_addon ())
		{
			if (icon = al_load_bitmap ("Resources\\icon.png"))
			{
				if (display = al_create_display (WIDTH, HEIGHT))
				{
					al_set_display_icon (display, icon);
					if (board = al_load_bitmap ("Resources\\board.jpg"))
					{
						al_draw_scaled_bitmap (board, 0, 0, 1494, 1494, 0, 0, WIDTH, HEIGHT, 0);
						al_flip_display ();
						al_set_window_position (display, 7, 7);
						al_set_window_title (display, "Monopoly - Family Guy edition");
						if (eventQueue = al_create_event_queue ())
						{
							al_register_event_source (eventQueue, al_get_display_event_source (display));
							if (al_install_keyboard ())
							{
								al_register_event_source (eventQueue, al_get_keyboard_event_source ());
								if (al_install_mouse ())
								{
									al_register_event_source (eventQueue, al_get_mouse_event_source ());
									if (timer = al_create_timer (1))
									{
										al_register_event_source (eventQueue, al_get_timer_event_source (timer));
										//
										al_init_primitives_addon();
										al_init_font_addon(); // initialize the font addon					PONER PROLIJOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
										al_init_ttf_addon();// initialize the ttf (True Type Font) addon
										font = al_load_ttf_font("Resources\\font.ttf",20,0 );
										//main_menu(font);
										//al_draw_filled_rounded_rectangle(0,50,880,100,25,25,al_map_rgb(0,255,0));
										
										//al_clear_to_color(al_map_rgb(255,255,255));
										al_flip_display();
										main_menu(font);
										al_rest(5);
										al_unregister_event_source (eventQueue, al_get_timer_event_source (timer));
										al_destroy_timer (timer);
															//EMPROLIJAR <<<<<<<----------------------------------------------------------------------
										//al_shutdown_ttf_addon ();
										al_shutdown_font_addon ();
									}
									else
										cerr << "Could not create an Allegro timer" << endl;
									al_unregister_event_source (eventQueue, al_get_mouse_event_source ());
									al_uninstall_mouse ();
								}
								else
									cerr << "Could not install mouse" << endl;
								//al_shutdown_font_addon ();					//EMPROLIJAR <<<<<<<----------------------------------------------------------------------
								//al_shutdown_ttf_addon ();
								al_unregister_event_source (eventQueue, al_get_keyboard_event_source ());
								al_uninstall_keyboard ();
							}
							else
								cerr << "Could not install keyboard" << endl;
							al_unregister_event_source (eventQueue, al_get_display_event_source (display));
							al_destroy_event_queue (eventQueue);
						}
						else
							cerr << "Could not create an Allegro event queue" << endl;
						al_destroy_bitmap (board);
					}
					else
						cerr << "Could not load board.jpg" << endl;
					al_destroy_display (display);
				}
				else
					cerr << "Could not create a display." << endl;
				al_destroy_bitmap (icon);
			}
			else
				cerr << "Could not load icon.png." << endl;
			al_shutdown_image_addon ();
		}
		else
			cerr << "Could not start Allegro image addon." << endl;
		al_uninstall_system ();
	}
	else
		cerr << "Could not start Allegro library." <<endl;
	
}
	
void main_menu (font font)
{
	bitmap stewie;
	stewie = al_load_bitmap("Resources\\stewie3.png");
	player p1(stewie);
	bitmap brian;
	brian = al_load_bitmap("Resources\\brian.png");
	player p2(brian);
	board b;
	movex(&p2, p1, b, 41);

	al_rest(1);

}



void update_display(player p1, player p2,board b)
{
	b.print();
	p1.print();
	p2.print();
	al_flip_display();
}


void move1(player* p1,player p2,board b)
{
	float dx, dy;
	if (p1->pos < 10)
	{
		dy = 0;
		dx = -D;
	}
	if ((p1->pos < 20) && (p1->pos >= 10))
	{
		dy = -D;
		dx = 0;
	}
	if ((p1->pos < 30) && (p1->pos >= 20))
	{
		dy = 0;
		dx = D;
	}
	if (p1->pos >= 30)
	{
		dy = D;
		dx = 0;
	}
	for (int i = 0; i <= 10; i++)
	{
		p1->x += dx;
		p1->y += dy;
		update_display(*p1, p2, b);
		al_rest(0.1);
	}
	p1->pos++;
	if (p1->pos > 39)
		p1->pos = 0;
	
}

void movex(player*p1, player p2, board b,int x)
{
	int i;
	for (i = 0; i < x; i++)
	{
		move1(p1, p2, b);
		al_rest(0.2);
	}
}