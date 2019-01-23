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
	int typeRev = (turn == BLACK? WHITE : BLACK); //相手のターンの色
	int revCount = 0;  //ひっくり返す回数
	int backCount = 0;  //もどるときにつかう
	int revPosX[40] = {0};  //ひっくりかえすマスのx座標
	int revPosY[40] = {0};  //ひっくりかえすマスのy座標

	//周囲8方向分ひっくり返す
	for (int i = 0; i < 8; i++) {

		backCount = 0;

		//調べるマスの方向
		int cx = checkRotation[i][0];
		int cy = checkRotation[i][1];
		
		//調べるマスが自分のコマの場所になるまで
		while (1) {

			//もし先のマスに相手のコマが置いてあったら
			if (MassData[x + cx][y + cy].type == typeRev) {

				//座標をrevPosの中に保存する
				revPosX[revCount] = x + cx;
				revPosY[revCount] = y + cy;

				//相手のコマだった場合はrevCount++,backCount++
				revCount++;
				backCount++;

				//一つ先のマスへ進む
				cx += checkRotation[i][0];
				cy += checkRotation[i][1];

			}
			else if (MassData[x + cx][y + cy].type==turn && revCount!=0) { //一つ以上挟めるコマがあった場合
				//処理を抜ける
				break;
			}
			else { //もしなにも置かれていないマスだった場合
				//カウントを戻して処理を抜ける
				revCount -= backCount;
				break;
			}
		}
	}

	//ひっくりかえす
	for (int j = 0; j < revCount; j++) {
		//配列の座標に合わせてtypeを変える
		MassData[revPosX[j]][revPosY[j]].type = turn;
	}

	turn = typeRev;
	AllCheckPut(0);

}