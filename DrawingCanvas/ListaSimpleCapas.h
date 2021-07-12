/* 
 * File:   ListaSimpleCapas.h
 * Author: AlexelBro
 *
 * Created on 16 de junio de 2019, 19:53
 */

#ifndef LISTASIMPLECAPAS_H
#define LISTASIMPLECAPAS_H
#include <iostream>

class Capa{
    
public:
    std::string idcapa;
    Capa* siguiente;
    
    Capa(std::string idcapa){
        this->idcapa = idcapa;
        siguiente = NULL;
    }
    
};

class ListaSimpleCapas {
public:
    Capa* primero;
    Capa* ultimo;
    
    ListaSimpleCapas(){
        primero = NULL;
        ultimo = NULL;
        
    }
    
    void ingresarCapa(std::string idcapa);
    bool existeCapa(std::string idcapa);
    int NumerodeCapas();
private:

};

#endif /* LISTASIMPLECAPAS_H */

