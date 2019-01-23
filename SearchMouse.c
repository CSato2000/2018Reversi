#include "SearchMouse.h"
#include "GlobalNum.h"
#include "UpSet.h"

#define FALSE 0
#define TRUE 1

void SearchMouse(POINT pos, LPARAM lParam) {

	//クリック時のマウス座標取得
	pos.x = LOWORD(lParam);
	pos.y = HIWORD(lParam);

	int massX = pos.x / 50 + 1;
	int massY = pos.y / 50 + 1;

	//画面外は無視
	if (pos.x <= 0 || pos.x >= 400 || pos.y <= 0 || pos.y >= 400) return 0;

	//クリックしたマスに白を配置
	if (MassData[massX][massY].putflag == TRUE && turn == WHITE) {
		MassData[massX][massY].type = WHITE;
		turn = BLACK;
		whiteframe++;
		UpSet(massX, massY);
	}

	//クリックしたマスに黒を配置
	if (MassData[massX][massY].putflag == TRUE && turn == BLACK) {
		MassData[massX][massY].type = BLACK;
		turn = WHITE;
		blackframe++;
		UpSet(massX, massY);
	}
}