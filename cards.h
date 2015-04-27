#ifndef CARDS_H
#define CARDS_H
#include <string>
using namespace std;

struct card
{
	string text;
	unsigned char code;
};

class cardsDeck
{
public:
	cardsDeck ();
	card chance ();
	card communityChest ();
	bool isChance (card c);
	bool isCommunityChest (card c);
private:
	void initDeck ();
	card deck [30];
	bool getOutOfJailChance;
	bool getOutOfJailCommunityChest;
};

#endif