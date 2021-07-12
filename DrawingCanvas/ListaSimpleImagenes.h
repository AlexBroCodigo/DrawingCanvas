/* 
 * File:   ListaSimpleImagenes.h
 * Author: AlexelBro
 *
 * Created on 20 de junio de 2019, 12:13
 */

#ifndef LISTASIMPLEIMAGENES_H
#define LISTASIMPLEIMAGENES_H
#include <iostream>

class Img{
public:
    std::string idimagen;
    Img* siguiente;
    
    Img(std::string idimagen){
        this->idimagen = idimagen;
        siguiente = NULL;
    }
    
};


class ListaSimpleImagenes {
public:
    Img* primero;
    Img* ultimo;
    
    ListaSimpleImagenes(){
        primero = NULL;
        ultimo = NULL;
    }
    
    void ingresarImagen(std::string idimagen);
    void eliminarImagen(std::string idimagen);
    Img* buscarImagen(std::string idimagen);
private:

};

#endif /* LISTASIMPLEIMAGENES_H */

