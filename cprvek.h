#ifndef CPRVEK_H
#define CPRVEK_H

class CPrvek
{
public:
    CPrvek();
    void init(int pocet);
    ~CPrvek() {delete[] poleVstupu;}
    float *poleVstupu;
    int vystup;
};

#endif // CPRVEK_H
