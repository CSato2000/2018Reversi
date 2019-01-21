#include<Windows.h>
#include "KeyController.h"

int KeyController(WPARAM code) {

	if (code == VK_LEFT)keyPos.x--;
	if (code == VK_RIGHT)keyPos.x++;
	if (code == VK_UP)keyPos.y--;
	if (code == VK_DOWN)keyPos.y++;

	if (keyPos.x < 0)keyPos.x = 0;
	if (keyPos.x > 7)keyPos.x = 7;
	if (keyPos.y < 0)keyPos.y = 0;
	if (keyPos.y > 7)keyPos.y = 7;

	if (code == VK_SPACE && MassData[keyPos.x][keyPos.y].putflag == 1) {
		MassData[keyPos.x][keyPos.y].type = turn;
		//‚±‚±‚ÉƒRƒ}‚ğ’u‚­ŠÖ”‚ğŒÄ‚Ô
		
	}

	return 0;
}