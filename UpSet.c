#include "UpSet.h"
#include "AllCheckPut.h"


/********************************************************************************
関数名:void UpSet(int int)
内容：この関数が呼び出されたら、指定された場所から挟める範囲のコマをひっくり返す
引数:int x,int y
戻り値：なし
*********************************************************************************/
void UpSet(int x, int y) {
	if (MassData[x][y].putflag == 1) {
		if (MassData[x][y].type == BLACK) {
			//ブラシの色を白にする
			;
		}
		else if (MassData[x][y].type == WHITE) {
			//ブラシの色を黒にする
			;
		}
	}

	/*
	・構造体の全体を見てputflagがonのところをみる
	・putflagがonでturnと周囲のコマのtypeが違ったら、そのコマの色を変える
	⇒白なら黒、黒なら白に描画させる
	・
	*/
}