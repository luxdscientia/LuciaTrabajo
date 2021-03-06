#ifndef Refineria_h
#define Refineria_h

#include <iostream>
using namespace std;
#include "Gasolina.h"
#include "Persona.h"
#include "Tanque.h"

class Refineria : public Tanque
{
private:
    string nombre;
    Persona encargado;

public:
    Refineria(string, float, float ,string, string, string);
    ~Refineria();

    void producirGasolina(float);
    string obtenerDatos();
    void guardarDatos();
    void menu();
};
/*
Suponemos que cuando creamos la refineria tiene capacidad infinita pues porque queremos
*/
Refineria::Refineria(string _nombreRefineria, float _litros, float capacidad = 10000000000, string _nombreEncargado = "", string _cedulaEncargado = "", string _telefonoEncargado = "") : Tanque(_litros, capacidad)
{
    nombre = _nombreRefineria;
    encargado.establecerDatos(_nombreEncargado, _cedulaEncargado, _telefonoEncargado);
}

Refineria::~Refineria()
{
}

void Refineria::producirGasolina(float _litros)
{
    aumentarLitros(_litros);
    aumentarLitrosTotales(_litros);
}

string Refineria::obtenerDatos()
{
    string datosEncargado = encargado.obtenerDatos();
    string Manejados = to_string(litrosManejados()) ;
    string litrosDisponibles = to_string(cantidadLitrosDisponible());
    string capacidadTanque = to_string(obtenerCapacidad());

    return "\nNombre: " + nombre + "\nCapacidad del tanque: " + capacidadTanque + "\nLitros manejados: " + Manejados + "\nLitros restantes: " + litrosDisponibles + "\nDatos del encargado" + datosEncargado;
}

void Refineria::guardarDatos()
{
    ofstream archivo;
    //TODO cambie de crear el archivo a solo añadir informacion
    archivo.open("Refineria.txt", ios::app); //Abrimos el archivoCisternas
    //
    if (archivo.fail())
    {
        cout << "No se pudo abrir el archivo" << endl;
        exit(1);
    }
    
    archivo << obtenerDatos();

    archivo.close();
}

void Refineria::menu()
{
    bool salir = false;

    do
    {
        int opcion;
        cout << "Estacion: " << nombre << endl;
        cout << "Capacidad: " << obtenerCapacidad() << " litros" << endl;
        cout << "Actualmente posee: " << cantidadLitrosDisponible() << "litros" 
            << endl;
        cout << "1. Producir Gasolina" << endl;
        cout << "2. Cargar cisterna" << endl;
        cout << "3. Salir Refineria" << endl;
        cout << "Ingrese opcion: ";
        cin >> opcion;
        
        system("clear");

        switch (opcion)
        {
        case 1:
            
            system("clear");

            break;
        case 3:

            salir = true;
            
            break;

        default:

            cout << "Opcion no disponible ingrese otra" << endl;

            break;
        }

    } while (!salir);
    
}

#endif