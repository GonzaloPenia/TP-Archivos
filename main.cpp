#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>

using namespace std;

#include "function.h"
#include "clsFecha.h"
#include "clsProveedor.h"
#include "clsArticulo.h"
#include "clsArchivo.h"
#include "funcionesArticulo.h"

int main(){
int opcion;
int sub_menu;
while(opcion!=0){
    bool exit = false;
    system ("cls");
    mostrarMenuPrincipal();
    cin>>opcion;
    switch(opcion){

        ////-----MOSTRAR MENU ARTICULOS-----////

        case 1:
            system ("cls");
            mostrarMenuArticulos();
            while(exit==false){
                cin>>sub_menu;
                system ("cls");
                switch(sub_menu){
                    case 1:
                        cout<<"1-AGREGAR ARTICULOS."<<endl;
                        cargarArticulo();
                        system ("pause");
                        break;
                    case 2:
                        cout<<"2-BUSCAR ARTICULO."<<endl;
                        buscarArticulo();
                        system ("pause");
                        break;
                    case 3:
                        cout<<"3-MODIFICAR ARTICULOS."<<endl;
                        //
                        system ("pause");
                        break;
                    case 4:
                        cout<<"4-LISTAR TODOS LOS ARTICULOS."<<endl;
                        listaDeArticulos();
                        system ("pause");
                        break;
                    case 5:
                        cout<<"5-ELIMINAR ARTICULO."<<endl;
                        borrarArticulo();
                        system ("pause");
                        break;

                    case 0:
                        break;
                    default:
                        cout<<"Algo salio mal, intente nuevamente";
                return 0;
                }
                cout<<"Fin switch";
                exit=true;
            }
            break;

            ////-----SE DEJA DE MOSTRAR MENU JUGADORES-----////

////----------------------------------------------------------------------////

////----------------------------------------------------------------------////

////----------------------------------------------------------------------////

        ////-----SALIR-----////
        case 0:
            break;
        default:
            cout<<"Algo salio mal, intente nuevamente";
            return 0;
        }
    }

cout<<"El programa ha finalizado.";
return 0;


  return 0;
}