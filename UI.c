#include "UI.h"

void UI(hWnd) {

	//ハンドルの取得
	HDC hdc;
	HFONT hFont;
	hdc = GetDC(hWnd);

	//文字列
	LPTSTR lptStr1 = TEXT("黒のターンです");
	LPTSTR lptStr2 = TEXT("白のターンです");
	LPTSTR lptStr3 = TEXT("黒の勝ちです");
	LPTSTR lptStr4 = TEXT("白の勝ちです");
	LPTSTR lptStr5 = TEXT("引き分けです");
	LPTSTR lptStr6 = TEXT("　　　　　　　　　　");
	LPTSTR lptStr7 = TEXT("再戦 ： ENTER");

	//フォントを生成
	hFont = CreateFont(
		40, 0, 0, 0, FW_BOLD, TRUE, FALSE, FALSE,
		SHIFTJIS_CHARSET, OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		VARIABLE_PITCH | FF_ROMAN, NULL
	);

	//くそでかフォント
	SelectObject(hdc, hFont);

	//ターン表示
	if (turn == BLACK)TextOut(hdc, 460, 10, lptStr1, lstrlen(lptStr1));
	if (turn == WHITE)TextOut(hdc, 460, 10, lptStr2, lstrlen(lptStr2));

	//普通のフォント
	SelectObject(hdc, GetStockObject(SYSTEM_FONT));

	if (sceneFlag == RESULT) {


		//勝利者表示
		//くそでかフォント
		SelectObject(hdc, hFont);

		if (GetWinner() == BLACK) { TextOut(hdc, 460, 210, lptStr3, lstrlen(lptStr3)); }
		if (GetWinner() == WHITE) { TextOut(hdc, 460, 210, lptStr4, lstrlen(lptStr4)); }
		if (GetWinner() == DRAW) { TextOut(hdc, 460, 210, lptStr5, lstrlen(lptStr5)); }

		TextOut(hdc, 460, 310, lptStr7, lstrlen(lptStr7));

	}
	else {
		//テキストを消去
		SelectObject(hdc, hFont);
		TextOut(hdc, 460, 310, lptStr6, lstrlen(lptStr6));
		TextOut(hdc, 460, 210, lptStr6, lstrlen(lptStr6));
		
	}

	//くそでかフォントを削除
	DeleteObject(hFont);

	SelectObject(hdc, GetStockObject(SYSTEM_FONT));

	//駒数表示
	TCHAR buf[40];
	int length = wsprintf(buf, TEXT("黒の総数: %2d "), blackframe);
	TextOut(hdc, 480, 80, buf, length);

	length = wsprintf(buf, TEXT("白の総数: %2d "), whiteframe);
	TextOut(hdc, 480, 105, buf, length);

	length = wsprintf(buf, TEXT("駒の総数: %2d "), blackframe + whiteframe);
	TextOut(hdc, 480, 150, buf, length);

	//ハンドルの解放
	ReleaseDC(hWnd,hdc);

}