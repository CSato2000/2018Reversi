#include "GameEnd.h"

static int winner;

//I‚í‚Á‚½‚Æ‚«‚ÉŒÄ‚Î‚ê‚éAŸÒ‚Ì”»•Ê
void GameEnd() {
		if (blackframe < whiteframe) { winner = WHITE; }
		if (blackframe > whiteframe) { winner = BLACK; }
		if (blackframe == whiteframe) { winner = DRAW; }

		sceneFlag = RESULT;

}

//UI‚ÉŒÄ‚Î‚ê‚é
int GetWinner() { return winner; }
