#include "AllCheckPut.h"
#include "SearchPut.h"
#include "GameEnd.h"

#define FALSE 0
#define TRUE 0

int AllCheckPut() {

	int x, y;	//マスの座標

				/* すべてのマスを調べる */
	for (y = 1; y <= 8; y++) {
		for (x = 1; x <= 8; x++) {

			if (MassData[y][x].putflag == TRUE) {

				MassData[y][x].putflag = FALSE;		//前回の置けるマスのリセット
			}

			if (MassData[y][x] == EMPTY) SearchPut(x, y);	//SearchPut呼び出し

		}
	}

	return 0;
}