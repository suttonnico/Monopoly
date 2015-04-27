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
using namespace std;

#define WIDTH 1000	//FALTARIA HACERLO UN POCO MAS ANCHO PARA PONER LOS DATOS DEL JUEGO, ESTO ES SOLO DE PRUEBA
#define HEIGHT 1000
typedef ALLEGRO_BITMAP* bitmap;
typedef ALLEGRO_DISPLAY* display;
typedef ALLEGRO_EVENT_QUEUE* eventQueue;
typedef ALLEGRO_TIMER* timer;
typedef ALLEGRO_FONT* font;

bool init (bitmap* icon, bitmap* board, display* display, eventQueue* eventQueue, timer* timer)
{
	srand (time (NULL));
	if (al_init ())
	{
		if (al_init_image_addon ())
		{
			if (*icon = al_load_bitmap ("Resources\\icon.png"))
			{
				if (*display = al_create_display (WIDTH, HEIGHT))
				{
					al_set_display_icon (*display, *icon);
					if (*board = al_load_bitmap ("Resources\\board.jpg"))
					{
						al_draw_scaled_bitmap (*board, 0, 0, 1494, 1494, 0, 0, WIDTH, HEIGHT, 0);
						al_flip_display ();
						al_set_window_position (*display, 7, 7);
						al_set_window_title (*display, "Monopoly - Family Guy edition");
						if (*eventQueue = al_create_event_queue ())
						{
							al_register_event_source (*eventQueue, al_get_display_event_source (*display));
							if (al_install_keyboard ())
							{
								al_register_event_source (*eventQueue, al_get_keyboard_event_source ());
								if (al_install_mouse ())
								{
									al_register_event_source (*eventQueue, al_get_mouse_event_source ());
									if (*timer = al_create_timer (1))
									{
										al_register_event_source (*eventQueue, al_get_timer_event_source (*timer));
										//
										al_rest(5);
										al_unregister_event_source (*eventQueue, al_get_timer_event_source (*timer));
										al_destroy_timer (*timer);
									}
									else
										cerr << "Could not create an Allegro timer" << endl;
									al_unregister_event_source (*eventQueue, al_get_mouse_event_source ());
									al_uninstall_mouse ();
								}
								else
									cerr << "Could not install mouse" << endl;
								al_unregister_event_source (*eventQueue, al_get_keyboard_event_source ());
								al_uninstall_keyboard ();
							}
							else
								cerr << "Could not install keyboard" << endl;
							al_unregister_event_source (*eventQueue, al_get_display_event_source (*display));
							al_destroy_event_queue (*eventQueue);
						}
						else
							cerr << "Could not create an Allegro event queue" << endl;
						al_destroy_bitmap (*board);
					}
					else
						cerr << "Could not load board.jpg" << endl;
					al_destroy_display (*display);
				}
				else
					cerr << "Could not create a display." << endl;
				al_destroy_bitmap (*icon);
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
	return false;
}
void main_menu (void);

void main (void)
{
	bitmap icon, board;
	display display;
	eventQueue eventQueue;
	timer timer;
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
										main_menu();
										al_rest(5);
										al_unregister_event_source (eventQueue, al_get_timer_event_source (timer));
										al_destroy_timer (timer);
									}
									else
										cerr << "Could not create an Allegro timer" << endl;
									al_unregister_event_source (eventQueue, al_get_mouse_event_source ());
									al_uninstall_mouse ();
								}
								else
									cerr << "Could not install mouse" << endl;
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
	
void main_menu (void)
{
	display menu;
	if (menu = al_create_display (800, 400))
		{
			al_clear_to_color(al_map_rgb(0, 100, 0));
			al_flip_display();
			al_rest(1);
		}
		else
			cerr << "Could not create a display." << endl;
				
}