#include <iostream>
#include "List_Circular.h"
#include "funciones.hpp"

using namespace std;

int main(){
    system("cls");
    bool continuar = true;
    List_Circular veterinaria;

    cout<<"Bienvenido a veterinatia Patitas Al Rescate."<<endl;
    cout<<"El programa esta pensado sean mas de 1 registro."<<endl;
    system("pause");
    system("cls");

    do
    {
        switch (opciones())
        {
        case 1:
            veterinaria.Insertar_Nodo();
            break;
        
        case 2:
            system("cls");
            veterinaria.Mostrar_Registro();
            system("pause");
            break;

        case 3:
            system("cls");
            veterinaria.Mostrar_ID();
            veterinaria.Borrar();
            cout<<"Registro borrado exitosamente"<<endl;
            system("pause");
            system("cls");
            
            break;
        
        case 4:
            continuar = false;
            break;
        
        default:
            break;
        }
    } while (continuar);
    
};