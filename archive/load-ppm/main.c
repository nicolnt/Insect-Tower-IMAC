#include <stdio.h>
#include <stdlib.h>

#include "ppm-loader.h"
#include "../monster/cases.h"
#include "../check-itd-file/itd-file.h"

int main(int argc, char *argv[])
{
    MapData* mapData = itd_initMapData();
    idt_load("level1.itd", mapData);
    Plateau* plateau = malloc(sizeof(plateau));
    case_initPlateau(plateau, mapData);
}
