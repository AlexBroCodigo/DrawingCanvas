/* 
 * File:   ListaCircularImagenes.h
 * Author: AlexelBro
 *
 * Created on 16 de junio de 2019, 18:51
 */

#ifndef LISTACIRCULARIMAGENES_H
#define LISTACIRCULARIMAGENES_H
#include <iostream>
#include "ListaSimpleCapas.h"
#include <fstream>
#include <windows.h>
#include <sstream>
using namespace std;

class NodoImagen{
public:
    
    int imagen;
    NodoImagen* siguiente;
    NodoImagen* anterior;
    ListaSimpleCapas* listacapas;
    
    NodoImagen(int imagen){
        siguiente = NULL;
        anterior = NULL;
        this->imagen = imagen;
        listacapas = new ListaSimpleCapas();
        
    }
};


class ListaCircularImagenes {
public:
    NodoImagen* primero;
    NodoImagen* ultimo;
    
    ListaCircularImagenes(){
        primero = NULL;
        ultimo = NULL;
    }
    
    void ingresarImagen(int img);
    NodoImagen* buscarImagen(int img);
    void eliminarImagen(int img);
    void generarGrafica();
private:
    void escribirDot();
    string castear(int i);
    string dotimagenes = "";
};

#endif /* LISTACIRCULARIMAGENES_H */

