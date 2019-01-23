#ifndef _UP_SET_INCLUDE_
#define _UP_SET_INCLUDE_
#include "GlobalNum.h"

void UpSet(int, int);            //UpSet関数
static int checkRotation[8][2];  //マスの周囲
   
int cx,cy;                    //調べるマスの座標
int typeRev;                  //相手のターンの色
int revCount,backCount;        //ひっくり返すマスの数,戻るマスの数
int revPosX[40],revPosY[40];  //ひっくり返すマスの座標を入れる配列

#endif