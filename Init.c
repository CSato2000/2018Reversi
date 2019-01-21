#include<string.h>
#include "init.h"

void init() {
	turn = 0;
    blackframe = 0;
    whiteframe = 0;

	memset(MassData, 0x00, sizeof*(MassData));
}