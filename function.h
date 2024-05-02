void mostrarMenuPrincipal();
void mostrarMenuArticulos();
void cargarCadena();

void mostrarMenuPrincipal(){
    cout<<"MENU PRINCIPAL"<<endl;
    cout<<"--------------"<<endl;
    cout<<"1-MENU ARTICULOS."<<endl;
    cout<<"--------------"<<endl;
    cout<<"0- FIN DEL PROGRAMA..."<<endl;
    cout<<"Digite el nro de la opcion que quiera ejecutar y toque ENTER."<<endl;
}

void mostrarMenuArticulos(){
    cout<<"MENU JUGADORES"<<endl;
    cout<<"--------------"<<endl;
    cout<<"1-AGREGAR ARTICULOS."<<endl;
    cout<<"2-BUSCAR ARTICULOS."<<endl;
    cout<<"3-MODIFICAR( no disponible )."<<endl;
    cout<<"4-LISTAR ARTICULOS."<<endl;
    cout<<"5-ELIMINAR ARTICULO."<<endl;
    cout<<"--------------"<<endl;
    cout<<"0- VOLVER AL MENU PRINCIPAL"<<endl;
    cout<<"Digite el nro de la opcion que quiera ejecutar y toque ENTER."<<endl;
}

void cargarCadena(char *palabra, int tam){
    int i = 0;
    fflush(stdin);
    for (i = 0 ; i < tam ; i++ ){
        palabra[i] = cin.get();
        if(palabra[i] == '\n') break;
    }
    palabra[i] = '\0';
    fflush(stdin);
}
