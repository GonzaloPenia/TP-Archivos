#ifndef CLSPROVEEDOR_H_INCLUDED
#define CLSPROVEEDOR_H_INCLUDED

class Proveedor{
    private:  
        char nombre_proveedor[30];
        char email_proveedor[30];
        int telefono;
        int id_proveedor;
    
    public:

    Proveedor(){

    }

    //////INICIO DE SETS Y GETS

    const char* getNombreProveedor(){return nombre_proveedor;}
    const char* getEmailProveedor(){return email_proveedor;}
    int getTelefono(){return telefono;}
    int getIdProveedor(){return id_proveedor;}

    //

    void setEmailProveedor(const char *ep){strcpy(email_proveedor,ep);}
    void setNombreProveedor(const char *np){strcpy(nombre_proveedor,np);}
    void setTelefono(const int t){telefono=t;}
    void setIdProveedor(const int p){id_proveedor=p;}
    
    //////FINAL DE SETS Y GETS
    void Mostrar();
    void Cargar();
    void Modificar();
}; 


void Proveedor::Modificar() //NO TIENE EN CUENTA LA VALIDACION, TOMA CUALQUIER FECHA
    {
    cout<<"INGRESO DE DATOS DE PROVEEDOR"<<endl;
    cout<<"-----------------------------"<<endl;
    cout<<"NOMBRE PROVEEDOR: ";
    cin>>nombre_proveedor;
    cout<<"EMAIL: ";
    cin>>email_proveedor;
    cout<<"TELEFONO: ";
    cin>>telefono;
    }

void Proveedor::Cargar()
    {
    cout<<"INGRESO DE DATOS DE PROVEEDOR"<<endl;
    cout<<"-----------------------------"<<endl;
    cout<<"NOMBRE PROVEEDOR: ";
    cin>>nombre_proveedor;
    cout<<"EMAIL: ";
    cin>>email_proveedor;
    cout<<"TELEFONO: ";
    cin>>telefono;
    }
void Proveedor::Mostrar()
    {
    cout<<"NOMBRE PROVEEDOR: "<<nombre_proveedor<<endl;
    cout<<"EMAIL PROVEEDOR: "<<email_proveedor<<endl;
    cout<<"TELEFONO: "<<telefono<<endl<<endl;
    }

#endif // CLSPROVEEDOR_H_INCLUDED