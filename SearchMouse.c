#include "SearchMouse.h"

#define FALSE 0
#define TRUE 1

int SearchMouse(LPARAM lParam) {

	static POINT pos;

	//�N���b�N���̃}�E�X���W�擾
	pos.x = LOWORD(lParam);
	pos.y = HIWORD(lParam);

	int massX = pos.x / 50 + 1;
	int massY = pos.y / 50 + 1;

	//��ʊO�͖���
	if (pos.x <= 0 || pos.x >= 400 || pos.y <= 0 || pos.y >= 400) return 0;

	//�N���b�N�����}�X�ɔ���z�u
	if (MassData[massX][massY].putflag == TRUE) {
		MassData[massX][massY].type = turn;
		UpSet(massX, massY);
	}

	return 0;
}