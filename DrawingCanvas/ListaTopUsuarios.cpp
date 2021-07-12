/* 
 * File:   ListaTopUsuarios.cpp
 * Author: AlexelBro
 * 
 * Created on 25 de junio de 2019, 17:29
 */

#include "ListaTopUsuarios.h"

void ListaTopUsuarios :: ingresarUsuarioTop(string usuario,int numimagenes){
    NodoTopUsuario* nuevo = new NodoTopUsuario(usuario,numimagenes);
    if(primero==NULL){
        primero = nuevo;
        ultimo = nuevo;
        primero->siguiente = ultimo;
    } else{
        ordenarLista(nuevo);
    }
}


void ListaTopUsuarios :: imprimirTopCinco(){
    NodoTopUsuario* actual = primero;
    for(int i = 1;i<=5;i++){
        if(actual != NULL){
            cout << castear(i) << ". Usuario: "<< actual->usuario << " con numero de imagenes: " << castear(actual->numeroimagenes) << endl;
        }
        actual = actual->siguiente;
    }
}

string ListaTopUsuarios :: castear(int i){
    std::string cadenai = static_cast<std::ostringstream*>(&(std::ostringstream() << i))->str();
    return cadenai;
}

void ListaTopUsuarios :: ordenarLista(NodoTopUsuario* nuevo){
    
    if(primero->numeroimagenes < nuevo->numeroimagenes){
        nuevo->siguiente = primero;
        primero = nuevo;
    }
    else if(ultimo->numeroimagenes >= nuevo->numeroimagenes){
        ultimo->siguiente = nuevo;
        ultimo=nuevo;
    }
    else
    {
        NodoTopUsuario* auxiliar = primero;
        NodoTopUsuario* otroauxiliar = auxiliar;
        while(auxiliar!=NULL){
            if(auxiliar->numeroimagenes < nuevo->numeroimagenes){
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