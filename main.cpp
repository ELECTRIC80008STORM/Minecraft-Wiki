/*
* Proyecto Minecraft Wiki
* Rommel T. C.
* A01709922
*/

/*
* Descripción: Proyecto con el objetivo de facilitar el inicio del videojuego Minecraft brindando información básica
* acerca de bloques comúnes con los que se pueden encontrar jugadores no experimentados.
*/

//Biblioteca
#include "WikiData.h"
#include <iostream>
#include <iomanip>

using namespace std;

//Declaración de las funciones
void sleep(float);
void menu(WikiData);

//Código Principal
int main(){
    WikiData wikidata;
    int opcion;
    //Inicialización de Los Bloques Precargados
    wikidata.añadirBloque(1,"stone","Piedra","Puede ser obtenido mediante cualquier tipo de pico.",false,false);
    wikidata.añadirBloque(1.3,"stone","Diorita","Puede ser obtenido mediante cualquier tipo de pico.",false,false);
    wikidata.añadirBloque(13,"gravel","Grava",false,true,\
    "Puede ser obtenido de cualquier manera pero la más eficiente es una pala.",false,false,true,false,false,false);
    
    wikidata.añadirLiquido(8,"flowing_water","Agua En Flujo",true,\
    false,true,"Tiene una propagación de 7 bloques.",\
    "Sí el jugador permanece mucho tiempo debajo se consumirá su barra de oxígeno.");
    
    wikidata.añadirMineral(14,"gold_ore","Oro","Puede ser obtenido mediante cualquier tipo de pico.",\
    "Bloque de Oro","Entre la capa 10");
    wikidata.añadirMineral(15,"iron_ore","Hierro","Puede ser obtenido mediante cualquier tipo de pico.",\
    "Bloque de Hierro","Entre la capa 10");

    //Funcionamiento del Main
    cout << "Bienvenido a la Wiki de Bloques de Minecraft!!!" << endl << endl;
    sleep(1.4);
    cout << "Una wiki hecha para usarse como guía para jugadores nuevos, ya que les permitirá saber" << endl
    << "rápidamente las características básicas de algunos de los bloques comúnes que existen." << endl << endl;
    sleep(2.8);
    cout << "La lista de los bloques cargados actualmente en la Wiki es la siguiente:" << endl << endl;
    wikidata.mostrarListaDeBloques();
    sleep(6.4);
    menu(wikidata);
    return 0;
}

/* Definición de las funciones */

//Función que crea un delay
void sleep(float timeOfDelay){
    timeOfDelay *= 10000;
    for(int i; i <= timeOfDelay; i++){}
};

//Función que provee la funcionalidad del menú
void menu(WikiData wikidata){
    int opcion;
    cout << "A continuación escoge una de las siguientes opciones escribiendo unicamente el número en la consola:\n";
    cout << "1. Ver la Lista de Bloques." << endl
    << "2. Buscar la información de un bloque en específico a través de su ID Númerico." << endl
    << "3. Por Implementar." << endl
    << "4. Salir de la aplicación." << endl;

    cout << endl;
    cin >> opcion;

    switch (opcion)
    {
    case 1:
    wikidata.mostrarListaDeBloques();
    sleep(6.4);
    menu(wikidata);
        break;
    case 2:
    float identifier;
    cout << "\nEscribe el ID Númerico del bloque del cuál desees ver su información: ";
    cin >> identifier;
    cout << endl << endl;
    wikidata.encontrarEnListaDeBloques(identifier);
    sleep(5.6);
    menu(wikidata);
        break;
    case 3:
    cout << "Por Implementar." << endl << endl;
    sleep(2.4);
    menu(wikidata);
        break;
    case 4:
    sleep(2.4);
    cout << "\n\nEso fue todo, esperamos que te haya gustado nuestra WIKI." << "Vuelve pronto !!!" << endl;
        break;
    default:
    cout << "\nTip: Coloca el número de alguna de las opciones mostradas." << endl << endl;
    sleep(2.4);
    menu(wikidata);
        break;
    }  
}