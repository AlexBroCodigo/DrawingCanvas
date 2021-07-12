/* 
 * File:   ListaTopImagenes.cpp
 * Author: AlexelBro
 * 
 * Created on 25 de junio de 2019, 14:22
 */

#include "ListaTopImagenes.h"

void ListaTopImagenes :: ingresarImagenTop(string imagen,int numcapas){
    NodoTopImagen* nuevo = new NodoTopImagen(imagen,numcapas);
    
    if(primero==NULL){
        primero = nuevo;
        ultimo = nuevo;
        primero->siguiente = ultimo;
    } else{
        ordenarLista(nuevo);
    }
}


void ListaTopImagenes :: imprimirTopCinco(){
    NodoTopImagen* actual = primero;
    for(int i = 1;i<=5 && actual != NULL ;i++){
        cout << castear(i) << ". Imagen: "<< actual->imagen << " con numero de capas: " << castear(actual->numerocapas) << endl;
        actual = actual->siguiente;
    }
}

string ListaTopImagenes :: castear(int i){
    std::string cadenai = static_cast<std::ostringstream*>(&(std::ostringstream() << i))->str();
    return cadenai;
}

void ListaTopImagenes :: ordenarLista(NodoTopImagen* nuevo){
    
    if(primero->numerocapas < nuevo->numerocapas){
        nuevo->siguiente = primero;
        primero = nuevo;
    }
    else if(ultimo->numerocapas >= nuevo->numerocapas){
        ultimo->siguiente = nuevo;
        ultimo=nuevo;
    }
    else
    {
        NodoTopImagen* auxiliar = primero;
        NodoTopImagen* otroauxiliar = auxiliar;
        while(auxiliar!=NULL){
            if(auxiliar->numerocapas < nuevo->numerocapas){
                otroauxiliar->siguiente = nuevo;
                nuevo->siguiente = auxiliar;
                break;
            } else if(auxiliar->siguiente==NULL){
                auxiliar->siguiente=nuevo;
                ultimo = nuevo;
                break;
            } else {
                otroauxiliar = auxiliar;
                auxiliar = auxiliar->siguiente;
            }
        }
    }
}
