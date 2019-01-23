#include "SearchMouse.h"
#include "GlobalNum.h"
#include "UpSet.h"

#define FALSE 0
#define TRUE 1

void SearchMouse(POINT pos, LPARAM lParam) {

	//�N���b�N���̃}�E�X���W�擾
	pos.x = LOWORD(lParam);
	pos.y = HIWORD(lParam);

	int massX = pos.x / 50 + 1;
	int massY = pos.y / 50 + 1;

	//��ʊO�͖���
	if (pos.x <= 0 || pos.x >= 400 || pos.y <= 0 || pos.y >= 400) return 0;

	//�N���b�N�����}�X�ɔ���z�u
	if (MassData[massX][massY].putflag == TRUE && turn == WHITE) {
		MassData[massX][massY].type = WHITE;
		turn = BLACK;
		whiteframe++;
		UpSet(massX, massY);
	}

	//�N���b�N�����}�X�ɍ���z�u
	if (MassData[massX][massY].putflag == TRUE && turn == BLACK) {
		MassData[massX][massY].type = BLACK;
		turn = WHITE;
		blackframe++;
		UpSet(massX, massY);
	}
}