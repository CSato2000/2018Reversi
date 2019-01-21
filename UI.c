#include <windows.h>
#include "UI.h"

void UI(hWnd) {

	HDC hdc;
	hdc = GetDC(hWnd);

	LPTSTR lptStr1 = TEXT("黒のターンです");
	LPTSTR lptStr2 = TEXT("白のターンです");

	if (turn == BLACK)TextOut(hdc, 460, 10, lptStr1, lstrlen(lptStr1));
	if (turn == WHITE)TextOut(hdc, 460, 10, lptStr2, lstrlen(lptStr2));

	WCHAR buf[20];
	int length = wsprintf(buf, L"%d", blackframe);
	TextOut(hdc, 460, 30, buf, length);

	length = wsprintf(buf, L"%d", whiteframe);
	TextOut(hdc, 460, 50, buf, length);

	length = wsprintf(buf, L"%d", blackframe + whiteframe);
	TextOut(hdc, 460, 70, buf, length);

	ReleaseDC(hWnd,hdc);

}