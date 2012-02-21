#include "cperceptron.h"
#include <stdio.h>

CPerceptron::CPerceptron(const char *path)
{
    this->file.open(path);

}
void CPerceptron::test(){
    int pocetPrvku = 3;
    std::string line;
    for(int i = 0; i< pocetPrvku; ++i){
        line.append("%f ");
    }
}
int CPerceptron::loadFromFile()
{
    char str[200];
    std::string line;
    skipLines(str);
    if(EOF == sscanf(str, "%d", &this->pocetVstupu))
    {
      //error
    }
    skipLines(str);
    for (int i = 1; i < pocetVstupu; ++i) {
        getline(file,line);
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
    for (int i = 0; i < pocetCyklu; ++i) {
        for (int j = 0; j < pocetTrenPrvku; ++j) {

        }
    }
}
