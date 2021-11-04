#include <iostream>

using namespace std;

struct Nodo{
    int id;
    string nombre_encargado;
    string raza_mascota;
    float peso_mascota;
    int edad_mascota;
    Nodo * sig;
}registro;


class List_Circular
{
private:
    Nodo* inicio;
    Nodo* fin;
public:
    List_Circular();
    void Insertar_Inicio(int, string, string, float, int);
    void Insertar_Nodo();
    void Mostrar_Registro();
    void Mostrar_ID();
    int Total_nodos();
    void Borrar();
};

List_Circular::List_Circular(){
    inicio = NULL;
    fin = NULL;
}

void List_Circular::Insertar_Nodo(){
    system("cls");

    cout<<"ID del cliente: "; cin>>registro.id; 
    cin.ignore();

    cout<<"Nombre del encargado: "; getline(cin, registro.nombre_encargado);
     
    cout<<"Raza de la mascotas: "; getline(cin, registro.raza_mascota);

    cout<<"Peso de la mascota: "; cout<<"kg: "; cin>>registro.peso_mascota;
    cin.ignore();

    cout<<"Edad de la mascota: "; cin>>registro.edad_mascota;
    cin.ignore();

    cout<<"Guardado Correctamente"<<endl;
    system("pause");
    system("cls");

    Insertar_Inicio(registro.id, registro.nombre_encargado, registro.raza_mascota, registro.peso_mascota, registro.edad_mascota);
}

void List_Circular::Insertar_Inicio(int id, string nombre_encargado, string raza_mascota, float peso_mascota, int edad_mascota){
    Nodo * nuevo = new Nodo();
    nuevo->id = id;
    nuevo->nombre_encargado = nombre_encargado;
    nuevo->raza_mascota = raza_mascota;
    nuevo->peso_mascota = peso_mascota;
    nuevo->edad_mascota = edad_mascota;
    if (inicio == NULL){
        inicio = nuevo;
        fin = nuevo;
    }else{
        fin->sig = nuevo;
        nuevo->sig = inicio;
        fin = nuevo;
    }
    
};

int List_Circular::Total_nodos(){
    if (inicio == NULL){
        return 0;
    }else{
        Nodo * saltarin = inicio;
        int i = 0;

        do{
            saltarin = saltarin->sig;
            i++;
            cout<<i<<endl;
        } while (saltarin != inicio);
        return i;  
    }
}

void List_Circular::Mostrar_Registro(){
    if (inicio == NULL){
        cout<<"lista vacia"<<endl;
        system("pause");
    }else{

        Nodo * saltarin = inicio;
        int i = 1;

        do{
            cout<<"Registro: "<<i<<endl;
            cout<<"ID: "<<saltarin->id<<endl;
            cout<<"Nombre de encargado: "<<saltarin->nombre_encargado<<endl;
            cout<<"Raza de mascota: "<<saltarin->raza_mascota<<endl;
            cout<<"Peso de mascota: "<<saltarin->peso_mascota<<" kg"<<endl;
            cout<<"Edad de mascota: "<<saltarin->edad_mascota<<endl;
            cout<<endl;
            i++;
            saltarin = saltarin->sig;
            
        } while (saltarin != inicio);
        
    }
    
}

void List_Circular::Mostrar_ID(){
    if (inicio == NULL){
        cout<<"lista vacia"<<endl;
    }else{
        Nodo * saltarin = inicio;
        int i = 1;
        
        do{
            cout<<"Registro "<<i<<" Nombre Encargado: "<<saltarin->nombre_encargado<<endl;
            i++;
            saltarin = saltarin->sig;
        } while (saltarin != inicio);
        
    }
    
}


void List_Circular::Borrar(){
    Nodo * saltarin;
    Nodo * anterior = inicio;
    int pos;

    cout<<"Ingrese el numero del registro que desea eliminar: "<<endl;
    cin>>pos;

    if (inicio == NULL){
        cout<<"Lista Vacia"<<endl;
    }
    else if (pos == 0){
        cout<< "No existe la posicion 0" <<endl;
    }
    else if (pos> Total_nodos())
    {
        cout<< "La Posicion "<<pos<< " excede el Tamano"<<endl;
    }
    else if (pos == 1){
        Nodo* Borrar = inicio;
        inicio = inicio ->sig;
        fin->sig = inicio;
        delete Borrar;
    }
    else if (pos == Total_nodos()){
        Nodo * borrarUltimo;
        saltarin = inicio;
        int i = 0;
        do
        {
            i++;
            if (i == pos - 1){
                anterior = saltarin;
                anterior->sig = inicio;
            }else if (i == pos){
                borrarUltimo = saltarin;
                delete borrarUltimo;
            }
            
            
            saltarin = saltarin->sig;
        } while (saltarin != inicio);
               
    }else {
        saltarin = inicio->sig;
        Nodo * borrarMedio;

        int i = 1;

        do
        {
            i++;
            if (i == pos){
                borrarMedio = saltarin;
                anterior->sig = saltarin->sig;
                delete borrarMedio;
                break;
            }else {
                anterior = anterior->sig;
                saltarin = saltarin->sig; 
            }
        } while (saltarin != inicio);
        
    }
    
    
}