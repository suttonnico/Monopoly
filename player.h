#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "al.h"
using namespace std;

typedef struct
{
	float x, y;
}coords;

class player
{
public:
	
	player (bitmap);
	void print (void);
	int pos;
	float x;
	float y;
private:

	bitmap p;
};

#endif