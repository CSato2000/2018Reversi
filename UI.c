#include "UI.h"

void UI(hWnd) {

	//�n���h���̎擾
	HDC hdc;
	hdc = GetDC(hWnd);

	//������
	LPTSTR lptStr1 = TEXT("���̃^�[���ł�");
	LPTSTR lptStr2 = TEXT("���̃^�[���ł�");
	LPTSTR lptStr3 = TEXT("���̏����ł�");
	LPTSTR lptStr4 = TEXT("���̏����ł�");
	LPTSTR lptStr5 = TEXT("���������ł�");

	//�^�[���\��
	if (turn == BLACK)TextOut(hdc, 460, 10, lptStr1, lstrlen(lptStr1));
	if (turn == WHITE)TextOut(hdc, 460, 10, lptStr2, lstrlen(lptStr2));

	//�����ҕ\��
	if (GetWinner() == BLACK) {TextOut(hdc, 460, 110, lptStr3, lstrlen(lptStr3));}
	if (GetWinner() == WHITE) { TextOut(hdc, 460, 110, lptStr4, lstrlen(lptStr4)); }
	if (GetWinner() == DRAW) { TextOut(hdc, 460, 110, lptStr5, lstrlen(lptStr5)); }

	//��\��
	TCHAR buf[40];
	int length = wsprintf(buf, TEXT("���̑���:%2d "), blackframe);
	TextOut(hdc, 480, 30, buf, length);

	length = wsprintf(buf, TEXT("���̑���:%2d "), whiteframe);
	TextOut(hdc, 480, 50, buf, length);

	length = wsprintf(buf, TEXT("��̑���:%2d "), blackframe + whiteframe);
	TextOut(hdc, 480, 70, buf, length);

	//�n���h���̉��
	ReleaseDC(hWnd,hdc);

}