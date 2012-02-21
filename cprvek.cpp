#include "cprvek.h"

CPrvek::CPrvek()
{
}
void CPrvek::init(int pocet){
    poleVstupu = new float[pocet + 1];
    poleVstupu[0] = 1;
}
