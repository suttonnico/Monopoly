#include "cards.h"
#include <ctime>
#include <cstdlib>

cardsDeck::cardsDeck ()
{
	initDeck ();
	getOutOfJailChance = false;
	getOutOfJailCommunityChest = false;
}

void cardsDeck::initDeck ()
{
	// [0..13] WHAT THE DEUCE?
	// [14..29] GIGGITY! GIGGITY! GIGGITY!
	deck [0]  . code = 0x01;
	deck [0]  . text = "Advance Token to Nearest Utility";
	deck [1]  . code = 0x02;
	deck [1]  . text = "Advance Token to the Nearest Railroad";
	deck [2]  . code = 0x03;
	deck [2]  . text = "Advance Token to the Nearest Railroad";
	deck [3]  . code = 0x04;
	deck [3]  . text = "Advance to Geronimo's Palace";
	deck [4]  . code = 0x05;
	deck [4]  . text = "Collect $50";
	deck [5]  . code = 0x06;
	deck [5]  . text = "Go Back 3 Spaces";
	deck [6]  . code = 0x07;
	deck [6]  . text = "Go Directly to Church";
	deck [7]  . code = 0x08;
	deck [7]  . text = "For each house pay $25. For each hotel pay $100";
	deck [8]  . code = 0x09;
	deck [8]  . text = "Collect $15";
	deck [9]  . code = 0x0A;
	deck [9]  . text = "Advance Token to Peter's Fishing Boat";
	deck [10] . code = 0x0B;
	deck [10] . text = "Advance Token to Petoria";
	deck [11] . code = 0x0C;
	deck [11] . text = "Pay $50 to the other player";
	deck [12] . code = 0x0D;
	deck [12] . text = "Collect $150";
	deck [13] . code = 0xFE;
	deck [13] . text = "Get Out of Church Free";
	deck [14] . code = 0x10;
	deck [14] . text = "Advance to GO";
	deck [15] . code = 0x11;
	deck [15] . text = "Collect $200";
	deck [16] . code = 0x12;
	deck [16] . text = "Pay $50";
	deck [17] . code = 0x13;
	deck [17] . text = "Collect $45";
	deck [18] . code = 0x14;
	deck [18] . text = "Go to Church";
	deck [19] . code = 0x15;
	deck [19] . text = "Collect $50 from the other player";
	deck [20] . code = 0x16;
	deck [20] . text = "Collect $20";
	deck [21] . code = 0x17;
	deck [21] . text = "Collect $100";
	deck [22] . code = 0x18;
	deck [22] . text = "Pay $100";
	deck [23] . code = 0x19;
	deck [23] . text = "Pay $150";
	deck [24] . code = 0x1A;
	deck [24] . text = "Collect $25";
	deck [25] . code = 0x1B;
	deck [25] . text = "Collect $100";
	deck [26] . code = 0x1C;
	deck [26] . text = "For each house pay $40. For each hotel pay $115";
	deck [27] . code = 0x1D;
	deck [27] . text = "Collect $10";
	deck [28] . code = 0x1E;
	deck [28] . text = "Collect $100";
	deck [29] . code = 0xFF;
	deck [29] . text = "Get Out of Church Free";
}

card cardsDeck::chance ()	//WHAT THE DEUCE?
{
	char card = rand () % (14 - getOutOfJailChance);
	if (card == 13)
		getOutOfJailChance = true;
	return deck [card];
}

card cardsDeck::communityChest ()	//GIGGITY! GIGGITY! GIGGITY!
{
	char card = 14 + rand () % (16 - getOutOfJailCommunityChest);
	if (card == 29)
		getOutOfJailCommunityChest = true;
	return deck [card];
}

bool cardsDeck::isChance (card c)
{
	if (c . code < 0x0F || c . code == 0xFE)
		return true;
	else return false;
}

bool cardsDeck::isCommunityChest (card c)
{
	return !isChance (c);
}