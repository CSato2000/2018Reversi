#ifndef _BOARD_DRAW_INCLUDE_
#define _BOARD_DRAW_INCLUDE_

#include "GlobalNum.h"
#include <Windows.h>

/*******************************************************
�֐����FBoardDraw
�@�\�F�Ֆʂ�`�悷��
�����FHWND�^ �E�B���h�E�n���h��
�߂�l�F�Ȃ�
*******************************************************/
#define BRUSH_MAX 5

void BoardDraw(HWND);
void BoardDraw_Finalize();
#endif