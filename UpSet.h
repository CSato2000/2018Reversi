#ifndef _UP_SET_INCLUDE_
#define _UP_SET_INCLUDE_
#include "GlobalNum.h"

void UpSet(int, int);  //UpSet�֐�
static int checkRotation[8][2];  //�}�X�̎���

int cx,cy;            //���ׂ�}�X�̍��W
int typeRev;          //����̃^�[���̐F
int revCount;         //�Ђ�����Ԃ��}�X�̐�
int revPosX[10],revPosY[10];     //�Ђ�����Ԃ��}�X�̍��W

#endif