#include <iostream>

using namespace std;

int opciones(){
    system("cls");
    int opcion;

    cout<<"Eliga la funcion que desea: "<<endl;
    cout<<"1- Crear nuevo registro."<<endl;
    cout<<"2- Mostrar registros existentes."<<endl;
    cout<<"3- Borrar un registro existente."<<endl;
    cout<<"4- Salir del sistema."<<endl;
    cout<<"Opcion a elegir: "; cin>>opcion;
    return opcion;
    system("cls");
    system("pause");
}