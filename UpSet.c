#include "UpSet.h"
#include "AllCheckPut.h"


/********************************************************************************
関数名：void UpSet(int x,int y)
機能；指定された場所から挟める範囲のコマをひっくり返す
引数：int x,y
戻り値：なし
*********************************************************************************/

void UpSet(int x, int y) {
	static	int checkRotation[8][2] = { { -1,-1 },{ 0,-1 },{ 1,-1 },{ 1,0 },{ 1,1 },{ 0,1 },{ -1,1 },{ -1,0 } };
	typeRev = (turn == WHITE ? BLACK : WHITE);
	revCount = 0;
	backCount = 0;
	revPosX[40] = 0;
	revPosY[40] = 0;

	//周囲8方向分ひっくり返す
	for (int i = 0; i < 8; i++) {

		revCount = 0;
		backCount = 0;

		//調べるマスの場所(周囲8砲口)
		cx = checkRotation[i][0];
		cy = checkRotation[i][1];

		//調べるマスが自分のコマの場所になるまで
		while (MassData[x + cx][y + cy].type !=turn && MassData[x + cx][y + cy].type != EMPTY) {

			//もし先のマスに相手のコマが置いてあったら
			if (MassData[y + cy + cy][x + cx + cx].type == typeRev) {

				//相手のコマだった場合はrevCount++,backCount++
				revCount++;
				backCount++;

				//座標をrevPosの中に保存する
				revPosX[i] = x+cx;
				revPosY[i] = y+cy;
			}
		}

		//もし最後が何もないマスだったらカウントを戻す
		if (MassData[x + cx + cx][y + cy + cy].type = EMPTY) {
			revCount -= backCount;
		}

		//ひっくりかえす
		for (int j = 0; j < revCount; j++) {
			//配列の座標に合わせてtypeを変える
			MassData[revPosX[j]][revPosY[j]].type = turn;
		}

		//方向の切り替え
		cx += checkRotation[i][0];
		cy += checkRotation[i][1];

	}
}