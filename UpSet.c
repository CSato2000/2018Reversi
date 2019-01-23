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
	revCount = 0;
	typeRev = (turn == WHITE ? BLACK : WHITE);
	revPosX[40] = 0;
	revPosY[40] = 0;

	//周囲8方向分ひっくり返す
	for (int i = 0; i < 8; i++) {

		//調べるマスの場所(周囲8砲口)
		cx = checkRotation[i][0];
		cy = checkRotation[i][1];

		//調べるマスが自分のコマの場所になるまで
		while (MassData[x + cx][y + cy].type == typeRev) {

			//もし先のマスに相手のコマが置いてあったら
			if (MassData[y + cy + cy][x + cx + cx].type == turn) {
				//その先のマスの状態が自分のコマか空白のマスになるまで調べる
				//相手のコマだった場合はrevCount++
				revCount++;
				//座標をrevPosの中に保存する
				//もし最後が何もないマスだったらカウントを戻す
			}
		}

		//ひっくりかえす
		for (int k = 0; k < revCount; k++) {
			//配列の座標に合わせてtypeを変える
			MassData[revPosX[k]][revPosY[k]].type = turn;
		}
			
		//カウントの初期化
		revCount = 0;

		//配列の中身の初期化
		revPosX[10] = 0;
		revPosY[10]= 0;

		//方向の切り替え
		cx += checkRotation[i][0];
		cy += checkRotation[i][1];

	}
}