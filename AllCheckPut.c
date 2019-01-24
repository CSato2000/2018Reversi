#include "AllCheckPut.h"
#include "SearchPut.h"
#include "GameEnd.h"

#define FALSE 0
#define TRUE 1

int AllCheckPut() {

	int x, y;	//マスの座標
	int putJudge = FALSE; //置ける：TRUE / 置けない：FALSE
	int putJudgeFlg = FALSE; //上記と同じ

	/* すべてのマスを調べる */
	for (y = 1; y <= 8; y++) {
		for (x = 1; x <= 8; x++) {

			if (MassData[y][x].putflag == TRUE) {
				MassData[y][x].putflag = FALSE;		//前回の置けるマスのリセット
			}

			if (MassData[y][x].type == EMPTY) {
				putJudge = SearchPut(x, y);		//SearchPut呼び出し
				if (putJudgeFlg != TRUE) putJudgeFlg = putJudge;
			}
		}
	}

	//置ける場所がなかったらターン交代
	if (putJudgeFlg != TRUE) {

		if (putJudgeCnt >= 2) {
			GameEnd();
			return 0;
		}

		putJudgeCnt++;
		turn = (turn == WHITE ? BLACK : WHITE);
		AllCheckPut();

		int onButton;
		onButton = MessageBox(NULL, TEXT("置けませんでした\nターンをパスします"),
			TEXT("メッセージ"), MB_OK);

	}

	return 0;
}