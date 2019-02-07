#ifndef _BOARD_DRAW_INCLUDE_
#define _BOARD_DRAW_INCLUDE_

#include "GlobalNum.h"
#include <Windows.h>

/*******************************************************
関数名：BoardDraw
機能：盤面を描画する
引数：HWND型 ウィンドウハンドル
戻り値：なし
*******************************************************/
#define BRUSH_MAX 5

void BoardDraw(HWND);
void BoardDraw_Finalize();
#endif