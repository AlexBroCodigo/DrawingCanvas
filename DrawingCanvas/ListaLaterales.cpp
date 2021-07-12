/* 
 * File:   ListaLaterales.cpp
 * Author: AlexelBro
 * 
 * Created on 15 de junio de 2019, 22:19
 */

#include "ListaLaterales.h"

void ListaLaterales :: ingresarLateral(NodoLateral* nuevo){
    if(primero == NULL){
        primero = nuevo;
        primero->siguiente = NULL;
        primero->anterior = NULL;
        ultimo = primero;
    } else{
        ordenarLateral(nuevo);
    }
    
}

void ListaLaterales :: ordenarLateral(NodoLateral* nuevo){
    if(nuevo->y <= primero->y)
    {
        primero->anterior = nuevo;
        nuevo->siguiente = primero;
        nuevo->anterior = NULL;
        primero = nuevo;

    }
    else if(nuevo->y >= ultimo->y)  
    {
        ultimo->siguiente = nuevo;
        nuevo->anterior = ultimo;
        nuevo->siguiente = NULL;
        ultimo=nuevo;
    }
    else
    {
        NodoLateral* actual = primero;
        while(actual!=ultimo)
        {
            if((nuevo->y >= actual->y) && (nuevo->y <= actual->siguiente->y)){
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

bool ListaLaterales :: esVacio(){
    if(primero==NULL){
        return true;
    } else{
        return false;
    }
}

NodoLateral* ListaLaterales :: buscarLateral(int y){
    
    if(!esVacio()){
        NodoLateral* actual = primero;
        while(actual!=NULL){
            if(actual->y == y){
                return actual;
            }
            actual = actual->siguiente;
        }
        return NULL;
    } else{
        return NULL;
    }
}