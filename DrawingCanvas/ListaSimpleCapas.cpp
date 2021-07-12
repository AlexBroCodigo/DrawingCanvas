/* 
 * File:   ListaSimpleCapas.cpp
 * Author: AlexelBro
 * 
 * Created on 16 de junio de 2019, 19:53
 */

#include "ListaSimpleCapas.h"

void ListaSimpleCapas :: ingresarCapa(std::string idcapa){
    Capa* nuevo = new Capa(idcapa);
    if(primero==NULL){
        primero = nuevo;
        ultimo = nuevo;
    } else{
        ultimo->siguiente = nuevo;
        ultimo = nuevo;
    }
}

bool ListaSimpleCapas :: existeCapa(std::string idcapa){
    Capa* actual = primero;
    while(actual!=NULL){
        if(actual->idcapa == idcapa){
            return true;
        }
        actual = actual->siguiente;
    }
    return false;
}

int ListaSimpleCapas :: NumerodeCapas(){
    int numcapas = 0;
    Capa* actual = primero;
    while(actual!=NULL){
        numcapas++;
        actual = actual->siguiente;
    }
    return numcapas;
}

