/* 
 * File:   ListaTopUsuarios.h
 * Author: AlexelBro
 *
 * Created on 25 de junio de 2019, 17:29
 */

#ifndef LISTATOPUSUARIOS_H
#define LISTATOPUSUARIOS_H
#include <iostream>
#include <sstream>

using namespace std;

class NodoTopUsuario{
public:
    string usuario;
    int numeroimagenes;
    NodoTopUsuario* siguiente;
    
    NodoTopUsuario(string usuario,int numimagenes){
       this->usuario = usuario;
       this->numeroimagenes = numimagenes;
       siguiente = NULL;
    }
};

class ListaTopUsuarios {
public:
    NodoTopUsuario* primero;
    NodoTopUsuario* ultimo;
    
    ListaTopUsuarios(){
        primero=NULL;
        ultimo=NULL;
    }
    
    void ingresarUsuarioTop(string usuario,int numimagenes);
    void imprimirTopCinco();
    
private:
    void ordenarLista(NodoTopUsuario* nuevo);
    string castear(int i);
};

#endif /* LISTATOPUSUARIOS_H */

