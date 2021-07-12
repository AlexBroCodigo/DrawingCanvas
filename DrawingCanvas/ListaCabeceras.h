/* 
 * File:   ListaCabeceras.h
 * Author: AlexelBro
 *
 * Created on 15 de junio de 2019, 19:15
 */

#ifndef LISTACABECERAS_H
#define LISTACABECERAS_H
#include <iostream>
#include "ListaVertical.h"

class NodoCabecera{
public: 
    int x;
    NodoCabecera* siguiente;
    NodoCabecera* anterior;
    ListaVertical* columna;
    
    NodoCabecera(int x){
        this->x = x;
        columna = new ListaVertical();
        siguiente = NULL;
        anterior = NULL;
    }
};


class ListaCabeceras{
public:
    NodoCabecera* primero;
    NodoCabecera* ultimo;
    
    ListaCabeceras(){
        primero = NULL;
        ultimo = NULL;
    }
    
    void ingresarCabecera(NodoCabecera* nuevo);
    NodoCabecera* buscarCabecera(int x);
private:
    void ordenarCabecera(NodoCabecera* nuevo);
    bool esVacio();

};

#endif /* LISTACABECERAS_H */

