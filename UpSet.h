#ifndef _UP_SET_INCLUDE_
#define _UP_SET_INCLUDE_
#include "GlobalNum.h"

/********************************************************************************
関数名：void UpSet(int x,int y)
機能；指定されたマスからどこまでひっくり返せるコマがあるかを探してひっくり返す
引数：int x,y
戻り値：なし
*********************************************************************************/
void UpSet(int, int);            //UpSet関数

static int checkRotation[8][2];  //マスの周囲


#endif