/* 
 * File:   ListaHorizontal.cpp
 * Author: AlexelBro
 * 
 * Created on 15 de junio de 2019, 23:10
 */

#include "ListaHorizontal.h"

void ListaHorizontal :: insertarDispersa(NodoDispersa* nuevo){
     if(esVacio()){
        primero = nuevo;
        ultimo = nuevo;
    } else{
        if(nuevo->posx < primero->posx){
            insertarFrente(nuevo);
        }
        else if(nuevo->posx > ultimo->posx){
            insertarFinal(nuevo);

        }
        else{
            insertarMedio(nuevo);
        }
    }
}

bool ListaHorizontal::esVacio(){
    return (primero==NULL) ? true : false;
    
}


void ListaHorizontal :: insertarFrente(NodoDispersa* nuevo){
    primero->izquierda = nuevo;
    nuevo->derecha = primero;
    primero = nuevo;
}


void ListaHorizontal::insertarFinal(NodoDispersa* nuevo){
    ultimo->derecha = nuevo;
    nuevo->izquierda = ultimo;
    ultimo = nuevo;
}

void ListaHorizontal::insertarMedio(NodoDispersa* nuevo){
    NodoDispersa* temp1;
    NodoDispersa* temp2;
    temp1 = primero;

    while(temp1->posx<nuevo->posx){
        temp1 = temp1->derecha;
    }

    temp2 = temp1->izquierda;

    temp2->derecha = nuevo;
    temp1->izquierda = nuevo;
    nuevo->derecha = temp1;
    nuevo->izquierda = temp2;
}