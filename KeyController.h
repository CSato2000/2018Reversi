#ifndef _KEY_CONTROLLER_INCLUDE_
#define _KEY_CONTROLLER_INCLUDE_

#include "GlobalNum.h"
#include "UpSet.h"
#include "Init.h"
#include<windows.h>
/*******************************************************
関数名：KeyController
機能：キーボード操作の制御 どのキーが押されたかの情報をWM_KEYDOWNからもらう
引数：WPARAM型 keyコード
戻り値：なし
*******************************************************/
void KeyController(WPARAM);

#endif