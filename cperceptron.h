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
    std::string *popisVstupu;
    float *vahy;
    CPerceptron(const char *path);
    ~CPerceptron();
    int loadFromFile();
    void initVahy();
    void test();
    void teach(int pocetCyklu);
private:
    int pocetVstupu;
    float koeficietUceni;
    int pocetTrenPrvku;
    int pocetTestVstupu;
    float *minHod;
    float *maxHod;
    CPrvek *trenovaciMnozina;
    CPrvek *testovaciVstupy;
    void skipLines(char*);
    template <typename T> int sgn(T val);

};

#endif // CPERCEPTRON_H
