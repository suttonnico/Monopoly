#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "al.h"
#include "cards.h"
#include "board.h"
#include "player.h"
using namespace std;

#define D 7.8

typedef struct
{
	bitmap icon, stewie, brian, board;
	display display;
	eventQueue eventQueue;
	timer timer;
	font font;
} resources;

bool init (resources&);
void shutdown (resources&);
void move1 (player&, player, board);
void main_menu (resources&);
void update_display (player, player, board);
void movex (player&, player, board, int);

void main (void)
{
	resources res;
	if (init (res))
	{
		main_menu (res);
		shutdown (res);
	}
}
	
void main_menu (resources& res)
{
	player p1 (res . stewie);
	player p2 (res . brian);
	board b (res . board);
	movex (p2, p1, b, 41);

	al_rest (5);
}

void update_display (player p1, player p2, board b)
{
	b . print ();
	p1 . print ();
	p2 . print ();
	al_flip_display ();
}

void move1 (player& p1, player p2, board b)
{
	float dx, dy;
	if (p1 . pos < 10)
	{
		dy = 0;
		dx = -D;
	}
	if ((p1 . pos < 20) && (p1 . pos >= 10))
	{
		dy = -D;
		dx = 0;
	}
	if ((p1 . pos < 30) && (p1 . pos >= 20))
	{
		dy = 0;
		dx = D;
	}
	if (p1 . pos >= 30)
	{
		dy = D;
		dx = 0;
	}
	for (int i = 0; i <= 10; i++)
	{
		p1 . x += dx;
		p1 . y += dy;
		update_display (p1, p2, b);
		al_rest (0.1);
	}
	p1 . pos++;
	if (p1 . pos > 39)
		p1 . pos = 0;
	
}

void movex (player&p1, player p2, board b, int x)
{
	int i;
	for (i = 0; i < x; i++)
	{
		move1 (p1, p2, b);
		al_rest (0.2);
	}
}

bool init (resources& res)
{
	srand (time (NULL));
	if (al_init ())
	{
		if (al_init_image_addon ())
		{
			if (res . icon = al_load_bitmap ("Resources\\icon.png"))
			{
				if (res . display = al_create_display (WIDTH, HEIGHT))
				{
					al_set_window_position (res . display, 7, 7);
					al_set_window_title (res . display, "Monopoly - Family Guy edition");
					al_set_display_icon (res . display, res . icon);
					if (res . stewie = al_load_bitmap ("Resources\\stewie3.png"))
					{
						if (res . brian = al_load_bitmap ("Resources\\brian.png"))
						{
							if (res . board = al_load_bitmap ("Resources\\board.jpg"))
							{
								if (res . eventQueue = al_create_event_queue ())
								{
									al_register_event_source (res . eventQueue, al_get_display_event_source (res . display));
									if (al_install_keyboard ())
									{
										al_register_event_source (res . eventQueue, al_get_keyboard_event_source ());
										if (al_install_mouse ())
										{
											al_register_event_source (res . eventQueue, al_get_mouse_event_source ());
											if (res . timer = al_create_timer (1))
											{
												al_register_event_source (res . eventQueue, al_get_timer_event_source (res . timer));
												if (al_init_primitives_addon ())
												{
													al_init_font_addon ();
													if (al_init_ttf_addon ())
													{
														res . font = al_load_ttf_font ("Resources\\font.ttf", 20, 0);
														return true;
														al_destroy_font (res . font);
														al_shutdown_ttf_addon ();
													}
													else
														cerr << "Could not TTF addon." << endl;
													al_shutdown_font_addon ();
													al_shutdown_primitives_addon ();
												}
												else
													cerr << "Could not initiate primitives addon." << endl;
												al_unregister_event_source (res . eventQueue, al_get_timer_event_source (res . timer));
												al_destroy_timer (res . timer);
											}
											else
												cerr << "Could not create an Allegro timer." << endl;
											al_unregister_event_source (res . eventQueue, al_get_mouse_event_source ());
											al_uninstall_mouse ();
										}
										else
											cerr << "Could not install mouse." << endl;
										al_unregister_event_source (res . eventQueue, al_get_keyboard_event_source ());
										al_uninstall_keyboard ();
									}
									else
										cerr << "Could not install keyboard." << endl;
									al_unregister_event_source (res . eventQueue, al_get_display_event_source (res . display));
									al_destroy_event_queue (res . eventQueue);
								}
								else
									cerr << "Could not create an Allegro event queue." << endl;
								al_destroy_bitmap (res . board);
							}
							else
								cerr << "Could not load board.jpg" << endl;
							al_destroy_bitmap (res . brian);
						}
						else
							cerr << "Could not load brian.png" << endl;
						al_destroy_bitmap (res . stewie);
					}
					else
						cerr << "Could not load stewie3.png" << endl;
					al_destroy_display (res . display);
				}
				else
					cerr << "Could not create a display." << endl;
				al_destroy_bitmap (res . icon);
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

void shutdown (resources& res)
{
	al_destroy_font (res . font);
	al_shutdown_ttf_addon ();
	al_shutdown_font_addon ();
	al_shutdown_primitives_addon ();
	al_unregister_event_source (res . eventQueue, al_get_timer_event_source (res . timer));
	al_destroy_timer (res . timer);
	al_unregister_event_source (res . eventQueue, al_get_mouse_event_source ());
	al_uninstall_mouse ();
	al_unregister_event_source (res . eventQueue, al_get_keyboard_event_source ());
	al_uninstall_keyboard ();
	al_unregister_event_source (res . eventQueue, al_get_display_event_source (res . display));
	al_destroy_event_queue (res . eventQueue);
	al_destroy_bitmap (res . board);
	al_destroy_bitmap (res . brian);
	al_destroy_bitmap (res . stewie);
	al_destroy_display (res . display);
	al_destroy_bitmap (res . icon);
	al_shutdown_image_addon ();
	al_uninstall_system ();
}