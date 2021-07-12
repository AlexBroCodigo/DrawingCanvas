/* 
 * File:   ListaLaterales.h
 * Author: AlexelBro
 *
 * Created on 15 de junio de 2019, 22:19
 */

#ifndef LISTALATERALES_H
#define LISTALATERALES_H
#include <iostream>
#include "ListaHorizontal.h"


class NodoLateral{
public:
    int y;
    NodoLateral* siguiente;
    NodoLateral* anterior;
    ListaHorizontal* fila;
    
    NodoLateral(int y){
        this->y = y;
        fila = new ListaHorizontal();
        siguiente = NULL;
        anterior = NULL;
    }
};


class ListaLaterales {
    
public:
    NodoLateral* primero;
    NodoLateral* ultimo;
    
    ListaLaterales(){
        primero = NULL;
        ultimo = NULL;
    }
    
    void ingresarLateral(NodoLateral* nuevo);
    NodoLateral* buscarLateral(int y);
private:
    
    void ordenarLateral(NodoLateral* nuevo);
    bool esVacio();
};

#endif /* LISTALATERALES_H */

