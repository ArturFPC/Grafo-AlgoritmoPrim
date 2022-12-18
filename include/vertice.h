#ifndef VERTICE_H
#define VERTICE_H
#include <string>
#include <iostream>
using namespace std;
class vertice
{
    public:
        vertice();
        virtual ~vertice();
        int getP(){return this->p;}
        void setP(int nP);
        int getNum(){return this->num;}
        void setNum(int nNum);
        int getChave(){return this->chave;}
        void setChave(int nChave);
    protected:
        string cor;
        int d;
        int p = NULL;//numero do predescessor
        int num;//numero para pegar a posição do vertice na matriz de adjacencia
        int chave;
    private:
};
vertice::vertice()
{
    this->p = NULL;
    this->num = 0;
    this->chave = 999;
}

vertice::~vertice()
{
    //dtor
}

void vertice::setP(int nP){
    this->p = nP;
}
void vertice::setNum(int nNum){
    this->num=nNum;
}
void vertice::setChave(int nChave){
    this->chave=nChave;
}
#endif // VERTICE_H
