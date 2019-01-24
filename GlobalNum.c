#include "GlobalNum.h"

turn;        //どちらのターンか BLACK:1 WHITE:2
blackframe;  //黒のコマの数
whiteframe;  //白のコマの数

sMASS MassData[10][10]; //各マスのデータ配列

POINT keyPos = { 0 };

putJudgeCnt = 0;	//置けなかった判定

