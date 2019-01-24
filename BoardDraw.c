#include "BoardDraw.h"

void BoardDraw(HWND hWnd) {

	//宣言
	static HDC hdc;
	static PAINTSTRUCT ps;
	static HBRUSH hBrush[5];
	static initFlag;
	
	if (initFlag == 0) {
		hBrush[0] = CreateSolidBrush(RGB(0, 0xAA, 0));          // 盤面（緑）
		hBrush[1] = CreateSolidBrush(RGB(0xFF, 0xFF, 0xFF));    // WHITE
		hBrush[2] = CreateSolidBrush(RGB(0, 0, 0));		        // BLACK
		hBrush[3] = CreateSolidBrush(RGB(0xAA, 0xAA, 0xAA));
		hBrush[4] = CreateSolidBrush(RGB(0xFF, 0xFF, 0x14));
		initFlag = 1;
	}

	static POINT dot[4] = {
		{ 100,100 },
	{ 300,100 },
	{ 100,300 },
	{ 300,300 }
	};

	//ペイントハンドルの作成
	hdc = BeginPaint(hWnd, &ps);


	// オセロ盤の描画

	SelectObject(hdc, hBrush[0]);
	Rectangle(hdc, 0, 0, 401, 401);

	for (int i = 0; i < 7; i++) {
		MoveToEx(hdc, 50 * (i + 1), 0, NULL);
		LineTo(hdc, 50 * (i + 1), 400);
		MoveToEx(hdc, 0, 50 * (i + 1), NULL);
		LineTo(hdc, 400, 50 * (i + 1));
	}

	//キーの選択位置
	SelectObject(hdc, hBrush[3]);
	Rectangle(hdc, keyPos.x * 50, keyPos.y * 50, (keyPos.x + 1) * 50 + 1, (keyPos.y + 1) * 50 + 1);


	//置けるマスを表示
	SelectObject(hdc, hBrush[4]);
	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= 8; j++) {
			if (MassData[i][j].putflag == 1) {
				//Rectangle(hdc, (i - 1) * 50, (j - 1) * 50, i * 50 + 1, j * 50 + 1);
				Ellipse(hdc, (i - 1) * 50+15, (j - 1) * 50+15, i * 50-15, j * 50-15);
			}
		}
	}

	


	//小さな黒丸の描画
	SelectObject(hdc, hBrush[2]);
	for (int i = 0; i < 4; i++) {
		Ellipse(hdc, dot[i].x - 5, dot[i].y - 5,
			dot[i].x + 5, dot[i].y + 5);
	}

	blackframe = 0;
	whiteframe = 0;

	// オセロ盤の表示
	for (int i = 1; i < 9; i++) {
		for (int j = 1; j < 9; j++) {
			if (MassData[i][j].type != EMPTY) {
				if (MassData[i][j].type == WHITE) {
					SelectObject(hdc, hBrush[1]);  //白
					whiteframe++;
				}
				else if (MassData[i][j].type == BLACK) {
					SelectObject(hdc, hBrush[2]);  //黒
					blackframe++;
				}
				Ellipse(hdc, (i - 1) * 50, (j - 1) * 50, i * 50, j * 50);

			}
		}
	}
	EndPaint(hWnd, &ps);
}