#include "UpSet.h"
#include "AllCheckPut.h"


/********************************************************************************
�֐���:void UpSet(int int)
���e�F���̊֐����Ăяo���ꂽ��A�w�肳�ꂽ�ꏊ���狲�߂�͈͂̃R�}���Ђ�����Ԃ�
����:int x,int y
�߂�l�F�Ȃ�
*********************************************************************************/
void UpSet(int x, int y) {
	if (MassData[x][y].putflag == 1) {
		if (MassData[x][y].type == BLACK) {
			//�u���V�̐F�𔒂ɂ���
			;
		}
		else if (MassData[x][y].type == WHITE) {
			//�u���V�̐F�����ɂ���
			;
		}
	}

	/*
	�E�\���̂̑S�̂�����putflag��on�̂Ƃ�����݂�
	�Eputflag��on��turn�Ǝ��͂̃R�}��type���������A���̃R�}�̐F��ς���
	�˔��Ȃ獕�A���Ȃ甒�ɕ`�悳����
	�E
	*/
}