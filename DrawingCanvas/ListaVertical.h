/* 
 * File:   Listavertical.h
 * Author: AlexelBro
 *
 * Created on 16 de junio de 2019, 0:28
 */

#ifndef LISTAVERTICAL_H
#define LISTAVERTICAL_H
#include <iostream>
#include "NodoDispersa.h"

class ListaVertical {
public:
    NodoDispersa* primero;
    NodoDispersa* ultimo;
    
    ListaVertical(){
        primero=NULL;
        ultimo=NULL;
    }
    
    void insertarDispersa(NodoDispersa* nuevo);
    
    
private:
    bool esVacio();
    void insertarFrente(NodoDispersa* nuevo);
    void insertarFinal(NodoDispersa* nuevo);
    void insertarMedio(NodoDispersa* nuevo);
    
};

#endif /* LISTAVERTICAL_H */

