/* 
 * File:   ListaCircularImagenes.cpp
 * Author: AlexelBro
 * 
 * Created on 16 de junio de 2019, 18:51
 */

#include "ListaCircularImagenes.h"
void ListaCircularImagenes :: ingresarImagen(int img){
    NodoImagen* nuevo = new NodoImagen(img);
    if(primero==NULL){
        primero = nuevo;
        ultimo = nuevo;
        primero->siguiente = primero;
        primero->anterior = ultimo;
    }else{
        ultimo->siguiente = nuevo;
        nuevo->anterior = ultimo;
        nuevo->siguiente = primero;
        ultimo=nuevo;
        primero->anterior = ultimo;
    }
}

NodoImagen* ListaCircularImagenes :: buscarImagen(int img){
    NodoImagen* actual = primero;
    do{
        if(actual->imagen==img){
            return actual;
        }
        actual = actual->siguiente;
    } while(actual!=primero);
    return NULL;
}

string ListaCircularImagenes :: castear(int i){
    std::string cadenai = static_cast<std::ostringstream*>(&(std::ostringstream() << i))->str();
    return cadenai;
}



void ListaCircularImagenes :: eliminarImagen(int img){
    NodoImagen* actual = primero;
    do{
        if(actual->imagen==img){
            if(actual==primero){
                ultimo->siguiente = primero->siguiente;
                primero->siguiente->anterior = ultimo;
                primero = primero->siguiente;
            } else if(actual==ultimo){
                primero->anterior = ultimo->anterior;
                ultimo->anterior->siguiente = primero;
                ultimo = ultimo->anterior;
            }else{
                actual->anterior->siguiente = actual->siguiente;
                actual->siguiente->anterior = actual->anterior;
            }
            actual->siguiente = NULL;
            actual->anterior = NULL;
            std::cout << "Imagen eliminada de la lista circular de imagenes" << std::endl;
            break;
        }
        actual = actual->siguiente;
    } while(actual!=primero);
}

void ListaCircularImagenes :: generarGrafica(){
    dotimagenes = "digraph Imagenes{\n nodesep=0.5;\n node[shape=box, fillcolor=white,style=filled];\n edge[color=\"#FF9B00\"];\n";
    escribirDot();
    ofstream archivo;
    archivo.open("GraficaImagenes.dot",ios::out);
    
    if(archivo.fail()){
        cout << "No se pudo abrir el archivo";
    }
    archivo << dotimagenes + "\n}";
    archivo.close();
    dotimagenes = "";
    system("dot GraficaImagenes.dot -Tpng -o GraficaImagenes.png");
    ShellExecute(NULL,"open","GraficaImagenes.png","","",0);
}

void ListaCircularImagenes :: escribirDot(){
    
    NodoImagen* actual = primero;
    if(actual!=NULL){
        do{
            dotimagenes+="nodocircular"+castear(actual->imagen)+" [label=\"Imagen: "+castear(actual->imagen)+"\"];\n";
        
            actual = actual->siguiente;
        } while(actual!=primero);
    
        do{
            dotimagenes+="nodocircular"+castear(actual->imagen)+" -> nodocircular"+castear(actual->siguiente->imagen)+"[constraint=false];\n";
            dotimagenes+= "nodocircular"+castear(actual->imagen)+" -> nodocircular"+castear(actual->anterior->imagen)+"[constraint=false];\n";
            actual = actual->siguiente;
        } while(actual!=primero);
    }
    
    actual = primero;
    Capa* auxcapa;
        do{
            auxcapa = actual->listacapas->primero;
            if(auxcapa!=NULL){
                dotimagenes += "nodocircular"+castear(actual->imagen)+" -> simplecapa"+castear(actual->imagen)+auxcapa->idcapa+" [constraint=true];\n";
                while(auxcapa!=NULL){
                    dotimagenes += "simplecapa"+castear(actual->imagen)+auxcapa->idcapa+" [label=\"capa: "+auxcapa->idcapa+"\"];\n";
                    if(auxcapa->siguiente!=NULL){
                        dotimagenes += "simplecapa"+castear(actual->imagen)+auxcapa->idcapa+" -> simplecapa"+castear(actual->imagen)+auxcapa->siguiente->idcapa+" [constraint=true];\n";
                    }
                    auxcapa = auxcapa->siguiente;
                }
            }
            actual = actual->siguiente;
        } while(actual!=primero);
            
            
}

