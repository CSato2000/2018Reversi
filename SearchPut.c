#include "SearchPut.h"

#define FALSE 0
#define TRUE 0

int SearchPut(x, y) {

	//�}�X�̎���𒲂ׂ�z��
	static int checkOrder[8][2] = { { -1,0 },{ -1,1 },{ 0,1 },{ 1,1 },{ 1,0 },{ 1,-1 },{ 0,-1 },{ -1,-1 } };
	int i;			//�J�E���g�p
	int cx, cy;		//���ׂ�p
	int turnRev;	//���݃^�[���̋t

	/* �}�X�̎���𒲂ׂ� */
	for (i = 0; i < 8; i++) {

		cx = checkOrder[i][1];
		cy = checkOrder[i][0];

		turnRev = (turn == WHITE ? BLACK : WHITE);		//���݂̃^�[���̋t�̐F

														/* ���ׂ��悪����̃}�X�Ȃ炻�̐�𒲂ׂ� */
		while (MassData[y + cy][x + cx].type == turnRev) {

			//���ׂ��悪����̐F�ł��̐悪�����̐F�Ȃ�u����
			if (MassData[y + cy + cy][x + cx + cx].type == turn) {

				MassData[y][x].putflag = TRUE;

			}

			//���̏���
			cx += checkOrder[i][1];
			cy += checkOrder[i][0];

		}
	}

	return 0;
}