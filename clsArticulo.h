#ifndef CLSARTICULO_H_INCLUDED
#define CLSARTICULO_H_INCLUDED

class Articulo{
private:
    int id;
    char nombre[30];
    char descripcion[50];
    int unidades;
    int alerta_unidades; //CANTIDAD DE UNIDADES QUE SE CONSIDERA COMO BAJA CANTIDAD DE STOCK. DARÁ AVISO CUANDO SE LISTE
    bool estado;
    Fecha fecha_ingreso; // FECHA DEL ULTIMO INGRESO
    Fecha fecha_repo; // FECHA EN LA QUE SE ESTIPULA QUE SERÁ EL PROXIMO INGRESO
    Proveedor proveedor;

public:
    Articulo(const char *n="NOMBRE"){ //CONSTRUCTOR
        strcpy(nombre, n); //COPIA EL CONTENIDO DE N EN NOMBRE
    }

    Articulo(Fecha aux){
        fecha_ingreso=aux;
        fecha_repo=aux;
        estado=true;
    }

    Articulo(int d, int m, int a){ //CONSTRUCTOR
        fecha_ingreso.setDia(d);
        fecha_ingreso.setMes(m);
        fecha_ingreso.setAnio(a);
        fecha_repo.setDia(d);
        fecha_repo.setMes(m);
        fecha_repo.setAnio(a);
        estado=true;
    }

    //////INICIO DE SETS Y GETS

    int getId(){return id;}
    const char* getNombre(){return nombre;}
    const char* getApellido(){return descripcion;}
    int getUnidades(){return unidades;}
    int getAlertaUnidades(){return alerta_unidades;}
    Fecha getFechaInscripcion(){return fecha_ingreso;}
    Fecha getFechaReposicion(){return fecha_repo;}
    bool getEstado(){return estado;}

    //

    void setId(const int i){id=i;}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setDescripcion(const char *d){strcpy(descripcion, d);}
    void setUnidades(const int u){unidades=u;}
    void setAlertaUnidades(const int au){alerta_unidades=au;}
    void setFechaIngreso(Fecha fi){fecha_ingreso=fi;}
    void setFechaReposicion(Fecha fr){fecha_repo=fr;}
    void setEstado(bool est){estado=est;}

    //////FINAL DE SETS Y GETS

    //////PROTOTIPOS
    bool Cargar(int id); // RECIBE UN ID, DEVUELVE TRUE EN CASO DE QUE LA CARGA SE HAYA HECHO
    void Mostrar();
};

//METODO CARGAR.
bool Articulo::Cargar(int identificador)
{
    id=identificador;
    cout<<"NOMBRE: ";
    cargarCadena(nombre, 29);
    cout<<"DESCRIPCION: ";
    cargarCadena(descripcion,29);
    cout<<"CANTIDAD DE UNIDADES: ";
    cin>>unidades;
    cout<<"¿CUANTO CONSIDERA POCO STOCK DE ESTE ARTICULO?";
    cin>>alerta_unidades;
    cout<<"FECHA ULTIMO INGRESO: ";
    fecha_ingreso.Cargar();
    cout<<"FECHA ESTIMADA DEL PROXIMO INGRESO: ";
    fecha_repo.Cargar();
    cout<<"INGRESE NOMBRE DEL PROVEEDOR: ";
    proveedor.Cargar();
    estado=true;
    return true; //TRUE CONFIRMA QUE SE CARGO EL USUARIO
}

//METODO MOSTRAR.
void Articulo::Mostrar()
{
    if(estado==true)
    {
        cout<<endl;
        cout<<"-------------------------"<<endl;
        cout<<"ID: ";
        cout<<id<<endl<<endl;
        cout<<"NOMBRE: ";
        cout<<nombre<<endl<<endl;
        cout<<"DESCRIPCION: ";
        cout<<descripcion<<endl<<endl;
        cout<<"CANTIDAD DE UNIDADES: ";
        cout<<unidades<<endl<<endl;
        cout<<"ALERTA POCO STOCK:";
        cout<<alerta_unidades<<endl<<endl;
        cout<<"FECHA ULTIMO INGRESO: ";
        fecha_ingreso.Mostrar();
        cout<<"FECHA ESTIMADA DEL PROXIMO INGRESO: ";
        fecha_repo.Mostrar();
        proveedor.Mostrar();
        cout<<endl;
    }
}


#endif // CLSFECHA_H_INCLUDED