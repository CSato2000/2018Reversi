#include <windows.h>
#include "UI.h"

void UI(hWnd) {

	HDC hdc;
	hdc = GetDC(hWnd);

	LPTSTR lptStr1 = TEXT("���̃^�[���ł�");
	LPTSTR lptStr2 = TEXT("���̃^�[���ł�");
	LPTSTR lptStr3 = TEXT("���̏����ł�");
	LPTSTR lptStr4 = TEXT("���̏����ł�");
	LPTSTR lptStr5 = TEXT("���������ł�");

	//�^�[���\��
	if (turn == BLACK)TextOut(hdc, 460, 10, lptStr1, lstrlen(lptStr1));
	if (turn == WHITE)TextOut(hdc, 460, 10, lptStr2, lstrlen(lptStr2));

	//�����ҕ\��
	TextOut(hdc, 460, 110, lptStr3, lstrlen(lptStr3));
	//TextOut(hdc, 460, 110, lptStr4, lstrlen(lptStr4));
	//TextOut(hdc, 460, 110, lptStr5, lstrlen(lptStr5));

	//��\��
	WCHAR buf[20];
	int length = wsprintf(buf, "���̑���:%d", blackframe);
	TextOut(hdc, 560, 30, buf, length);

	length = wsprintf(buf, "���̑���:%d", whiteframe);
	TextOut(hdc, 560, 50, buf, length);

	length = wsprintf(buf, "��̑���:%d", blackframe + whiteframe);
	TextOut(hdc, 560, 70, buf, length);

	ReleaseDC(hWnd,hdc);

}