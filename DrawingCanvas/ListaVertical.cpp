/* 
 * File:   Listavertical.cpp
 * Author: AlexelBro
 * 
 * Created on 16 de junio de 2019, 0:28
 */

#include "ListaVertical.h"

void ListaVertical :: insertarDispersa(NodoDispersa* nuevo){
    if(esVacio()){
        primero = nuevo;
        ultimo = nuevo;
    } else{
        if(nuevo->posy < primero->posy){
            insertarFrente(nuevo);
        }
        else if(nuevo->posy > ultimo->posy){
            insertarFinal(nuevo);

        }
        else{
            insertarMedio(nuevo);
        }
    }
}


void ListaVertical::insertarFrente(NodoDispersa* nuevo){
    primero->arriba = nuevo;
    nuevo->abajo = primero;
    primero = nuevo;
}


void ListaVertical::insertarFinal(NodoDispersa* nuevo){
    ultimo->abajo = nuevo;
    nuevo->arriba = ultimo;
    ultimo = nuevo;
}

void ListaVertical::insertarMedio(NodoDispersa* nuevo){
    NodoDispersa* temp1;
    NodoDispersa* temp2;
    temp1 = primero;

    while(temp1->posy<nuevo->posy){
        temp1 = temp1->abajo;
    }

    temp2 = temp1->arriba;

    temp2->abajo = nuevo;
    temp1->arriba = nuevo;
    nuevo->abajo = temp1;
    nuevo->arriba = temp2;

}

bool ListaVertical::esVacio(){
    return (primero==NULL) ? true : false;
}
