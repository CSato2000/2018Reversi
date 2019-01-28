#include<string.h>
#include "init.h"

void Init() {
	turn = BLACK;
    blackframe = 2;
    whiteframe = 2;
	sceneFlag = INGAME;

	memset(MassData, 0x00, sizeof(MassData));
	MassData[4][4].type = WHITE;
	MassData[5][5].type = WHITE;
	MassData[4][5].type = BLACK;
	MassData[5][4].type = BLACK;

	AllCheckPut();

}