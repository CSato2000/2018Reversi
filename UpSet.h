#ifndef _UP_SET_INCLUDE_
#define _UP_SET_INCLUDE_
#include "GlobalNum.h"

void UpSet(int, int);            //UpSet�֐�
static int checkRotation[8][2];  //�}�X�̎���
   
int cx,cy;                    //���ׂ�}�X�̍��W
int typeRev;                  //����̃^�[���̐F
int revCount,backCount;        //�Ђ�����Ԃ��}�X�̐�,�߂�}�X�̐�
int revPosX[40],revPosY[40];  //�Ђ�����Ԃ��}�X�̍��W������z��

#endif