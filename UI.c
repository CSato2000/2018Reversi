#include "UI.h"

void UI(hWnd) {

	//�n���h���̎擾
	HDC hdc;
	HFONT hFont;
	hdc = GetDC(hWnd);

	//������
	LPTSTR lptStr1 = TEXT("���̃^�[���ł�");
	LPTSTR lptStr2 = TEXT("���̃^�[���ł�");
	LPTSTR lptStr3 = TEXT("���̏����ł�");
	LPTSTR lptStr4 = TEXT("���̏����ł�");
	LPTSTR lptStr5 = TEXT("���������ł�");
	LPTSTR lptStr6 = TEXT("�@�@�@�@�@�@�@�@�@�@");
	LPTSTR lptStr7 = TEXT("�Đ� �F ENTER");

	//�t�H���g�𐶐�
	hFont = CreateFont(
		40, 0, 0, 0, FW_BOLD, TRUE, FALSE, FALSE,
		SHIFTJIS_CHARSET, OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		VARIABLE_PITCH | FF_ROMAN, NULL
	);

	//�����ł��t�H���g
	SelectObject(hdc, hFont);

	//�^�[���\��
	if (turn == BLACK)TextOut(hdc, 460, 10, lptStr1, lstrlen(lptStr1));
	if (turn == WHITE)TextOut(hdc, 460, 10, lptStr2, lstrlen(lptStr2));

	//���ʂ̃t�H���g
	SelectObject(hdc, GetStockObject(SYSTEM_FONT));

	if (sceneFlag == RESULT) {


		//�����ҕ\��
		//�����ł��t�H���g
		SelectObject(hdc, hFont);

		if (GetWinner() == BLACK) { TextOut(hdc, 460, 210, lptStr3, lstrlen(lptStr3)); }
		if (GetWinner() == WHITE) { TextOut(hdc, 460, 210, lptStr4, lstrlen(lptStr4)); }
		if (GetWinner() == DRAW) { TextOut(hdc, 460, 210, lptStr5, lstrlen(lptStr5)); }

		TextOut(hdc, 460, 310, lptStr7, lstrlen(lptStr7));

	}
	else {
		//�e�L�X�g������
		SelectObject(hdc, hFont);
		TextOut(hdc, 460, 310, lptStr6, lstrlen(lptStr6));
		TextOut(hdc, 460, 210, lptStr6, lstrlen(lptStr6));
		
	}

	//�����ł��t�H���g���폜
	DeleteObject(hFont);

	SelectObject(hdc, GetStockObject(SYSTEM_FONT));

	//��\��
	TCHAR buf[40];
	int length = wsprintf(buf, TEXT("���̑���: %2d "), blackframe);
	TextOut(hdc, 480, 80, buf, length);

	length = wsprintf(buf, TEXT("���̑���: %2d "), whiteframe);
	TextOut(hdc, 480, 105, buf, length);

	length = wsprintf(buf, TEXT("��̑���: %2d "), blackframe + whiteframe);
	TextOut(hdc, 480, 150, buf, length);

	//�n���h���̉��
	ReleaseDC(hWnd,hdc);

}