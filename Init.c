#include<string.h>
#include "init.h"

void Init() {
	turn = 0;
    blackframe = 0;
    whiteframe = 0;

	memset(MassData, 0x00, sizeof*(MassData));
	MassData[4][4].type = BLACK;
	MassData[5][5].type = BLACK;
	MassData[4][5].type = WHITE;
	MassData[5][4].type = WHITE;
}