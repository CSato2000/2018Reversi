#include "SearchPut.h"

#define FALSE 0
#define TRUE 1

int SearchPut(x, y) {

	//マスの周りを調べる配列
	static int checkOrder[8][2] = { { -1,0 },{ -1,1 },{ 0,1 },{ 1,1 },{ 1,0 },{ 1,-1 },{ 0,-1 },{ -1,-1 } };
	int i;			//カウント用
	int cx, cy;		//調べる用
	int turnRev;	//現在ターンの逆
	int putJudge;	//置けるかどうか 置ける：TRUE / 置けない：FALSE

	/* マスの周りを調べる */
	for (i = 0; i < 8; i++) {

		cx = checkOrder[i][1];
		cy = checkOrder[i][0];

		turnRev = (turn == WHITE ? BLACK : WHITE);		//現在のターンの逆の色

		/* 調べた先が相手のマスならその先を調べる */
		while (MassData[y + cy][x + cx].type == turnRev) {

			//調べた先が相手の色でその先が自分の色なら置ける
			if (MassData[y + cy + cy][x + cx + cx].type == turn) {

				MassData[y][x].putflag = TRUE;
				putJudge = TRUE;

			}

			//次の準備
			cx += checkOrder[i][1];
			cy += checkOrder[i][0];

		}
	}
	if (putJudge == TRUE) return TRUE;
	return FALSE;
}