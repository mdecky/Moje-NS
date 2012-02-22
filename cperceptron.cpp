#include "cperceptron.h"
#include <stdio.h>

CPerceptron::CPerceptron()
{

}
CPerceptron::~CPerceptron()
{
    delete [] trenovaciMnozina;
    delete [] testovaciVstupy;
    delete [] vahy;
    delete [] minHod;
    delete [] maxHod;
    delete [] popisVstupu;
}
int CPerceptron::loadFromFile(const char *path)
{
    char str[200];
    this->file.open(path);
    skipLines(str);
    if(EOF == sscanf(str, "%d", &this->pocetVstupu))
    {
      //error
    }
    skipLines(str);
    minHod = new float[this->pocetVstupu + 1];
    maxHod = new float[this->pocetVstupu + 1];
    popisVstupu = new std::string[this->pocetVstupu + 1];
    popisVstupu[0].append("Vstup s vahou theta");
    minHod[0] = 0;
    maxHod[0] = 1;
    tmp = strtok(str, " ");
    popisVstupu[1].append(tmp);
    tmp = strtok(NULL, " ");
    sscanf(tmp, "%f", minHod[1]);
    tmp = strtok(NULL, " ");
    sscanf(tmp, "%f", maxHod[1]);
    for (int i = 2; i < pocetVstupu; ++i) {
        skipLines(str);
        tmp = strtok(str, " ");
        popisVstupu[1].append(tmp);
        tmp = strtok(NULL, " ");
        sscanf(tmp, "%f", minHod[i]);
        tmp = strtok(NULL, " ");
        sscanf(tmp, "%f", maxHod[i]);
    }
    initVahy();
    skipLines(str);
    if(EOF == sscanf(str, "%f", &this->koeficietUceni))
    {
      //error
    }
    skipLines(str);
    if(EOF == sscanf(str, "%d", &this->pocetTrenPrvku))
    {
      //error
    }
    this->trenovaciMnozina = new CPrvek[this->pocetTrenPrvku]();
    for (int i = 0; i < this->pocetTrenPrvku; ++i) {
        this->trenovaciMnozina[i].init(this->pocetVstupu);
    }
    skipLines(str);
    //nacteni testovani mnoziny
    char * tmp;
    tmp = strtok(str, " ");
    for (int i = 0; i < this->pocetTrenPrvku; ++i){
        for (int j = 0; j < this->pocetVstupu; ++j){
            sscanf(tmp, "%f", &trenovaciMnozina[i].poleVstupu[j]);
            tmp = strtok(NULL, " ");
        }
        sscanf(tmp, "%d", &trenovaciMnozina[i].vystup);
        skipLines(str);
        tmp = strtok(str, " ");
    }
    skipLines(str);
    if(EOF == sscanf(str, "%d", &this->pocetTestVstupu))
    {
      //error
    }
    //nacteni testovacich vstupu
    this->testovaciVstupy = new CPrvek[this->pocetTestVstupu]();
    for (int i = 0; i < this->pocetTestVstupu; ++i) {
        this->testovaciVstupy[i].init(this->pocetVstupu);
    }
    tmp = strtok(str, " ");
    for (int i = 0; i < this->pocetTestVstupu; ++i){
        for (int j = 0; j < this->pocetVstupu; ++j){
            sscanf(tmp, "%f", &testovaciVstupy[i].poleVstupu[j]);
            tmp = strtok(NULL, " ");
        }
        sscanf(tmp, "%d", &testovaciVstupy[i].vystup);
        skipLines(str);
        tmp = strtok(str, " ");
    }
    file.close();
}
void CPerceptron::skipLines(char *c)
{
    std::string line;
    getline(file,line);
    while(1){
        if(line.length()!=0 && line.at(0) != '#')
            break;
        getline(file,line);
    }
    strcpy(c, line.c_str());
}
void CPerceptron::initVahy()
{
    srand((unsigned)time(0));
    vahy = new float[pocetVstupu];
    for (int i = 0; i < pocetVstupu; ++i) {
        vahy[i] = (float)rand()/(float)RAND_MAX;

    }
}
void CPerceptron::teach(int pocetCyklu)
{
    int ys;
    float yspom = 0;
    bool teached = true;
    for (int i = 0; i < pocetCyklu; ++i) {
        for (int j = 0; j < pocetTrenPrvku; ++j) {
            for (int k = 0; k < pocetVstupu + 1; ++k) {
                yspom += vahy[k]*trenovaciMnozina[j].poleVstupu[k];
            }
            ys = sgn(yspom);
            if(trenovaciMnozina[j]!=ys){
                teached = false;
                for (int k = 0; k < pocetVstupu + 1; ++k) {
                    vahy[k] += (trenovaciMnozina[j].vystup - ys)*trenovaciMnozina[j].poleVstupu[k]*koeficietUceni;

                }
            }
            teached &= teached;
            ys = 0;
        }
        if(teached)
            return;
        teached = false;
    }
}
template <typename T> int sgn(T val)
{
    return (val > T(0)) - (val < T(0));
}

