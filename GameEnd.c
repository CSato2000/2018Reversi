#include "GameEnd.h"

static int winner=0;

void GameEnd() {
		if (blackframe < whiteframe) { winner = WHITE; }
		if (blackframe > whiteframe) { winner = BLACK; }
		if (blackframe == whiteframe) { winner = 0; }
}

int GetWinner() { return winner; }
