/* 
 * File:   ListaHorizontal.h
 * Author: AlexelBro
 *
 * Created on 15 de junio de 2019, 23:10
 */

#ifndef LISTAHORIZONTAL_H
#define LISTAHORIZONTAL_H
#include <iostream>
#include "NodoDispersa.h"

class ListaHorizontal{
    
public:
    NodoDispersa* primero;
    NodoDispersa* ultimo;
    
    ListaHorizontal(){
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

#endif /* LISTAHORIZONTAL_H */

