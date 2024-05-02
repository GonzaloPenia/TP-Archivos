#ifndef CLSARCHIVO_H_INCLUDED
#define CLSARCHIVO_H_INCLUDED

class Archivo{
private:

    char nombre[30];

public:
    Archivo(const char *n="NOMBRE"){ //CONSTRUCTOR
        strcpy(nombre, n); //COPIA EL CONTENIDO DE N EN NOMBRE
        //estado=true;
    }
    const char *getNombre(){return nombre;}

    //

    bool escribirArchivo(Articulo Articulo);
    Articulo leerArchivo(int pos); //SI SE LE PASA COMO PARAMETRO UN INT, MOSTRARá EL ARTICULO EN LA POSICION QUE SE LE PAS�.
    void leerArchivo();        //MUESTRA TODOS LOS ARTICULOS EN EL ARCHIVO.
    bool modificarArchivo(int pos, Articulo Articulo);
    int buscarEnArchivo(int id);
    bool verificarRepetido(int id);

};

bool Archivo::verificarRepetido(int id){
    Articulo Articulo;
    FILE *p=fopen(nombre,"rb");
    while(fread(&Articulo,sizeof Articulo,1,p)==1){
        if(Articulo.getId()==id){
            cout<<"Se encontro coincidencia, ya tenemos un jugador con ese DNI inscripto en nuestra BdD."<<endl<<endl;
            Articulo.Mostrar();
            return true; //HAY UN REPETIDO
        }
    }
    return false; //NO SE ENCONTRO REPETICION, FALSE HABILITA LA CARGA DE LOS DEMAS DATOS
    fclose(p);
}


int Archivo::buscarEnArchivo(int id)
{
    Articulo Articulo;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"FALLO EN EL ACCESO AL ARCHIVO";
        return -2;
    }
    int contador=0;
    while(fread(&Articulo,sizeof Articulo,1,p)==1){
        if(Articulo.getId()==id){
            cout<<"SE ENCONTRO UN ARTICULO CON ESE ID:"<<endl<<endl;
            Articulo.Mostrar();
            fclose(p);
            return contador;
        }
        contador++;
    }
    fclose(p);
    return -1;
}

bool Archivo::escribirArchivo(Articulo Articulo){
    FILE *p=fopen(nombre,"ab");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    fwrite(&Articulo,sizeof Articulo,1,p);
    fclose(p);
    return true;
}

Articulo Archivo::leerArchivo(int pos){
    Articulo Articulo;
    Articulo.setEstado(false);
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"FALLO EN EL ACCESO AL ARCHIVO";
        return Articulo;
    }
    fseek (p,sizeof(Articulo)*pos,0);
    fread(&Articulo,sizeof Articulo,1,p);
    fclose(p);
    return Articulo;
}

void Archivo::leerArchivo(){
    Articulo Articulo;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }
    while(fread(&Articulo,sizeof Articulo,1,p)==1){
        Articulo.Mostrar();
    }
    fclose(p);
}

bool Archivo::modificarArchivo(int pos, Articulo Articulo){
    FILE *p=fopen(nombre,"rb+");
    if(p==NULL){
        cout<<"FALLO EN EL ACCESO AL ARCHIVO";
        return false;
    }
    fseek (p,sizeof(Articulo)*pos,0);
    bool confirmacion=fwrite(&Articulo,sizeof Articulo,1,p);
    fclose(p);
    return confirmacion; //DEVUELVE CONFIRMACION EN CASO DE SER EXITOSO
}


#endif // CLSARCHIVO_H_INCLUDED