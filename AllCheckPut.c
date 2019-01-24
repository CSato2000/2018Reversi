#include "AllCheckPut.h"
#include "SearchPut.h"
#include "GameEnd.h"

#define FALSE 0
#define TRUE 1

int AllCheckPut() {

	int x, y;	//�}�X�̍��W
	int putJudge = FALSE; //�u����FTRUE / �u���Ȃ��FFALSE
	int putJudgeFlg = FALSE; //��L�Ɠ���

	/* ���ׂẴ}�X�𒲂ׂ� */
	for (y = 1; y <= 8; y++) {
		for (x = 1; x <= 8; x++) {

			if (MassData[y][x].putflag == TRUE) {
				MassData[y][x].putflag = FALSE;		//�O��̒u����}�X�̃��Z�b�g
			}

			if (MassData[y][x].type == EMPTY) {
				putJudge = SearchPut(x, y);		//SearchPut�Ăяo��
				if (putJudgeFlg != TRUE) putJudgeFlg = putJudge;
			}
		}
	}

	//�u����ꏊ���Ȃ�������^�[�����
	if (putJudgeFlg != TRUE) {

		if (putJudgeCnt >= 2) {
			GameEnd();
			return 0;
		}

		putJudgeCnt++;
		turn = (turn == WHITE ? BLACK : WHITE);
		AllCheckPut();

		int onButton;
		onButton = MessageBox(NULL, TEXT("�u���܂���ł���\n�^�[�����p�X���܂�"),
			TEXT("���b�Z�[�W"), MB_OK);

	}

	return 0;
}