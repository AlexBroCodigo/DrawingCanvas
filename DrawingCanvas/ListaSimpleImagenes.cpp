/* 
 * File:   ListaSimpleImagenes.cpp
 * Author: AlexelBro
 * 
 * Created on 20 de junio de 2019, 12:13
 */

#include "ListaSimpleImagenes.h"

void ListaSimpleImagenes :: ingresarImagen(std::string idimagen){
    Img* nuevo = new Img(idimagen);
    if(primero==NULL){
        primero = nuevo;
        ultimo = nuevo;
    } else{
        ultimo->siguiente = nuevo;
        ultimo = nuevo;
    }
}

Img* ListaSimpleImagenes :: buscarImagen(std::string idimagen){
    Img* actual = primero;
    while(actual!=NULL){
        if(actual->idimagen==idimagen){
            return actual;
            break;
        }
        actual = actual->siguiente;
    }
    return NULL;
}

void ListaSimpleImagenes :: eliminarImagen(std::string idimagen){
    Img* actual = primero;
    Img* anterior = NULL;
    
    while(actual!=NULL){
        if(actual == primero){
            if(actual->idimagen == idimagen){
                primero = primero->siguiente;
                return;
            }
        } else{
            if(actual->idimagen == idimagen){
                anterior->siguiente = actual->siguiente;
                delete(actual);
                return;
            }
        }
        anterior = actual;
        actual = actual->siguiente;
    }
}


