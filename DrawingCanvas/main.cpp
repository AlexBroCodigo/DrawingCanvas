/* 
 * File:   main.cpp
 * Author: AlexelBro
 *
 * Created on 15 de junio de 2019, 18:32
 */

#include <cstdlib>
#include "ListaCabeceras.h"
#include "ArbolCapas.h"
#include "ArbolAvlUsuarios.h"
#include "ListaCircularImagenes.h"
#include "ListaTopImagenes.h"
#include "ListaTopUsuarios.h"
#include <cctype>



//Métodos generales
void menuPrincipal();
bool esNumero(string linea);
string castear(int i);
void lecturaCapas();
void lecturaImagenes();
void lecturaUsuarios();
void funcionalidades();
void generacionImagenes();
void porRecorridoLimitado();
void recorridoPreordenCapas(NodoCapa* r,NodoImagen* imagen,int* numcapas);
void recorridoInordenCapas(NodoCapa* r,NodoImagen* imagen,int* numcapas);
void recorridoPostordenCapas(NodoCapa* r,NodoImagen* imagen,int* numcapas);
void porListaImagenes();
void generarImagenporId(NodoCapa* r,Capa* capaactual);
void porCapa();
void porUsuario();

void gestionarABC();
void gestionarUsuarios();
void gestionarImagenes();
void agregarImagenABC();
void eliminarImagenABC();

void estadoMemoria();
void verImagenCapas();
void generarImagenCapas(NodoImagen* imagen);
void escribirImagenCapas(NodoImagen* actual);
void dibujarArbolCapas(NodoCapa* r);

void reportes();
void topCincoImagenesCapas();
void topCincoUsuariosImagenes();
void recorrerUsuarios(NodoAvlUsuario* r,ListaTopUsuarios* topusuarios);




//Instancias de memorias
ArbolCapas* arbolcapas = new ArbolCapas();
ListaCircularImagenes* imagenes = new ListaCircularImagenes();
ArbolAvlUsuarios* usuarios = new ArbolAvlUsuarios();
MatrizCapa* auxmatriz = new MatrizCapa();
int contador = 0;
string dotenlaces ="";



int main(int argc, char** argv) {
    menuPrincipal();
    return 0;
}

void menuPrincipal(){
    int opcionmenu=0;
    bool cargahecha = false;
    string linea;
    
    while(opcionmenu!=3){
        cout << "______________Drawing Canvas_______________" << endl;
        cout << "Seleccione una opcion:" << endl;
        cout << "1. Carga masiva de archivos" << endl;
        cout << "2. Funcionalidades" << endl;
        cout << "3. Salir" << endl;
        getline(cin,linea);
        if(esNumero(linea)){
            opcionmenu=atoi(linea.c_str());  
            if(opcionmenu==1 && cargahecha==false){
                lecturaCapas();
                lecturaImagenes();
                lecturaUsuarios();
                cargahecha = true;
                cout << "Cargas masivas realizadas exitosamente." << endl;
                funcionalidades();
            } else if(opcionmenu==1 && cargahecha==true){
                 cout << "Las cargas masivas ya fueron realizadas con exito." << endl;   
            } else if(opcionmenu==2 && cargahecha==false){
                 cout << "Primero realice la carga masiva de archivos por favor." << endl;   
            } else if(opcionmenu==2 && cargahecha==true){
                funcionalidades();
            } else if(opcionmenu==3){
                
            } else{
                cout << "Ingrese un numero de las opciones por favor." << endl;
            }
            
        } else {
            cout << "Entrada escrita invalida, intentelo nuevamente." << endl;
        }
    }
    
}

bool esNumero(string linea){
   bool esnumero = true;
   int longitud = linea.size();
 
   if (longitud == 0) {
      esnumero = false;
   } else if (longitud == 1 && !isdigit(linea[0])) {
      esnumero = false;
   } else{
       int i = 0;
      while (i < longitud) {
         if (!isdigit(linea[i])) {
            esnumero = false;
            break;
         }
         i++;
      }
   }
   
   return esnumero;
}

string castear(int i){
    std::string cadenai = static_cast<std::ostringstream*>(&(std::ostringstream() << i))->str();
    return cadenai;
}


void funcionalidades(){
    int opcionfuncion = 0;
    string linea;
    while(opcionfuncion!=5){
        cout << "*Funcionalidades" << endl;
        cout << "¿Que desea hacer?" << endl;
        cout << "1. Generar imagen" << endl;
        cout << "2. Gestionar ABC" << endl;
        cout << "3. Ver estado de la memoria" << endl;
        cout << "4. Ver otros reportes" << endl;
        cout << "5. Salir de funcionalidades" << endl;
        getline(cin,linea);
        
        if(esNumero(linea)){
            opcionfuncion = atoi(linea.c_str());
            if(opcionfuncion==1){
                generacionImagenes();
            } else if(opcionfuncion==2){
                gestionarABC();
            } else if(opcionfuncion==3){
                estadoMemoria();
            } else if(opcionfuncion==4){
                reportes();
            } else if(opcionfuncion==5){
                cout << "Saliendo de funcionalidades ... " << endl;
            } else{
                cout<< "Ingrese un numero de las opciones por favor." << endl;
            }
        } else{
            cout << "Entrada escrita invalida, intentelo nuevamente." << endl;
        }
    }
    
    
}

void generacionImagenes(){
    string linea;
    int opcionimg = 0;
    while(opcionimg!=5){
        cout << "+Generacion de imagenes" << endl;
        cout << "Seleccione una opcion:" << endl;
        cout << "1. Por recorrido limitado" << endl;
        cout << "2. Por lista de imagenes" << endl;
        cout << "3. Por capa" << endl;
        cout << "4. Por usuario" << endl;
        cout << "5. Salir de generacion de imagenes" << endl;
        getline(cin,linea);
        if(esNumero(linea)){
            opcionimg = atoi(linea.c_str());
            if(opcionimg==1){
                porRecorridoLimitado();
            } else if(opcionimg==2){
                porListaImagenes();
            }  else if(opcionimg==3){
                porCapa();
            }  else if(opcionimg==4){
                porUsuario();
            }  else if(opcionimg==5){
                cout << "Saliendo de generacion de imagenes ..." << endl;
            } else {
                cout << "Ingrese un numero de las opciones por favor." << endl;
            }
        } else{
            cout << "Entrada escrita invalida, intentelo nuevamente." << endl;
        }
    }
    
}

void porRecorridoLimitado(){
    string linea;
    int numcapas = 0;
    int tiporecorrido = 0;
    int idimagen = 0;
    
    NodoImagen* imagenactual;
    
    
    bool idcorrecto = false;
    bool esnumcapa = false;
    
    while(idcorrecto!=true){
        cout << "Ingrese el identificador de la imagen a graficar: " << endl;
        getline(cin,linea);
        if(esNumero(linea)){
            idimagen=atoi(linea.c_str());
            imagenactual = imagenes->buscarImagen(idimagen);
                if(imagenactual==NULL){
                    cout << "No existe esa imagen en el sistema, intentelo nuevamente." <<endl;
                } else{
                    idcorrecto=true;
                    cout << "Imagen encontrada en el sistema." << endl;
                }
        } else{
            cout << "Entrada invalida para el identificador de la imagen, intentelo nuevamente con un numero por favor." << endl;
        }
    }
    
    while(esnumcapa!=true){
        cout << "Ingrese el numero de capas a utilizar: " << endl;
        getline(cin,linea);
        if(esNumero(linea)){
            numcapas = atoi(linea.c_str());
            esnumcapa = true;
        } else{
            cout << "Entrada invalida para el numero de capas, intentelo nuevamente." << endl;
        }
    }
    
    do{
        cout << "Seleccione el tipo de recorrido:" << endl;
        cout << "1.Preorden" << endl;
        cout << "2.Inorden" << endl;
        cout << "3.Postorden" << endl;
        getline(cin,linea);
        if(esNumero(linea)){
            tiporecorrido = atoi(linea.c_str());
            if(tiporecorrido == 1 || tiporecorrido==2 || tiporecorrido==3){
                
            } else{
                cout << "Ingrese un numero de las opciones por favor." << endl;
            }
        } else{
            cout << "Entrada invalida, intentelo nuevamente." << endl;
        }
    } while(tiporecorrido != 1 && tiporecorrido!=2 && tiporecorrido!=3);
    
    
    if(imagenactual->listacapas->primero!=NULL && numcapas!=0){
        
        if(tiporecorrido==1){
            recorridoPreordenCapas(arbolcapas->Oraiz(),imagenactual,&numcapas);
            contador = 0;
            auxmatriz->generarGrafica();
            auxmatriz->generarLienzo();
            auxmatriz = new MatrizCapa();
        } else if(tiporecorrido==2){
            recorridoInordenCapas(arbolcapas->Oraiz(),imagenactual,&numcapas);
            contador = 0;
            auxmatriz->generarGrafica();
            auxmatriz->generarLienzo();
            auxmatriz = new MatrizCapa();
        } else if(tiporecorrido==3){
            recorridoPostordenCapas(arbolcapas->Oraiz(),imagenactual,&numcapas);
            contador = 0;
            auxmatriz->generarGrafica();
            auxmatriz->generarLienzo();
            auxmatriz = new MatrizCapa();
        }
    } else {
        auxmatriz->agregarPixel(0,0,"#000000");
        auxmatriz->generarGrafica();
        auxmatriz->generarLienzo();
        auxmatriz = new MatrizCapa();
    }
    
}

void recorridoPreordenCapas(NodoCapa* r,NodoImagen* imagen,int* numcapas){
    if (r != NULL && contador!=*numcapas){
        Capa* actual = imagen->listacapas->primero;
        while(actual!=NULL){
            if(r->capa==atoi(actual->idcapa.c_str())){
                NodoLateral* lateral = r->matrizcapa->laterales->primero;
                while(lateral!=NULL){
                    NodoDispersa* nodocolor = lateral->fila->primero;
                    while(nodocolor!=NULL){
                        auxmatriz->agregarPixel(nodocolor->posx,nodocolor->posy,nodocolor->color);
                        nodocolor = nodocolor->derecha;
                    }
                    lateral = lateral->siguiente;
                }
                ++contador;
                break;
            }
            actual = actual->siguiente;
        }
        recorridoPreordenCapas(r->subarbolIzdo(),imagen,numcapas);
        recorridoPreordenCapas(r->subarbolDcho(),imagen,numcapas);
    }
}

void recorridoInordenCapas(NodoCapa* r,NodoImagen* imagen,int* numcapas){
    if (r != NULL && contador!=*numcapas){
        recorridoInordenCapas(r->subarbolIzdo(),imagen,numcapas);
        Capa* actual = imagen->listacapas->primero;
        while(actual!=NULL){
            if(r->capa==atoi(actual->idcapa.c_str())){
                NodoLateral* lateral = r->matrizcapa->laterales->primero;
                while(lateral!=NULL){
                    NodoDispersa* nodocolor = lateral->fila->primero;
                    while(nodocolor!=NULL){
                        auxmatriz->agregarPixel(nodocolor->posx,nodocolor->posy,nodocolor->color);
                        nodocolor = nodocolor->derecha;
                    }
                    lateral = lateral->siguiente;
                }
                ++contador;
                break;
            }
            actual = actual->siguiente;
        }
        recorridoInordenCapas(r->subarbolDcho(),imagen,numcapas);
    }
}

void recorridoPostordenCapas(NodoCapa* r,NodoImagen* imagen,int* numcapas){
    if (r != NULL && contador!=*numcapas){
        recorridoPostordenCapas(r->subarbolIzdo(),imagen,numcapas);
        recorridoPostordenCapas(r->subarbolDcho(),imagen,numcapas);
        Capa* actual = imagen->listacapas->primero;
        while(actual!=NULL){
            if(r->capa==atoi(actual->idcapa.c_str())){
                NodoLateral* lateral = r->matrizcapa->laterales->primero;
                while(lateral!=NULL){
                    NodoDispersa* nodocolor = lateral->fila->primero;
                    while(nodocolor!=NULL){
                        auxmatriz->agregarPixel(nodocolor->posx,nodocolor->posy,nodocolor->color);
                        nodocolor = nodocolor->derecha;
                    }
                    lateral = lateral->siguiente;
                }
                ++contador;
                break;
            }
            actual = actual->siguiente;
        }
    }
}

void porListaImagenes(){
    string linea;
    NodoImagen* imagen;
    bool esnumeroexistente = false;
    while(esnumeroexistente!=true){
        cout << "Ingrese el id de la imagen que desea graficar:" << endl;
        getline(cin,linea);
        if(esNumero(linea)){
            imagen = imagenes->buscarImagen(atoi(linea.c_str()));
            if(imagen!=NULL){
                esnumeroexistente = true;
                Capa* capaactual = imagen->listacapas->primero;
                if(capaactual!=NULL){
                    while(capaactual!=NULL){
                        generarImagenporId(arbolcapas->Oraiz(),capaactual);
                        capaactual = capaactual->siguiente;
                    }
                auxmatriz->generarGrafica();
                auxmatriz->generarLienzo();
                auxmatriz = new MatrizCapa();
                } else{
                    auxmatriz->agregarPixel(0,0,"#000000");
                    auxmatriz->generarGrafica();
                    auxmatriz->generarLienzo();
                    auxmatriz = new MatrizCapa();
                }
            } else{
                cout << "Id no existente en la lista de imagenes, intentelo de nuevo por favor." << endl;
            }
        } else {
            cout << "Id invalido, intentelo con un numero por favor." << endl;
        }
    }
    
}

void generarImagenporId(NodoCapa* r,Capa* capaactual){
    if (r != NULL){
        if(r->capa==atoi(capaactual->idcapa.c_str())){
            NodoLateral* lateral = r->matrizcapa->laterales->primero;
            while(lateral!=NULL){
                NodoDispersa* nodocolor = lateral->fila->primero;
                while(nodocolor!=NULL){
                    auxmatriz->agregarPixel(nodocolor->posx,nodocolor->posy,nodocolor->color);
                    nodocolor = nodocolor->derecha;
                }
                    lateral = lateral->siguiente;
                }
        } else{
            generarImagenporId(r->subarbolIzdo(),capaactual);
            generarImagenporId(r->subarbolDcho(),capaactual);
        }
    }
}

void porCapa(){
    string linea;
    bool capacorrecta = false;
    while(capacorrecta!=true){
        cout << "Ingrese id de capa a graficar por favor:" << endl;
        getline(cin,linea);
        if(esNumero(linea)){
            NodoCapa* capanula = NULL;
            NodoCapa* nodocapa = arbolcapas->buscarCapa(arbolcapas->Oraiz(),capanula,atoi(linea.c_str()));
            if(nodocapa!=NULL){
                capacorrecta=true;
                nodocapa->matrizcapa->generarGrafica();
                nodocapa->matrizcapa->generarLienzo();
            } else{
                cout << "Id de capa no existente en el sistema, intentelo con otro id por favor." << endl;
            }
        } else{
            cout << "Entrada invalida, por favor ingrese un numero." << endl;
        }
    }
    
}

void porUsuario(){
    string linea;
    bool usuarioexiste = false;
    
    while(usuarioexiste!=true){
        cout << "Usuarios: " << endl;
        usuarios->preorden();
        cout << "Ingrese el nombre del usuario que desea buscar:" << endl;
        getline(cin,linea);
        NodoAvlUsuario* usuarionulo = NULL;
        NodoAvlUsuario* usuario = usuarios->buscarUsuario(usuarios->Oraiz(),usuarionulo,linea);
        if(usuario!=NULL){
            Img* imagen = usuario->listaimagenes->primero;
            if(imagen!=NULL){
                usuarioexiste=true;
                bool imagencorrecta = false;
                while(imagencorrecta!=true){
                    cout << "Seleccione una imagen de la lista de imagenes:" << endl;
                    while(imagen!=NULL){
                        cout << "-" << imagen->idimagen << endl;
                        imagen = imagen->siguiente;
                    }
                    imagen = usuario->listaimagenes->primero;
                    getline(cin,linea);
                    if(esNumero(linea)){
                        NodoImagen* nodoimagen = imagenes->buscarImagen(atoi(linea.c_str()));
                        if(nodoimagen!=NULL){
                            imagencorrecta=true;
                            Capa* capaactual = nodoimagen->listacapas->primero;
                            if(capaactual!=NULL){
                                while(capaactual!=NULL){
                                    generarImagenporId(arbolcapas->Oraiz(),capaactual);
                                    capaactual = capaactual->siguiente;
                                }
                                auxmatriz->generarGrafica();
                                auxmatriz->generarLienzo();
                                auxmatriz = new MatrizCapa();
                            } else{
                                auxmatriz->agregarPixel(0,0,"#000000");
                                auxmatriz->generarGrafica();
                                auxmatriz->generarLienzo();
                                auxmatriz = new MatrizCapa();
                            }
                        } else{
                            cout << "Imagen no existe en memoria pero si en carga de archivos, corrige el archivo para una posterior carga por favor." << endl;
                        }
                    } else{
                        cout << "Entrada invalida, seleccione un numero de la lista de imagenes por favor." << endl;
                    }
                }
            } else{
                cout << "Este usuario no tiene registrado ninguna imagen, busque imagenes en otro usuario." << endl;
            }
            
        } else{
            cout << "Usuario no existente en el sistema, ingrese uno de las opciones por favor." << endl;
        }
    }
}



void gestionarABC(){
    int opcionabc = 0;
    string linea;
    while(opcionabc!=3){
        cout << "+ABC:" << endl;
        cout << "Seleccione una opcion a gestionar:" << endl;
        cout << "1. Usuarios" << endl;
        cout << "2. Imagenes" << endl;
        cout << "3. Salir de ABC" << endl;
        getline(cin,linea);
        if(esNumero(linea)){
            opcionabc = atoi(linea.c_str());
            switch(opcionabc){
                case 1:
                    gestionarUsuarios();
                    break;
                case 2:
                    gestionarImagenes();
                    break;
                case 3: 
                    cout << "Saliendo de gestionar ABC..." << endl;
                    break;
                default: 
                    cout << "Entrada incorrecta, ingrese un numero de las opciones por favor." << endl;
            }
            
        } else{
            cout << "Entrada invalida, ingrese un numero de las opciones por favor." << endl;
        }
        
        
        
    }
    
    
}

void gestionarUsuarios(){
    string linea;
    int opgestion = 0;
    bool usuariocorrecto = false;
    while(opgestion!=2){
        usuariocorrecto= false;
        cout << "*Gestion de Usuarios:" << endl;
        cout << "1. Agregar usuario:" << endl;
        cout << "2. Salir de gestion de usuarios." << endl;
        getline(cin,linea);
        if(esNumero(linea)){
            opgestion = atoi(linea.c_str());
            switch(opgestion){
                case 1:
                    while(usuariocorrecto!=true){
                        cout << "Ingrese el nombre del usuario a agregar:" << endl;
                        getline(cin,linea);
                        NodoAvlUsuario* usuarionulo = NULL;
                        NodoAvlUsuario* user = usuarios->buscarUsuario(usuarios->Oraiz(),usuarionulo,linea);
                        if(user==NULL){
                            usuariocorrecto=true;
                            NodoAvlUsuario* nuevo = new NodoAvlUsuario(linea);
                            usuarios->insertarAvl(nuevo);
                            cout << "Usuario agregado al sistema." << endl;
                        } else{
                            cout << "Usuario ya existente, intentelo con otro nombre por favor." << endl;
                        }
                    }
                    break;
                case 2:
                    cout << "Saliendo de gestion de usuarios..." << endl;
                    break;
                default:
                    cout << "Opcion incorrecta, ingrese un numero de las opciones por favor." << endl;
            }
        } else {
            cout << "Entrada invalida, ingrese un numero de las opciones por favor." << endl;
        }
    }
}



void gestionarImagenes(){
    int opcionimg = 0;
    string linea;
    while(opcionimg!=3){
        cout << "*Gestion de imagenes:" << endl;
        cout << "1. Agregar imagen:" << endl;
        cout << "2. Eliminar imagen " << endl;
        cout << "3. Salir de gestion de imagenes." << endl;
        getline(cin,linea);
        if(esNumero(linea)){
            opcionimg = atoi(linea.c_str());
            switch(opcionimg){
                case 1:
                    agregarImagenABC();
                    break;
                case 2:
                    eliminarImagenABC();
                    break;
                case 3:
                    cout << "Saliendo de gestion de imagenes..." << endl;
                    break;
                default:
                    cout << "Opcion incorrecta, ingrese un numero de las opciones por favor." << endl;
            }
        } else {
            cout << "Entrada invalida, ingrese un numero de las opciones por favor." << endl;
        }
        
        
    }
    
    
    
}

void agregarImagenABC(){
    string linea;
    bool usuariocorrecto = false;
    bool idcorrecto = false;
    while(usuariocorrecto!=true){
        cout << "Lista de usuarios:" << endl;
        usuarios->preorden();
        cout << "Seleccione un usuario ingresando su nombre por favor." << endl;
        getline(cin,linea);
        NodoAvlUsuario* usuarionulo = NULL;
        NodoAvlUsuario* user = usuarios->buscarUsuario(usuarios->Oraiz(),usuarionulo,linea);
        if(user!=NULL){
            usuariocorrecto = true;
            while(idcorrecto!=true){
                cout << "Ingrese un Id para la imagen por favor." << endl;
                getline(cin,linea);
                if(esNumero(linea)){
                    Img* image = user->listaimagenes->primero;
                    while(image!=NULL){
                        if(image->idimagen==linea){
                            break;
                        }
                        image = image->siguiente;
                    }
                    if(image==NULL){
                        NodoImagen* nodoimagen = imagenes->buscarImagen(atoi(linea.c_str()));
                        if(nodoimagen!=NULL){
                            idcorrecto=true;
                            user->listaimagenes->ingresarImagen(castear(nodoimagen->imagen));
                            cout << "Imagen agregada a la lista de imagenes del usuario exitosamente." << endl;
                        } else{
                            cout << "Esta imagen no se encuentra en el sistema, por lo tanto no se puede agregar al usuario." << endl;
                        }
                    } else{
                        cout << "Este id de imagen ya esta registrado. intente otro por favor" << endl;
                    }
                } else {
                    cout << "Entrada invalida, ingrese un numero por favor." << endl;
                }
            }
            
            
        } else{
            cout << "Usuario incorrecto, ingrese un usuario de la lista de usuarios por favor." << endl;
        }
    }  
            
}

void eliminarImagenABC(){
    string linea;
    bool usuariocorrecto = false;
    bool idcorrecto = false;
    while(usuariocorrecto!=true){
        cout << "Lista de usuarios:" << endl;
        usuarios->preorden();
        cout << "Seleccione un usuario ingresando el nombre por favor." << endl;
        getline(cin,linea);
        NodoAvlUsuario* usuarionulo = NULL;
        NodoAvlUsuario* user = usuarios->buscarUsuario(usuarios->Oraiz(),usuarionulo,linea);
        if(user!=NULL){
            usuariocorrecto=true;
            while(idcorrecto!=true){
                Img* image = user->listaimagenes->primero;
                cout << "Lista de imagenes del usuario:" << endl;
                while(image!=NULL){
                    cout << "-" << image->idimagen << endl;
                    image = image->siguiente;
                }
                cout << "Seleccione el id de la imagen a eliminar por favor." << endl;
                getline(cin,linea);
                if(esNumero(linea)){
                    image = user->listaimagenes->buscarImagen(linea);
                    if(image!=NULL){
                        idcorrecto=true;
                        string id = image->idimagen;
                        user->listaimagenes->eliminarImagen(id);
                        cout << "Imagen eliminada de la lista de imagenes del usuario." << endl;
                        imagenes->eliminarImagen(atoi(id.c_str()));
                    } else{
                        cout << "Id incorrecto, ingrese un id de la lista por favor." << endl;
                    }
                } else{
                    cout << "Entrada invalida, ingrese un numero de la lista de imagenes por favor." << endl;
                }
            }
            
        } else{
            cout << "Usuario incorrecto, ingrese un usuario de la lista de usuarios por favor." << endl;
        }
    }
}


void estadoMemoria(){
    string linea;
    int opcionmemoria = 0;
    bool idcorrecto = false;
    while(opcionmemoria!=7){
        cout << "+Estado de la Memoria" << endl;
        cout << "Seleccione una opcion:" << endl;
        cout << "1. Ver lista de imagenes " << endl;
        cout << "2. Ver arbol de capas" << endl;
        cout << "3. Ver arbol de capas espejo" << endl;
        cout << "4. Ver capa" << endl;
        cout << "5. Ver imagen y arbol de capas" << endl;
        cout << "6. Ver arbol de usuarios" << endl;
        cout << "7. Salir del estado de la memoria" << endl;
        getline(cin,linea);
        
        if(esNumero(linea)){
            opcionmemoria = atoi(linea.c_str());
            
            switch(opcionmemoria){
                case 1:
                    imagenes->generarGrafica();
                    break;
                case 2:
                    arbolcapas->generarGrafica();
                    break;
                case 3:
                    arbolcapas->generarGraficaEspejo();
                    break;
                case 4:
                    while(idcorrecto!=true){
                        cout << "Ingrese el id de la capa a mostrar:" << endl;
                        getline(cin,linea);
                        if(esNumero(linea)){
                            NodoCapa* capanula = NULL;
                            NodoCapa* capa = arbolcapas->buscarCapa(arbolcapas->Oraiz(),capanula,atoi(linea.c_str()));
                            if(capa!=NULL){
                                idcorrecto = true;
                                capa->matrizcapa->generarGrafica();
                            } else{
                                cout << "Capa no registrada en el sistema, intento con otro numero por favor." << endl;
                            }
                        } else{
                            cout << "Entrada invalida, ingrese un numero de capa por favor." << endl;
                        }
                    }
                    break;
                case 5: 
                    verImagenCapas();
                    break;
                case 6:
                    usuarios->generarGrafica();
                    break;
                case 7: 
                    cout << "Saliendo del estado de la memoria." << endl;
                    break;
                default:
                    cout << "Opcion incorrecta, ingrese un numero de las opciones por favor." << endl;
            }
            
        } else{
            cout << "Entrada invalida, ingrese un numero de las opciones por favor." << endl;
        }
        
        
        
    }
}

void verImagenCapas(){
    string linea;
    bool imagencorrecta = false;
    while(imagencorrecta!=true){
        NodoImagen* actual = imagenes->primero;
        cout << "Lista de Imagenes:" << endl;
        do{
            cout << "-" << actual->imagen << endl;
            actual = actual->siguiente;
        } while(actual!= imagenes->primero);
        cout << "Seleccione una imagen ingresando su id: " << endl;
        getline(cin,linea);
        if(esNumero(linea)){
            actual = imagenes->buscarImagen(atoi(linea.c_str()));
            if(actual!=NULL){
                imagencorrecta = true;
                generarImagenCapas(actual);
            } else{
                cout << "Id incorrecto, por favor seleccione una de la lista de imagenes." << endl;
            }
        } else{
            cout << "Entrada invalida, ingrese un numero de la lista de imagenes por favor." << endl;
        }
    }
    
}


void generarImagenCapas(NodoImagen* imagen){
    string textodot = "digraph ImagenCapasEnlaces{\n subgraph cluster_ArbolCapas{\n color=white;\n node[shape = record,height=.1, color=\"#1A0082\"];\n edge[color=\"#009BFF\"];\n";
    dibujarArbolCapas(arbolcapas->Oraiz());
    dotenlaces += "}\n";
    escribirImagenCapas(imagen);
    ofstream archivo;
    textodot += dotenlaces;
    dotenlaces="";
    archivo.open("ImagenEnlacesCapas.dot",ios::out); 
    if(archivo.fail()){
        cout << "No se pudo abrir el archivo";
    }
    
    archivo << textodot + "\n}";
    archivo.close();
    system("dot ImagenEnlacesCapas.dot -Tpng -o ImagenEnlacesCapas.png");
    ShellExecute(NULL,"open","ImagenEnlacesCapas.png","","",0);
}

void escribirImagenCapas(NodoImagen* actual){
    dotenlaces+= "subgraph cluster_ListaCapas{\n color=white;\n node[shape=box, fillcolor=white,style=filled];\n edge[color=\"#FF9B00\"];\n";
    dotenlaces += "nodocircular"+castear(actual->imagen)+" [label=\"Imagen: "+castear(actual->imagen)+"\"];\n";
    Capa* auxcapa;
    auxcapa = actual->listacapas->primero;
    if(auxcapa!=NULL){
        dotenlaces += "nodocircular"+castear(actual->imagen)+" -> simplecapa"+auxcapa->idcapa+" [constraint=true];\n";
        while(auxcapa!=NULL){
            dotenlaces += "simplecapa"+auxcapa->idcapa+" [label=\"capa: "+auxcapa->idcapa+"\"];\n";
            if(auxcapa->siguiente!=NULL){
                dotenlaces += "simplecapa"+auxcapa->idcapa+" -> simplecapa"+auxcapa->siguiente->idcapa+" [constraint=true];\n";
            }
            auxcapa = auxcapa->siguiente;
        }
        
        auxcapa = actual->listacapas->primero;
        while(auxcapa!=NULL){
            NodoCapa* capanula = NULL;
            NodoCapa* nodocapa = arbolcapas->buscarCapa(arbolcapas->Oraiz(),capanula,atoi(auxcapa->idcapa.c_str()));
            if(nodocapa!=NULL){
                dotenlaces += "simplecapa"+auxcapa->idcapa+" -> \"nodeAC"+castear(nodocapa->capa)+"\":f1;\n";
            }
            auxcapa = auxcapa->siguiente;
        }
    }
    dotenlaces += "}\n";
    
}

void dibujarArbolCapas(NodoCapa* r){
    if (r != NULL){
        dotenlaces += "nodeAC" + castear(r->capa) + "[label = \"<f0> | <f1> " + castear(r->capa) + " | <f2>\"];\n";
        dibujarArbolCapas(r->subarbolIzdo());
        if(r->izq != NULL){
            dotenlaces += "\"nodeAC" + castear(r->capa)+"\":f0 -> \"nodeAC" + castear(r->izq->capa) + "\":f1;\n";
        }
        dibujarArbolCapas(r->subarbolDcho());
        if(r->der != NULL){
            dotenlaces += "\"nodeAC" + castear(r->capa)+"\":f2 -> \"nodeAC" + castear(r->der->capa) + "\":f1;\n";
        }
    }
}

void reportes(){
    string linea;
    int opreporte=0;
    while(opreporte!=9){
        cout << "+------------------Reportes------------------+" << endl;
        cout << "1. Top 5 de imagenes con mas numero de capas" << endl;
        cout << "2. Todas las capas que son hojas" << endl;
        cout << "3. Profundidad de arbol de capas" << endl;
        cout << "4. Mostrar capas en postorden" << endl;
        cout << "5. Listar capas en: preorden, inorden, postorden" << endl;
        cout << "6. Top 5 de usuarios con mas imagenes" << endl;
        cout << "7. Arbol espejo de usuarios." << endl;
        cout << "8. Listar usuarios en recorrido: preorden, inorden, postorden, por niveles" << endl;
        cout << "9. Salir de reportes" << endl;
        cout << "Seleccione una opcion por favor:" << endl;
        getline(cin,linea);
        if(esNumero(linea)){
            opreporte = atoi(linea.c_str());
            switch(opreporte){
                case 1:
                    cout << "-TOP 5 de imagenes con mayor numero de capas." << endl;
                    topCincoImagenesCapas();
                    break;
                case 2:
                    cout << "-Capas que son hojas:" << endl;
                    arbolcapas->CapasHojas(arbolcapas->Oraiz());
                    break;
                case 3: 
                    cout << "-Profundidad de arbol binario de busqueda de capas:" << endl;
                    cout << "*" << castear(arbolcapas->profundidad(arbolcapas->Oraiz())) << endl;
                    break;
                case 4:
                    cout << "-Capas en postorden:" << endl;
                    arbolcapas->Postorden();
                    break;
                case 5:
                    cout << "-Listado de capas:" << endl;
                    cout << "*Preorden: " << endl;
                    arbolcapas->Preorden();
                    cout << "*Inorden:" << endl;
                    arbolcapas->inorden();
                    cout << "*Postorden:" << endl;
                    arbolcapas->Postorden();
                    break;
                case 6:
                    cout << "-TOP 5 de usuarios con mayor numero de imagenes." << endl;
                    topCincoUsuariosImagenes();
                    break;
                case 7:
                    cout << "-Arbol espejo de usuarios:" << endl;
                    usuarios->arbolespejo();
                    break;
                case 8:
                    cout << "-Usuarios en recorrido:" << endl;
                    cout << "*Preorden:" << endl;
                    usuarios->preorden();
                    cout << "*Inorden:" << endl;
                    usuarios->inorden();
                    cout << "*Postorden:" << endl;
                    usuarios->postorden();
                    break;
                case 9:
                    cout << "Saliendo de reportes..." << endl;
                    break;
                default:
                    cout << "Opcion incorrecta, ingrese un numero de las opciones por favor." << endl;
            }
        } else{
            cout << "Entrada escrita invalida, ingrese un numero de las opciones por favor." << endl;
        }
        
        
    }
    
}

void topCincoImagenesCapas(){
    NodoImagen* actual = imagenes->primero;
    ListaTopImagenes* mitop = new ListaTopImagenes();
    do{
        mitop->ingresarImagenTop(castear(actual->imagen),actual->listacapas->NumerodeCapas());
        actual = actual->siguiente;
    } while(actual!=imagenes->primero);
    
    mitop->imprimirTopCinco();
}

void topCincoUsuariosImagenes(){
    ListaTopUsuarios* topusuarios = new ListaTopUsuarios();
    recorrerUsuarios(usuarios->Oraiz(),topusuarios);
    topusuarios->imprimirTopCinco();
}

void recorrerUsuarios(NodoAvlUsuario* r,ListaTopUsuarios* topusuarios){
    if (r != NULL){
        Img* actual = r->listaimagenes->primero;
        int numimagenes = 0;
        while(actual!=NULL){
            numimagenes++;
            actual = actual->siguiente;
        }
        topusuarios->ingresarUsuarioTop(r->usuario,numimagenes);
        
        recorrerUsuarios(r->subarbolIzdo(),topusuarios);
        recorrerUsuarios(r->subarbolDcho(),topusuarios);
    }
}





void lecturaCapas(){
    string textocapas;
    string rutacapas;
    bool filecorrecto = false;
    ifstream archivo;
    while(filecorrecto!=true){
        cout << "Ingrese la ruta absoluta del archivo de capas:" << endl;
        getline(cin,rutacapas);
        archivo.open(rutacapas,ios::in);
        if(archivo.is_open()){
            char c;
            while(!archivo.eof()){
                c = archivo.get();
                if(c==' ' || c=='\n' || c=='\t' || c=='\r' || c=='\f' || c=='\377'){
                    
                } else {
                    textocapas += c;
                }
            }
            archivo.close();
            filecorrecto=true;
            cout << "Archivo de capas cargado exitosamente." << endl;
        } else {
            cout << "No se encontro o pudo abrir el archivo, ingrese la ruta correctamente por favor." << endl;
        }
    }
    
    
    int fila = 0;
    int columna = 0;
    string auxcadena = "";
    
    bool esidcapa = true;
    bool esfila = false;
    bool escolumna = false;
    bool escolor = false;
    
    NodoCapa* nuevacapa;
    for(int i = 0;i<textocapas.size();i++){
        
        if(textocapas[i]=='{' && esidcapa==true){
            esidcapa=false;
            esfila=true;
            nuevacapa = new NodoCapa(atoi(auxcadena.c_str()));
            auxcadena="";
        } else if(textocapas[i]==',' && esfila==true){
            esfila=false;
            escolumna=true;
            fila = atoi(auxcadena.c_str());
            auxcadena="";
        }  else if(textocapas[i]==',' && escolumna==true){
            escolumna=false;
            escolor=true;
            columna = atoi(auxcadena.c_str());
            auxcadena="";
        } else if(textocapas[i]==';' && escolor==true){
            escolor=false;
            esfila=true;
            nuevacapa->matrizcapa->agregarPixel(columna,fila,auxcadena);
            auxcadena="";
        } else if(textocapas[i]=='}'){
            esidcapa=true;
            esfila=false;
            arbolcapas->insertar(nuevacapa);
            
        } else {
          auxcadena += textocapas[i];   
        }   
    }
    
    
}

void lecturaImagenes(){
    string textoimg;
    string rutaimg;
    bool filecorrecto = false;
    ifstream archimagenes;
    while(filecorrecto!=true){
        cout << "Ingrese la ruta absoluta del archivo de imagenes:" << endl;
        getline(cin,rutaimg);
        archimagenes.open(rutaimg,ios::in);
        if(archimagenes.is_open()){
            char c;
            while(!archimagenes.eof()){
                c = archimagenes.get();
                if(c==' ' || c=='\n' || c=='\t' || c=='\r' || c=='\f' || c=='\377'){
                
                } else {
                    textoimg += c;
                }
            }
            archimagenes.close();
            filecorrecto=true;
            cout << "Archivo de imagenes cargado exitosamente." << endl;
        } else {
            cout << "No se encontro o pudo abrir el archivo, ingrese la ruta correctamente por favor." << endl; 
        }
    }
    
    
    bool esidimagen = true;
    bool esidcapa = false;
    string cadena = "";
    
    NodoImagen* imagenactual;
    
    for(int j=0;j<textoimg.size();j++){
        if(textoimg[j]=='{' && esidimagen==true){
            esidimagen=false;
            esidcapa = true;
            imagenes->ingresarImagen(atoi(cadena.c_str()));
            imagenactual = imagenes->ultimo;
            cadena="";
        } else if(textoimg[j]==',' && esidcapa==true){
            if(!imagenactual->listacapas->existeCapa(cadena)){
                imagenactual->listacapas->ingresarCapa(cadena);
            }
            
            cadena="";
        } else if(textoimg[j]=='}' && esidcapa==true){
            esidcapa=false;
            esidimagen=true;
            if(cadena!=""){
                if(!imagenactual->listacapas->existeCapa(cadena)){
                    imagenactual->listacapas->ingresarCapa(cadena);
                }
            }
            cadena="";
        }
        else{
            cadena += textoimg[j];
        }
        
    }
    
}

void lecturaUsuarios(){
    string textous;
    string rutauser;
    bool filecorrecto = false;
    ifstream archiusuarios;
    while(filecorrecto!=true){
        cout << "Ingrese la ruta absoluta del archivo de usuarios:" << endl;
        getline(cin,rutauser);
        archiusuarios.open(rutauser,ios::in);
        if(archiusuarios.is_open()){
            char c;
            while(!archiusuarios.eof()){
                c = archiusuarios.get();
                if(c==' ' || c=='\n' || c=='\t' || c=='\r' || c=='\f' || c=='\377'){
                
                } else {
                    textous += c;
                }
            }
            archiusuarios.close();
            filecorrecto = true;
            cout << "Archivo de usuarios cargado exitosamente." << endl;
        } else {
            cout << "No se encontro o pudo abrir el archivo, ingrese la ruta correctamente por favor." << endl;
        }
    }
    
    
    bool esidusuario = true;
    bool esidimagen = false;
    string img="";
    string info = "";
    NodoAvlUsuario* nuevous;
    
    for(int m = 0; m<textous.size();m++){
        if(textous[m]==':' && esidusuario==true){
            esidusuario=false;
            esidimagen = true;
            nuevous = new NodoAvlUsuario(info);
            info="";
        } else if(textous[m]==',' && esidimagen==true){
            nuevous->listaimagenes->ingresarImagen(info);
            info = "";
        } else if(textous[m]==';' && esidimagen==true){
            esidusuario = true;
            esidimagen = false;
            if(textous[m-1]==':'){
                usuarios->insertarAvl(nuevous);
            } else{
                nuevous->listaimagenes->ingresarImagen(info);
                usuarios->insertarAvl(nuevous);
            }
            info="";
        }
        else{
            info += textous[m];
        }
    }
    
}
