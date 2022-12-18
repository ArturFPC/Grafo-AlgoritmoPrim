#ifndef GRAFO_H
#define GRAFO_H
#include "vertice.h"
#include <queue>
#include <vector>
using namespace std;
class grafo
{
    public:
        grafo();
        virtual ~grafo();
        void enqueue(vertice v);
        vertice dequeue();
        vector<vector<int>> getMA(){return this->mAdjacencia;}
        void setMA(vector<vector<int>> nMA);
        void montarGrafo(int nVerticeRaiz);
        void mostrarGrafo();
        vertice extractMin();
        bool pertenceFila(vertice x);
        void prim(int nVerticeRaiz);
        void mostrarPrim();
    protected:
        queue<vertice> Q;
        vector<vector<int>> mAdjacencia;
        vector<vertice> v;//vetor para armazenar os vertices pertencentes ao grafo
    private:
};
grafo::grafo()
{
    //ctor
}

grafo::~grafo()
{
    //dtor
}
void grafo::enqueue(vertice v){
    Q.push(v);
}
vertice grafo::dequeue(){
    vertice pF;//primeiro vertice da fila
    pF = Q.front();
    Q.pop();
    return pF;
}
void grafo::setMA(vector<vector<int>> nMA){
    this->mAdjacencia=nMA;
}
void grafo::montarGrafo(int nVerticeRaiz){
    for (int i = 0; i<mAdjacencia.size();i++){
        vertice aux;
        aux.setChave(999);
        if (nVerticeRaiz ==i){
            aux.setChave(0);
        }
        aux.setP(NULL);
        aux.setNum(i);
        this->v.push_back(aux);
        enqueue(v[i]);
    }
}

vertice grafo::extractMin(){
    int menor;
    vertice vMenor;
    menor = v[Q.front().getNum()].getChave();
    vMenor = Q.front();

    queue<vertice> aux;
    int queueSize = Q.size();
    for (int i = 1; i<v.size();i++){
        if ((v[i].getChave()<menor) && (pertenceFila(v[i]))){
            if (pertenceFila(v[i])){
                menor = v[i].getChave();
                vMenor = v[i];
            }

        }
    }
    for (int i = 0; i<queueSize;i++){
        if (Q.front().getNum()!=vMenor.getNum()){
            aux.push(Q.front());
            Q.pop();
        }else{
            Q.pop();
        }
    }
    Q = aux;
    return vMenor;
}
bool grafo::pertenceFila(vertice x){
    bool pertence = false;
    queue<vertice> filaAux;
    filaAux = Q;
    for (int i = 0; i<Q.size();i++){
        if (x.getNum()==filaAux.front().getNum()){
            pertence = true;
        }
        filaAux.pop();
    }
    return pertence;
}
void grafo::prim(int nVerticeRaiz){
    montarGrafo(nVerticeRaiz);
    vertice u;
    int ajuda=0;
    while(!Q.empty()){
        u = extractMin();

        for (int i=0; i<mAdjacencia.size();i++){
            if(mAdjacencia[u.getNum()][i]!=0){
                if ((pertenceFila(v[i]))and (mAdjacencia[u.getNum()][v[i].getNum()]<v[i].getChave())){
                    v[i].setP(u.getNum());
                    v[i].setChave(mAdjacencia[u.getNum()][v[i].getNum()]);
                }
            }
        }
    }
}
void grafo::mostrarPrim(){
    int total = 0;
    for (int i = 0; i<v.size();i++){
        cout<<"////////////////////"<<endl;
        cout<<"Número do vértice: "<<v[i].getNum()<<endl;
        cout<<"Número do predecessor: "<<v[i].getP()<<endl;
        cout<<"Chave: "<<v[i].getChave()<<endl;
        total = total + v[i].getChave();
    }
    cout<<"////////////////////"<<endl;
    cout<<"Peso Total da árvore: "<<total<<endl;

}
#endif // GRAFO_H
