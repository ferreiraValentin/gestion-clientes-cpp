#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 100;

struct Cliente{
    int id;
    char nombre[30];
    char apellido[30];
    int dni;
    int edad;
    bool activo;
};

void inicializar(Cliente vec[], int tam);
void mostrarMenu();
void altaCliente(Cliente vec[], int &cantidad);
void listarClientes(const Cliente vec[], int cantidad);
void bajaCliente(Cliente vec[], int cantidad);
void modificarCliente(Cliente vec[], int cantidad);
void buscarClientePorDNI(const Cliente vec[], int cantidad);
void ordenarClientesPorID(Cliente vec[], int cantidad);
void estadisticas(const Cliente vec[], int cantidad);
void guardarEnArchivo(const Cliente vec[], int cantidad);
void cargarDesdeArchivo(Cliente vec[], int &cantidad);

int main(){
    Cliente clientes[MAX];
    int cantidad = 0;

    inicializar(clientes, MAX);

    int opcion;
    
    do{
        mostrarMenu();
        cin >> opcion;

        switch(opcion){
            case 1:
            altaCliente(clientes, cantidad);
            break;
            case 2:
            bajaCliente(clientes, cantidad);
            break;
            case 3:
            modificarCliente(clientes, cantidad);
            break;
            case 4:
            listarClientes(clientes, cantidad);
            break;
            case 5:
            buscarClientePorDNI(clientes, cantidad);
            break;
            case 6:
            ordenarClientesPorID(clientes, cantidad);
            break;
            case 7:
            estadisticas(clientes, cantidad);
            break;
            case 8:
            guardarEnArchivo(clientes, cantidad);
            break;
            case 9:
            cargarDesdeArchivo(clientes, cantidad);
            break;
            case 0:
            cout << "Saliendo del sistema..." << endl;
            break;
            default:
            cout << "Opcion no valida." << endl;
        }
    } while(opcion != 0);
    return 0; 
}

void inicializar(Cliente vec[], int tam){
    for(int i = 0; i < tam; i++){
        vec[i].activo = false;
    }
}

void mostrarMenu(){
    cout << "\n===== SISTEMA DE GESTION DE CLIENTES =====\n";
    cout << "1) Alta de cliente\n";
    cout << "2) Baja de cliente\n";
    cout << "3) Modificar cliente\n";
    cout << "4) Listar clientes\n";
    cout << "5) Buscar cliente por DNI\n";
    cout << "6) Ordenar clientes\n";
    cout << "7) Estadisticas\n";
    cout << "8) Guardar en archivo\n";
    cout << "9) Cargar desde archivo\n";
    cout << "0) Salir\n";
    cout << "Seleccione una opcion: ";
}

void bajaCliente(Cliente vec[], int cantidad){
    int id;
    cout << "Ingrese el ID del cliente a dar de baja: ";
    cin >> id;

    bool encontrado = false;
    for(int i = 0; i < cantidad; i++){
        if(vec[i].id == id && vec[i].activo){
            vec[i].activo = false;
            cout << "Cliente dado de baja correctamente.\n";
            encontrado = true;
            break;
        }
    }
if(!encontrado){
    cout << "No se encontro un cliente activo con ese ID.\n";
}
}

void altaCliente(Cliente vec[], int &cantidad){
    if(cantidad >= MAX){
        cout << "No hay espacio para mas clientes.\n";
        return;
    }
Cliente c;
c.id = cantidad + 1;

cout << "Nombre: ";
cin >> c.nombre;

cout << "Apellido: ";
cin >> c.apellido;

cout << "DNI: ";
cin >> c.dni;

cout << "Edad: ";
cin >> c.edad;

c.activo = true;

vec[cantidad] = c;
cantidad++;

cout << "Cliente cargado correctamente.\n";
}

void modificarCliente(Cliente vec[], int cantidad){
    int id;
    cout << "Ingrese el ID del cliente a modificar: ";
    cin >> id;

    bool encontrado = false;

    for(int i = 0; i < cantidad; i++){
        if(vec[i].id == id && vec[i].activo){

            cout << "\nCliente encontrado: \n";
            cout << "Nombre actual: " << vec[i].nombre << endl;
            cout << "Apellido actual: " << vec[i].apellido << endl;
            cout << "DNI actual: " << vec[i].dni << endl;
            cout << "Edad actual: " << vec[i].edad << endl;

            cout << "\nIngrese nuevo nombre: ";
            cin >> vec[i].nombre;

            cout << "Ingrese nuevo apellido: ";
            cin >> vec[i].apellido;

            cout << "Ingrese nuevo DNI: ";
            cin >> vec[i].dni;

            cout << "Ingrese nueva edad: ";
            cin >> vec[i].edad;

            cout << "Cliente modificado correctamente.\n";

            encontrado = true;
            break;
        }
    }
if(!encontrado){
    cout << "No se encontro un cliente activo con ese ID.\n";
}
}

void buscarClientePorDNI(const Cliente vec[], int cantidad){
    int dni;
    cout << "Ingrese el DNI a buscar: ";
    cin >> dni;

    bool encontrado = false;

    for(int i = 0; i < cantidad; i++){
        if(vec[i].dni == dni && vec[i].activo){
            cout << "\nCliente encontrado: \n";
            cout << "ID: " << vec[i].id << endl;
            cout << "Nombre: " << vec[i].nombre << endl;
            cout << "Apellido: " << vec[i].apellido << endl;
            cout << "DNI: " << vec[i].dni << endl;
            cout << "Edad: " << vec[i].edad << endl;
            encontrado = true;
            break;
        }
    }
if(!encontrado){
    cout << "No se encontro un cliente activo con ese DNI.\n";
}
}

void ordenarClientesPorID(Cliente vec[], int cantidad){
    for(int i = 0; i < cantidad - 1; i++){
        for(int j = 0; j < cantidad - i - 1; j++){
            if(vec[j].id > vec[j+1].id){
                Cliente aux = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = aux;
            }
        }
    }
cout << "Clientes ordenados por ID correctamente.\n";
}

void estadisticas(const Cliente vec[], int cantidad){
    int total = cantidad;
    int activos = 0;
    int sumaEdades = 0;

    for(int i = 0; i < cantidad; i++){
        if(vec[i].activo){
            activos++;
            sumaEdades += vec[i].edad;
        }
    }

    cout << "\n===== ESTADISTICAS =====\n";
    cout << "Total de clientes cargados: " << total << endl;
    cout << "Clientes activos: " << activos << endl;

    if(activos > 0){
        float promedio = (float)sumaEdades / activos;
        cout << "Promedio de edad (activos): " << promedio << endl;
    }else{
        cout << "No hay clientes activos para calcular el promedio de edad.\n";
    }
cout << "======================\n";    
}

void guardarEnArchivo(const Cliente vec[], int cantidad){
    FILE *p = fopen("clientes.dat", "wb");
    if(p == NULL){
        cout << "No se pudo abrir el archivo para guardar.\n";
        return;
    }
for(int i = 0; i < cantidad; i++){
    if(vec[i].activo){
        fwrite(&vec[i], sizeof(Cliente), 1, p);
    }
}
fclose(p);
cout << "Datos guardados correctamente en clientes.dat\n";
}

void cargarDesdeArchivo(Cliente vec[], int &cantidad){
    FILE *p = fopen("clientes.dat", "rb");
    if(p == NULL){
        cout << "No existe archivo para cargar.\n";
        return;
    }

    Cliente aux;
    cantidad = 0;

    while(fread(&aux, sizeof(Cliente), 1, p) == 1){
        vec[cantidad] = aux;
        cantidad++;
    }
fclose(p);
cout << "Datos cargados correctamente desde clientes.dat\n";
}

void listarClientes(const Cliente vec[], int cantidad){
    cout << "\n--- LISTA DE CLIENTES ---\n";
    for(int i = 0; i < cantidad; i++){
        if(vec[i].activo){
            cout << "ID: " << vec[i].id << "  |  "
                 << vec[i].nombre << " "
                 << vec[i].apellido << "  | DNI: "
                 << vec[i].dni << "  | Edad: "
                 << vec[i].edad << endl;
        }
    }
cout << "-----------------------------------------------\n";
}



