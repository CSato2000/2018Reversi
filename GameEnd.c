#include "GameEnd.h"

static int winner;
static int gameEndFlg=FALSE;

void GameEnd() {
	if (blackframe + whiteframe == 64) { gameEndFlg = TRUE; }
	if (gameEndFlg == TRUE) {
		if (blackframe < whiteframe) { winner = WHITE; }
		if (blackframe > whiteframe) { winner = BLACK; }
		if (blackframe == whiteframe) { winner = 0; }
	}
}

int GetWinner() { return winner; }
int GetGameEnd() { return gameEndFlg; }
void SetGameEnd(tmp) { gameEndFlg = tmp; }