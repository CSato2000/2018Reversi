#include "AllCheckPut.h"
#include "SearchPut.h"
#include "GameEnd.h"

#define FALSE 0
#define TRUE 1

int AllCheckPut(gameEndJudge) {

	int x, y;	//マスの座標
	int putJudge; //置ける：TRUE / 置けない：FALSE

				/* すべてのマスを調べる */
	for (y = 1; y <= 8; y++) {
		for (x = 1; x <= 8; x++) {

			if (MassData[y][x].putflag == TRUE) {
				MassData[y][x].putflag = FALSE;		//前回の置けるマスのリセット
			}

			if (MassData[y][x].type == EMPTY) {
				putJudge = SearchPut(x, y);	//SearchPut呼び出し
			}
		}
	}

	//置ける場所がなかったらターン交代
	if (putJudge != TRUE) {
		if (gameEndJudge == TRUE) {
			GameEnd();
			return 0;
		}

		gameEndJudge = FALSE;
		turn = (turn == WHITE ? BLACK : WHITE);
		AllCheckPut(TRUE);

	}

	return 0;
}