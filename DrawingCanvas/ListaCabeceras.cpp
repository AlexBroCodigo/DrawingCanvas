/* 
 * File:   ListaCabeceras.cpp
 * Author: AlexelBro
 * 
 * Created on 15 de junio de 2019, 19:15
 */

#include "ListaCabeceras.h"

void ListaCabeceras :: ingresarCabecera(NodoCabecera* nuevo){
    if(primero == NULL){
        primero = nuevo;
        primero->siguiente = NULL;
        primero->anterior = NULL;
        ultimo = primero;
    } else{
        ordenarCabecera(nuevo);
    }
}

void ListaCabeceras :: ordenarCabecera(NodoCabecera* nuevo){
    
    if(nuevo->x <= primero->x)
    {
        primero->anterior = nuevo;
        nuevo->siguiente = primero;
        nuevo->anterior = NULL;
        primero = nuevo;

    }
    else if(nuevo->x >= ultimo->x)
    {
        ultimo->siguiente = nuevo;
        nuevo->anterior = ultimo;
        nuevo->siguiente = NULL;
        ultimo=nuevo;
    }
    else
    {
        NodoCabecera* actual = primero;
        while(actual!=ultimo)
        {
            if((nuevo->x >= actual->x) && (nuevo->x <= actual->siguiente->x)){
                nuevo->siguiente = actual->siguiente;
                nuevo->anterior = actual;
                actual->siguiente->anterior = nuevo;
                actual->siguiente = nuevo;
                break;
            }
            actual=actual->siguiente;
        }
    }
}

bool ListaCabeceras :: esVacio(){
    if(primero==NULL){
        return true;
    } else{
        return false;
    }
}

NodoCabecera* ListaCabeceras :: buscarCabecera(int x){
    
    if(!esVacio()){
        NodoCabecera* actual = primero;
        while(actual!=NULL){
            if(actual->x == x){
                return actual;
            }
            actual = actual->siguiente;
        }
        return NULL;
    } else{
        return NULL;
    }
}


