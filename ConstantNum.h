#ifndef _CONSTANT_NUM_INCLUDE_
#define _CONSTANT_NUM_INCLUDE_

/*
�萔���g���Ƃ��͂��̃t�@�C�����C���N���[�h���Ă��������B
*/

//�}�X�̏��
#define EMPTY 0  //��
#define BLACK 1  //��
#define WHITE 2  //��

//�V�[���̏��
//#define TITLE 0   //�^�C�g�����
#define INGAME 0    //�Q�[����
#define RESULT 1  //���ʉ��


//�}�X�̏����������\���́@�񎟌��z��Œ�`����
typedef struct {
	int type;  //�}�X�̏�� 0:�� 1:���̃R�}���u����Ă����� 2:���̃R�}���u����Ă�����
	int putflag;  //���̃}�X�ɃR�}��u���邩�ǂ��� 0:�u���Ȃ���� 1:�u������
}sMASS;

#endif