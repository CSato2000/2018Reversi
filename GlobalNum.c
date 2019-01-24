#include "GlobalNum.h"

int turn;        //どちらのターンか BLACK:1 WHITE:2
int blackframe;  //黒のコマの数
int whiteframe;  //白のコマの数

sMASS MassData[10][10]; //各マスのデータ配列

POINT keyPos = { 0 };

int putJudgeCnt = 0;	//置けなかった判定

