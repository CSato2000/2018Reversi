#include<Windows.h>
#include "KeyController.h"


void KeyController(WPARAM code) {
	//�L�[�̔���i���E�㉺�j
	if (code == VK_LEFT)keyPos.x--;
	if (code == VK_RIGHT)keyPos.x++;
	if (code == VK_UP)keyPos.y--;
	if (code == VK_DOWN)keyPos.y++;

	//keyPos�̏���Ɖ����̐���
	if (keyPos.x < 0)keyPos.x = 0;
	if (keyPos.x > 7)keyPos.x = 7;
	if (keyPos.y < 0)keyPos.y = 0;
	if (keyPos.y > 7)keyPos.y = 7;
	
	//�X�y�[�X�������ꂽ���A�����A���̃}�X�ɃR�}���u����ꍇ
	if (code == VK_SPACE && MassData[keyPos.x+1][keyPos.y+1].putflag == 1) {
		MassData[keyPos.x+1][keyPos.y+1].type = turn;
		//�����ɃR�}��u���֐����Ă�
		UpSet(keyPos.x + 1, keyPos.y + 1);
	}
	if (code == VK_SPACE && sceneFlag == RESULT) {
		sceneFlag = INGAME;
		Init();
	}
}