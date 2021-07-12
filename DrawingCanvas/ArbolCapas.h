/* 
 * File:   ArbolCapas.h
 * Author: AlexelBro
 *
 * Created on 16 de junio de 2019, 13:50
 */

#ifndef ARBOLCAPAS_H
#define ARBOLCAPAS_H
#include <iostream>
#include "MatrizCapa.h"

class NodoCapa{
public: 
    
    int capa;
    MatrizCapa* matrizcapa;
    NodoCapa* izq;
    NodoCapa* der;
    
    NodoCapa(int capa){
        this->capa = capa;
        izq = der = NULL;
        matrizcapa = new MatrizCapa();
    }
    
    NodoCapa(NodoCapa* ramaIzdo, int capa, NodoCapa* ramaDcho){
        this->capa = capa;
        izq = ramaIzdo;
        der = ramaDcho;
        matrizcapa = new MatrizCapa();
    }
    
    //Operaciones de acceso
    int getCapa(){ return capa; }
    NodoCapa* subarbolIzdo(){ return izq; }
    NodoCapa* subarbolDcho(){ return der; }

    // operaciones de modificación
    void ramaIzdo(NodoCapa* n){ izq = n; }
    void ramaDcho(NodoCapa* n){ der = n; }
    
    void visitar(){
        cout << "Capa: " << castear(capa) << endl;
    }
    
private:
    string castear(int i){
        std::string cadenai = static_cast<std::ostringstream*>(&(std::ostringstream() << i))->str();
    return cadenai;
    }
    
};


class ArbolCapas {
public:
    ArbolCapas(NodoCapa* r){
        raiz=r;
    }
    ArbolCapas(){
        raiz = NULL;
    }
    
    NodoCapa* buscarCapa(NodoCapa* r,NodoCapa* capanula,int capa);
    void Preorden();
    void inorden();
    void Postorden();
    void Praiz(NodoCapa* r);
    NodoCapa* Oraiz();
    bool esVacio();
    NodoCapa* hijoIzdo();
    NodoCapa* hijoDcho();
    void insertar(NodoCapa* nuevo);
    void generarGrafica();
    void generarGraficaEspejo();
    void CapasHojas(NodoCapa* r);
    int profundidad(NodoCapa* r);
private:
   NodoCapa* insertar(NodoCapa* raizSub,NodoCapa* nuevo);
   void escribirdot(NodoCapa *r);
   void escribirdotEspejo(NodoCapa *r);
   void Preorden(NodoCapa* r);
   void inorden(NodoCapa* r);
   void Postorden(NodoCapa* r);
   string castear(int i);
   string dotarbol = "";
   string dotarbolespejo = "";
protected:
    NodoCapa* raiz;

};

#endif /* ARBOLCAPAS_H */

