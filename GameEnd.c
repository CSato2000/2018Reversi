#include "GameEnd.h"

static int winner;

//�I������Ƃ��ɌĂ΂��A���҂̔���
void GameEnd() {
		if (blackframe < whiteframe) { winner = WHITE; }
		if (blackframe > whiteframe) { winner = BLACK; }
		if (blackframe == whiteframe) { winner = DRAW; }

		sceneFlag = RESULT;

}

//UI�ɌĂ΂��
int GetWinner() { return winner; }
