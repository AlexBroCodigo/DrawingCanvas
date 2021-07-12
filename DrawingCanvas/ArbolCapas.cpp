/* 
 * File:   ArbolCapas.cpp
 * Author: AlexelBro
 * 
 * Created on 16 de junio de 2019, 13:50
 */

#include "ArbolCapas.h"

void ArbolCapas :: Praiz(NodoCapa* r){
    raiz = r;
}

NodoCapa* ArbolCapas :: Oraiz(){
    return raiz;
}

bool ArbolCapas :: esVacio(){
    return (raiz==NULL) ? true: false;
}

NodoCapa* ArbolCapas :: hijoIzdo(){
    if(raiz)
    return raiz->subarbolIzdo();
    else
    throw " arbol vacio";
}

NodoCapa* ArbolCapas :: hijoDcho(){
    if(raiz)
    return raiz->subarbolDcho();
    else
    throw " arbol vacio";
}

NodoCapa* ArbolCapas::buscarCapa(NodoCapa* r,NodoCapa* capanula,int capa){
    if (r != NULL){
        if(r->capa==capa){
            capanula = r;
            return capanula;
        } else{
            if(r->subarbolIzdo()!=NULL && capanula==NULL){
               capanula = buscarCapa(r->subarbolIzdo(),capanula,capa);
            }
            if(r->subarbolDcho()!=NULL && capanula==NULL){
               capanula = buscarCapa(r->subarbolDcho(),capanula,capa);
            }
            return capanula;
        }
    }
}

void ArbolCapas::Preorden(){
    Preorden(raiz);
}

void ArbolCapas::Preorden(NodoCapa* r){
    if (r != NULL){
        r->visitar();
        Preorden(r->subarbolIzdo());
        Preorden(r->subarbolDcho());
    }
}

void ArbolCapas::inorden(){
    inorden(raiz);
}

void ArbolCapas::inorden(NodoCapa* r){
    if (r != NULL){
        inorden (r->subarbolIzdo());
        r->visitar();
        inorden (r->subarbolDcho());
    }
}

void ArbolCapas::Postorden(){
    Postorden(raiz);
}

void ArbolCapas::Postorden(NodoCapa* r){
    if (r != NULL){
        Postorden(r->subarbolIzdo());
        Postorden(r->subarbolDcho());
        r->visitar(); 
    }
}

int ArbolCapas :: profundidad(NodoCapa* r){
    if (r == NULL){
        return -1;
    } else{
        return max(profundidad(r->subarbolIzdo()),profundidad(r->subarbolDcho())) + 1;
    }
}



string ArbolCapas :: castear(int i){
    std::string cadenai = static_cast<std::ostringstream*>(&(std::ostringstream() << i))->str();
    return cadenai;
}



void ArbolCapas::CapasHojas(NodoCapa* r){
    if (r != NULL){
        CapasHojas(r->subarbolIzdo());
        if(r->subarbolIzdo()==NULL && r->subarbolDcho()==NULL){
            cout << "Capa: " << castear(r->getCapa()) << endl;
        }
        CapasHojas(r->subarbolDcho());
    }
}



void ArbolCapas::insertar(NodoCapa* nuevo){
    raiz = insertar(raiz,nuevo);
}

NodoCapa* ArbolCapas::insertar(NodoCapa* raizSub, NodoCapa* nuevo){
    if (raizSub == NULL)
        raizSub = nuevo;
    else if (nuevo->capa < raizSub->getCapa()){
        NodoCapa* iz;
        iz = insertar(raizSub->subarbolIzdo(),nuevo);
        raizSub->ramaIzdo(iz);
}
    else if (nuevo->capa > raizSub->getCapa()){
        NodoCapa* dr;
        dr = insertar(raizSub->subarbolDcho(),nuevo);
        raizSub->ramaDcho(dr);
}
    else
    throw "Nodo duplicado"; // tratamiento de repetición
    return raizSub;
}

void ArbolCapas:: generarGrafica(){

    escribirdot(raiz);
    ofstream archivo;
    string textodot = "digraph g{\n node [shape = record,height=.1, color=\"#1A0082\"];\n edge[color=\"#009BFF\"];\n";
    textodot += dotarbol;
    dotarbol="";
    archivo.open("ArbolCapasBusqueda.dot",ios::out); 
    
    if(archivo.fail()){
        cout << "No se pudo abrir el archivo";
    }
    
    archivo << textodot + "\n}";
    archivo.close();
    system("dot ArbolCapasBusqueda.dot -Tpng -o ArbolCapasBusqueda.png");
    ShellExecute(NULL,"open","ArbolCapasBusqueda.png","","",0);

}

void ArbolCapas:: generarGraficaEspejo(){

    escribirdotEspejo(raiz);
    ofstream archivo;
    string textodot = "digraph g{\n node [shape = record,height=.1, color=\"#1A0082\"];\n edge[color=\"#009BFF\"];\n";
    textodot += dotarbolespejo;
    dotarbolespejo="";
    archivo.open("ArbolCapasEspejo.dot",ios::out); 
    
    if(archivo.fail()){
        cout << "No se pudo abrir el archivo";
    }
    
    archivo << textodot + "\n}";
    archivo.close();
    system("dot ArbolCapasEspejo.dot -Tpng -o ArbolCapasEspejo.png");
    ShellExecute(NULL,"open","ArbolCapasEspejo.png","","",0);

}


void ArbolCapas::escribirdot(NodoCapa *r){
    if (r != NULL){
        dotarbol += "nodeAC" + castear(r->capa) + "[label = \"<f0> | <f1> " + castear(r->capa) + " | <f2>\"];\n";
        escribirdot(r->subarbolIzdo());
        if(r->izq != NULL){
            dotarbol+= "\"nodeAC" + castear(r->capa)+"\":f0 -> \"nodeAC" + castear(r->izq->capa) + "\":f1;\n";
        }
        escribirdot(r->subarbolDcho());
        if(r->der != NULL){
            dotarbol+= "\"nodeAC" + castear(r->capa)+"\":f2 -> \"nodeAC" + castear(r->der->capa) + "\":f1;\n";
        }
    }
}

void ArbolCapas::escribirdotEspejo(NodoCapa *r){
    if (r != NULL){
        dotarbolespejo += "nodeAC" + castear(r->capa) + "[label = \"<f0> | <f1> " + castear(r->capa) + " | <f2>\"];\n";
        escribirdotEspejo(r->subarbolDcho());
        if(r->der != NULL){
            dotarbolespejo+= "\"nodeAC" + castear(r->capa)+"\":f0 -> \"nodeAC" + castear(r->der->capa) + "\":f1;\n";
        }
        escribirdotEspejo(r->subarbolIzdo());
        if(r->izq != NULL){
            dotarbolespejo+= "\"nodeAC" + castear(r->capa)+"\":f2 -> \"nodeAC" + castear(r->izq->capa) + "\":f1;\n";
        }
    }
}

