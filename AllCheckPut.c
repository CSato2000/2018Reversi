#include "AllCheckPut.h"
#include "SearchPut.h"
#include "GameEnd.h"

#define FALSE 0
#define TRUE 1

int AllCheckPut(gameEndJudge) {

	int x, y;	//�}�X�̍��W
	int putJudge; //�u����FTRUE / �u���Ȃ��FFALSE

				/* ���ׂẴ}�X�𒲂ׂ� */
	for (y = 1; y <= 8; y++) {
		for (x = 1; x <= 8; x++) {

			if (MassData[y][x].putflag == TRUE) {
				MassData[y][x].putflag = FALSE;		//�O��̒u����}�X�̃��Z�b�g
			}

			if (MassData[y][x].type == EMPTY) {
				putJudge = SearchPut(x, y);	//SearchPut�Ăяo��
			}
		}
	}

	//�u����ꏊ���Ȃ�������^�[�����
	if (putJudge != TRUE) {
		if (gameEndJudge == TRUE) {
			GameEnd();
			return 0;
		}

		gameEndJudge = FALSE;
		turn = (turn == WHITE ? BLACK : WHITE);
		AllCheckPut(TRUE);

	}

	return 0;
}