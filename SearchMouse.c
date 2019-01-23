#include "SearchMouse.h"

void SearchMouse(POINT pos) {
	
	//クリック時のマウス座標取得
	pos.x = LOWORD(lParam);
	pos.y = HIWORD(lParam);

	//画面外は無視
	if (pos.x <= 0 || pos.x >= 400 || pos.y <= 0 || pos.y >= 400) return 0;

	//クリックしたマスに白を配置
	if (MassData[pos.x / 50 + 1][pos.y / 50 + 1].putflag == TRUE && turn == WHITE) {
		MassData[pos.x / 50 + 1][pos.y / 50 + 1].type = WHITE;

	}

	//クリックしたマスに黒を配置
	if (MassData[pos.x / 50 + 1][pos.y / 50 + 1].putflag == TRUE && turn == BLACK) {
		MassData[pos.x / 50 + 1][pos.y / 50 + 1].type = BLACK;

	}

	//PAINTイベントを発生させる
	InvalidateRect(hWnd, NULL, FALSE);

}