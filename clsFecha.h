#ifndef CLSFECHA_H_INCLUDED
#define CLSFECHA_H_INCLUDED

class Fecha{
    private:
        int dia, mes, anio;
    public:
        Fecha(int d=0, int m=0, int a=0){
            dia=d;
            mes=m;
            anio=a;
        }
        void Cargar();
        void Mostrar();
        void Modificar();
        bool VerificarFecha(int dia_aux,int mes_aux, int anio_aux);
        ///sets
        void setDia(int x){if(x>0 && x<32) dia=x;}
        void setMes(int x){if(x>0 && x<13)mes=x;}
        void setAnio(int x){anio=x;}
        ///gets
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}

};

void Fecha::Cargar(){
    cout<<"DIA: ";
    cin>>dia;
    cout<<"MES: ";
    cin>>mes;
    cout<<"ANIO: ";
    cin>>anio;
    //SE COMPRUEBA QUE SE ESTA PONIENDO UNA FECHA VALIDA
    time_t now = time(0);
    tm *ltm = localtime(&now);
    bool check_fecha=false;
    if(anio <=(1900 + ltm->tm_year)){
        if(anio==(1900 + ltm->tm_year)){
            if(mes<=(1 + ltm->tm_mon)){
                if(mes==(1 + ltm->tm_mon)){
                    if(dia<=(ltm->tm_mday)){
                    check_fecha=true;
                    }
                }else{check_fecha=true;}
            }
        }else{check_fecha=true;}

    }

    while(check_fecha!=true){
        cout<<"La fecha que desea ingresar esta en un formato incompatible o todavia no paso"<<endl<<"Ingrese una fecha valida."<<endl;
        cout<<"DIA: ";
        cin>>dia;
        cout<<"MES: ";
        cin>>mes;
        cout<<"ANIO: ";
        cin>>anio;
       if(anio <=(1900 + ltm->tm_year)){
        if(anio==(1900 + ltm->tm_year)){
            if(mes<=(1 + ltm->tm_mon)){
                if(mes==(1 + ltm->tm_mon)){
                    if(dia<=(ltm->tm_mday)){
                    check_fecha=true;
                    }
                }else{check_fecha=true;}
            }
        }else{check_fecha=true;}

    }

    }
   /* cout<<"DIA: "<<ltm->tm_mday<<endl;
    cout<<"MES: "<<1 + ltm->tm_mon<<endl;
    cout<<"ANIO: "<<1900 + ltm->tm_year<<endl;
*/
}

void Fecha::Modificar(){ //NO TIENE EN CUENTA LA VALIDACION, TOMA CUALQUIER FECHA
    cout<<"DIA: ";
    cin>>dia;
    cout<<"MES: ";
    cin>>mes;
    cout<<"ANIO: ";
    cin>>anio;
}

void Fecha::Mostrar(){
    /*cout<<"DIA: "<<dia<<endl;
    cout<<"MES: "<<mes<<endl;
    cout<<"ANIO: "<<anio<<endl<<endl;*/
    cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
}


#endif // CLSFECHA_H_INCLUDED
