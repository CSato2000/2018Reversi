#include <windows.h>
#include "UI.h"

void UI(hWnd) {

	HDC hdc;
	hdc = GetDC(hWnd);

	LPTSTR lptStr1 = TEXT("黒のターンです");
	LPTSTR lptStr2 = TEXT("白のターンです");
	LPTSTR lptStr3 = TEXT("黒の勝ちです");
	LPTSTR lptStr4 = TEXT("白の勝ちです");
	LPTSTR lptStr5 = TEXT("引き分けです");

	//ターン表示
	if (turn == BLACK)TextOut(hdc, 460, 10, lptStr1, lstrlen(lptStr1));
	if (turn == WHITE)TextOut(hdc, 460, 10, lptStr2, lstrlen(lptStr2));

	//勝利者表示
	TextOut(hdc, 460, 110, lptStr3, lstrlen(lptStr3));
	//TextOut(hdc, 460, 110, lptStr4, lstrlen(lptStr4));
	//TextOut(hdc, 460, 110, lptStr5, lstrlen(lptStr5));

	//駒数表示
	WCHAR buf[20];
	int length = wsprintf(buf, "黒の総数:%d", blackframe);
	TextOut(hdc, 560, 30, buf, length);

	length = wsprintf(buf, "白の総数:%d", whiteframe);
	TextOut(hdc, 560, 50, buf, length);

	length = wsprintf(buf, "駒の総数:%d", blackframe + whiteframe);
	TextOut(hdc, 560, 70, buf, length);

	ReleaseDC(hWnd,hdc);

}