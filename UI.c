#include <windows.h>
#include "ConstantNum.h"
#include "GlobalNum.h"
#include "UI.h"

void UI(hdc, nowPlayer, numblack, numwhite) {
	LPTSTR lptStr1 = TEXT("黒のターンです");
	LPTSTR lptStr2 = TEXT("白のターンです");

	if (nowPlayer == 2)TextOut(hdc, 460, 10, lptStr1, lstrlen(lptStr1));
	if (nowPlayer == 1)TextOut(hdc, 460, 10, lptStr2, lstrlen(lptStr2));

	WCHAR buf[20];
	int length = wsprintf(buf, L"%d", numblack);
	TextOut(hdc, 460, 30, buf, length);

	length = wsprintf(buf, L"%d", numwhite);
	TextOut(hdc, 460, 50, buf, length);

	length = wsprintf(buf, L"%d", numblack + numwhite);
	TextOut(hdc, 460, 70, buf, length);

}