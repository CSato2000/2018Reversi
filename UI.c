#include "UI.h"

void UI(hWnd) {

	//ハンドルの取得
	HDC hdc;
	hdc = GetDC(hWnd);

	//文字列
	LPTSTR lptStr1 = TEXT("黒のターンです");
	LPTSTR lptStr2 = TEXT("白のターンです");
	LPTSTR lptStr3 = TEXT("黒の勝ちです");
	LPTSTR lptStr4 = TEXT("白の勝ちです");
	LPTSTR lptStr5 = TEXT("引き分けです");

	//ターン表示
	if (turn == BLACK)TextOut(hdc, 460, 10, lptStr1, lstrlen(lptStr1));
	if (turn == WHITE)TextOut(hdc, 460, 10, lptStr2, lstrlen(lptStr2));

	//勝利者表示
	if (GetWinner() == BLACK) {TextOut(hdc, 460, 110, lptStr3, lstrlen(lptStr3));}
	if (GetWinner() == WHITE) { TextOut(hdc, 460, 110, lptStr4, lstrlen(lptStr4)); }
	if (GetWinner() == DRAW) { TextOut(hdc, 460, 110, lptStr5, lstrlen(lptStr5)); }

	//駒数表示
	TCHAR buf[40];
	int length = wsprintf(buf, TEXT("黒の総数:%2d "), blackframe);
	TextOut(hdc, 480, 30, buf, length);

	length = wsprintf(buf, TEXT("白の総数:%2d "), whiteframe);
	TextOut(hdc, 480, 50, buf, length);

	length = wsprintf(buf, TEXT("駒の総数:%2d "), blackframe + whiteframe);
	TextOut(hdc, 480, 70, buf, length);

	//ハンドルの解放
	ReleaseDC(hWnd,hdc);

}