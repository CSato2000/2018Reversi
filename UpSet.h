#ifndef _UP_SET_INCLUDE_
#define _UP_SET_INCLUDE_
#include "GlobalNum.h"

void UpSet(int, int);  //UpSet関数
static int checkRotation[8][2];  //マスの周囲

int cx,cy;            //調べるマスの座標
int typeRev;          //相手のターンの色
int revCount;         //ひっくり返すマスの数
int revPosX[10],revPosY[10];     //ひっくり返すマスの座標

#endif