#include "SearchMouse.h"

void SearchMouse(POINT pos) {
	
	//�N���b�N���̃}�E�X���W�擾
	pos.x = LOWORD(lParam);
	pos.y = HIWORD(lParam);

	//��ʊO�͖���
	if (pos.x <= 0 || pos.x >= 400 || pos.y <= 0 || pos.y >= 400) return 0;

	//�N���b�N�����}�X�ɔ���z�u
	if (MassData[pos.x / 50 + 1][pos.y / 50 + 1].putflag == TRUE && turn == WHITE) {
		MassData[pos.x / 50 + 1][pos.y / 50 + 1].type = WHITE;

	}

	//�N���b�N�����}�X�ɍ���z�u
	if (MassData[pos.x / 50 + 1][pos.y / 50 + 1].putflag == TRUE && turn == BLACK) {
		MassData[pos.x / 50 + 1][pos.y / 50 + 1].type = BLACK;

	}

	//PAINT�C�x���g�𔭐�������
	InvalidateRect(hWnd, NULL, FALSE);

}