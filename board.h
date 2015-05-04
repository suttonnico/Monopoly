#ifndef BOARD_H
#define BOARD_H
#include <string>
#include "al.h"
using namespace std;

#define HEIGHT 1000
#define WIDTH (HEIGHT * 1.3)	//FALTARIA HACERLO UN POCO MAS ANCHO PARA PONER LOS DATOS DEL JUEGO, ESTO ES SOLO DE PRUEBA
								//AGREGUE 30% A LA DERECHA PARA VER COMO SE VEIA.

typedef struct
{
	string name;
	char group;
	short price, buildCost, rent [6];	//RENT COST PER BUILT BUILDING
} land;

class board
{
public:

	board (bitmap);
	void print (void);
private:

	void initBoard ();
	land boardArray [40];
	bitmap b;
};

#endif