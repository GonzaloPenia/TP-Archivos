void cargarArticulo();
void buscarArticulo();
void listaDeArticulos();
void modificarFechaInsc();
void borrarArticulo();

void cargarArticulo(){
    Articulo Articulo;
    Archivo Archivo("articulo.dat");
    int id;
    cout<<"CARGA DE NUEVO ARTICULO.";
    cout<<"INGRESE LOS SIGUIENTES DATOS QUE LE SER�N SOLICITADOS.";
    cout<<"ID: ";
    cin>>id;
    bool repetido= Archivo.verificarRepetido(id); //VERIFICAMOS QUE EL ID EST� DISPONIBLE Y QUE NO HAYA REPETIDOS.
    if (repetido==false)//NO HAY NINGUN ARTICULO CON ESE ID REGISTRADO
        {
            Articulo.Cargar(id);
            if(Archivo.escribirArchivo(Articulo)==true)
                {
                    cout<<"ARTICULO AGREGADO EXITOSAMENTE"<<endl;
                }
            else
                {
                    cout<<"NO SE PUDO AGREGAR EL ARTICULO"<<endl;
                }
        }
        else
            {
                cout<<"HAY UN ARTICULO REPETIDO"<<endl;
            }
}

void buscarArticulo(){
    Archivo Archivo("articulo.dat");
    int id,pos;
    cout<<"BUSCAR UN ARTICULO POR ID."<<endl;
    cout<<"INGRESE EL ID DEL ARTICULO QUE DESEA BUSCAR EN NUESTRA BdD:"<<endl;
    cin>>id;
    pos= Archivo.buscarEnArchivo(id);
    if(pos==-1)
    {
        cout<<"NO HAY NADIE REGISTRADO CON ESE DNI"<<endl;
    }
    else
    {
        if(pos==-2)
        {
            cout<<"FALLO EN EL ACCESO AL ARCHIVO"<<endl;
        }
    }

}

void listaDeArticulos(){
    Archivo Archivo("articulo.dat");
    Archivo.leerArchivo();
    cout<<"-------------------------"<<endl;
}

void modificarFechaInsc(){
    Archivo Archivo("articulo.dat");
    int id,pos;
    cout<<"Ingrese el DNI del jugador cuya fecha quiere modificar:"<<endl;
    cin>>id;
    pos= Archivo.buscarEnArchivo(id);
    if(pos==-1)
    {
        cout<<"NO HAY NADIE REGISTRADO CON ESE DNI"<<endl;
        return;
    }
    else{
        if(pos==-2)
        {
            cout<<"FALLO EN EL ACCESO AL ARCHIVO"<<endl;
            return;
        }
        else
        {
            cout<<"SE ENCONTRO UN REGISTRO"<<endl;
            cout<<"-----------------------"<<endl;

        }
    }
    Articulo Articulo= Archivo.leerArchivo(pos);
    Articulo.Mostrar();
    cout<<"INGRESE LA NUEVA FECHA: "<<endl;
    Fecha fechaInsc;
    fechaInsc.Cargar();
    //Articulo.setFechaInsc(fechaInsc);
    bool flag= Archivo.modificarArchivo(pos, Articulo);
    if(flag==true)
    {
        cout<<"FECHA MODIFICADA DE FORMA CORRECTA";
    }
    else{
        cout<<"NO SE PUDO MODIFICAR LA FECHA";
    }

}

void borrarArticulo(){ //ESTA FUNCION S�LO DAR� DE BAJA EL ESTADO DEL ARTICULO PERO SEGUIR� ESTANDO EN EL HISTORIAL DE LA BdD
    Archivo Archivo("articulo.dat");
    int id,pos;
    cout<<"ELIMINAR UN ARTICULO."<<endl;
    cout<<"---------------------"<<endl;
    cout<<"INGRESE EL ID DEL ARTICULO EL CUAL DESEA ELIMINAR:"<<endl;
    cin>> id;
    pos=Archivo.buscarEnArchivo(id);
    if(pos==-1){
        cout<<"NO HAY NADIE REGISTRADO CON ESE DNI"<<endl;
        return;
    }
    else{
        if(pos==-2){
            cout<<"FALLO EN EL ACCESO AL ARCHIVO"<<endl;
            return;
        }
        else{
            cout<<"SE ENCONTRO UN REGISTRO"<<endl;
        }
    }

    Articulo Articulo = Archivo.leerArchivo(pos);
    Articulo.Mostrar();
    Articulo.setEstado(false);
    bool flag=Archivo.modificarArchivo(pos,Articulo);
    if(flag==true)
    {
        cout<<"REGISTRO BORRADO DE FORMA CORRECTA";
    }
    else{
        cout<<"NO SE PUDO BORRAR EL REGISTRO";
    }

}