#ifndef CPERCEPTRON_H
#define CPERCEPTRON_H
#include "cprvek.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <time.h>

class CPerceptron
{
public:
    std::ifstream file;
    float *vahy;
    CPerceptron(const char *path);
    ~CPerceptron(){ delete [] trenovaciMnozina; delete [] testovaciVstupy; delete [] vahy; }
    int loadFromFile();
    void initVahy();
    void test();
    void teach(int pocetCyklu);
private:
    int pocetVstupu;
    float koeficietUceni;
    int pocetTrenPrvku;
    int pocetTestVstupu;
    CPrvek *trenovaciMnozina;
    CPrvek *testovaciVstupy;
    void skipLines(char*);

};

#endif // CPERCEPTRON_H
