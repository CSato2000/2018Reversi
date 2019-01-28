#include "UpSet.h"
#include "AllCheckPut.h"

void UpSet(int x, int y) {
	static	int checkRotation[8][2] = { { -1,-1 },{ 0,-1 },{ 1,-1 },{ 1,0 },{ 1,1 },{ 0,1 },{ -1,1 },{ -1,0 } };  //マスの周囲8方向
	int typeRev = (turn == BLACK? WHITE : BLACK); //相手のターンの色
	int revCount = 0;       //コマをひっくり返す数のカウント
	int revPosX[40] = {0};  //ひっくりかえすマスのx座標
	int revPosY[40] = {0};  //ひっくりかえすマスのy座標

	//周囲8方向分のひっくり返せるコマを探す
	for (int i = 0; i < 8; i++) {

		//カウントの初期化
		revCount = 0;

		//調べるマスの方向
		int cx = checkRotation[i][0];
		int cy = checkRotation[i][1];
		
		//調べるマスに相手のコマが置かれている間処理を行う
		while (1) {

			//もし先のマスに相手のコマが置いてあったら
			if (MassData[x + cx][y + cy].type == typeRev) {

				//座標をrevPosの中に保存する
				revPosX[revCount] = x + cx;
				revPosY[revCount] = y + cy;

				//相手のコマだった場合はrevCount++
				revCount++;

				//一つ先のマスへ進む
				cx += checkRotation[i][0];
				cy += checkRotation[i][1];

			}
			else if (MassData[x + cx][y + cy].type==turn && revCount!=0) { //自分のコマに当たり、かつ一つ以上挟めるコマがあった場合
				//処理を抜ける
				break;
			}
			else { //もしなにも置かれていないマスだった場合
				//カウントを戻して処理を抜ける
				revCount =0;
				break;
			}
		}//while文終了

		//コマをひっくり返す
		for (int j = 0; j < revCount; j++) {
			MassData[revPosX[j]][revPosY[j]].type = turn;
		}

	}//for文終了

	//相手のターンに切り替える
	turn = typeRev;

	//AllCheckPutの呼び出し
	AllCheckPut();

}