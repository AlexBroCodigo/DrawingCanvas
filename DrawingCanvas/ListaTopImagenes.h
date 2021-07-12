/* 
 * File:   ListaTopImagenes.h
 * Author: AlexelBro
 *
 * Created on 25 de junio de 2019, 14:22
 */

#ifndef LISTATOPIMAGENES_H
#define LISTATOPIMAGENES_H
#include <iostream>
#include <sstream>

using namespace std;

class NodoTopImagen{
public:
    string imagen;
    int numerocapas;
    NodoTopImagen* siguiente;
    
    NodoTopImagen(string imagen,int numcapas){
        this->imagen = imagen;
        this->numerocapas = numcapas;
        siguiente = NULL;
    }
};


class ListaTopImagenes {
public:
    NodoTopImagen* primero;
    NodoTopImagen* ultimo;
    
    ListaTopImagenes(){
        primero=NULL;
        ultimo=NULL;
    }
    
    void ingresarImagenTop(string imagen,int numcapas);
    void imprimirTopCinco();
private:
    void ordenarLista(NodoTopImagen* nuevo);
    string castear(int i);
};

#endif /* LISTATOPIMAGENES_H */

