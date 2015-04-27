#ifndef BOARD_H
#define BOARD_H
#include <string>
using namespace std;

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
private:
	void initBoard ();
	land boardArray [40];
};

#endif