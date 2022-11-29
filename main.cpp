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
#include <limits>

using namespace std;

//Contador usado en el main
int adminCounter = 0;

//Funciones
void sleep(float);
void menu(WikiData);
void modoAdmin(WikiData);

/*
Solución al problema en el cuál "cin" deja de tomar el input del usuario.
Copiado de: https://latedev.wordpress.com/2011/09/13/simple-input-bullet-proofing-in-c/
La función fue editada para ser de utilidad en el programa.
*/
template <typename T>
T ReadType(const string & prompt, string message) {
    T n;
    while( (cout << prompt) && ! (cin>> n) ) {
        cout << endl << message << endl;
        cin.clear();
        cin.ignore( numeric_limits<int>::max(), '\n' );
    }
    return n;
}

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
    printf("\e[1;1H\e[2J");
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
    cout << "A continuación escoge una de las siguientes opciones escribiendo unicamente el número en la consola:\n";
    cout << "1. Ver la Lista de Bloques." << endl
    << "2. Buscar la información de un bloque en específico a través de su ID Númerico." << endl
    << "3. Ser admin (Te permite añadir bloques normales, bloques líquidos y/o minerales a la lista de bloques)." << endl
    << "4. Salir de la aplicación." << endl;
    
    if(adminCounter >= 1){
        cout << "\n42. Añadir bloques al sistema. (Nota: No puedes eliminar bloques una vez se han subido.)" << endl;
    }

    int opcion;
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
    identifier = ReadType<float>("","Tip:\nEscribe el ID Númerico del bloque del cuál desees ver su información: ");
    cout << endl;
    wikidata.encontrarEnListaDeBloques(identifier);
    sleep(5.6);
    menu(wikidata);
        break;
    case 3:
    if(adminCounter == 0){
        cout << "\nFelicidades..." << endl;
        sleep(2.4);
        cout << "Ahora eres admin. Se te abrió la nueva opción de añadir bloques." << endl <<
        "Pero se cuidadoso." << endl;
        sleep(1.8);
        cout << "Una vez añades un bloque, nunca se puede quitar..." << endl << endl;
        adminCounter += 1;
        sleep(2.8);
    }
    else{
        cout << "Ya eres actualmente admin." << endl;
        sleep(2.3);
        cout << "¿Acaso este nuevo poder no fué suficiente para tí?...";
        sleep(4.2);
    }
    menu(wikidata);
        break;
    case 4:
    sleep(2.4);
    cout << "\n\nEso fue todo, esperamos que te haya gustado nuestra WIKI." << endl << "Vuelve pronto !!!" << endl;
        break;
    case 42:
    modoAdmin(wikidata);
    sleep(2.4);
        break;
    default:
    cout << "\nTip: Coloca el número de alguna de las opciones mostradas." << endl << endl;
    sleep(2.4);
    menu(wikidata);
        break;
    }  
}

//Función que permité añadir bloques
void modoAdmin(WikiData wikidata){
    int opcionModoAdmin;
    float identifier;
    string nameIdentifier;
    string name;
    bool interactive;
    bool breakable;
    string obtainable;
    bool canBeCrafted;
    bool damage;
    bool obeysPhysics;
    bool flammable;
    bool luminous;
    bool transparent;
    string propagation;
    string properties;
    string itemDrop;
    string localitation;
    cout << "\nEscoge que tipo de bloque deseas añadir:\n";
    cout << "1. Bloque General." << endl << "2. Liquido" <<
    endl << "3. Mineral" << endl << endl;
    
    cin >> opcionModoAdmin;
    cout << endl;
   
    switch (opcionModoAdmin)
    {
    case 1:
        cout << "Ingresa el ID del bloque que deseas añadir, "
        << "es importante que sea distinto al resto de IDs y mayor a 0 o el programa no funcionará adecuadamente." << endl;
        cin >> identifier;
        while(identifier <= 0.0){
            cout << "\nEl ID debe ser mayor a 0 y distinto al resto de IDs" << endl;
            identifier = ReadType<float>("","El ID debe ser mayor a 0 y distinto al resto de IDs");
        }
        
        cout << "\nIngresa el ID del nombre del bloque que deseas añadir." << endl;
        getline(cin >> ws,nameIdentifier);
        
        cout << "\nIngresa el nombre del bloque que deseas añadir." << endl;
        getline(cin >> ws,name);
        
        cout << "\nIngresa \"1\" si el bloque puede ser interactuado o \"0\" si no." << endl;
        interactive = ReadType<bool>("","Debes ingresar \"1\" si el bloque puede ser interactuado o \"0\" si no.");
        
        cout << "\nIngresa \"1\" si el bloque puede ser roto o \"0\" si no." << endl;
        breakable = ReadType<bool>("","Debes ingresar \"1\" si el bloque puede ser roto o \"0\" si no.");
        
        cout << "\nIntroduce la manera de conseguir este bloque." << endl;
        getline(cin >> ws,obtainable);

        cout << "\nIngresa \"1\" si el bloque puede ser crafteado o \"0\" si no." << endl;
        canBeCrafted = ReadType<bool>("","Debes ingresar \"1\" si el bloque puede ser crafteado o \"0\" si no.");
        
        cout << "\nIngresa \"1\" si el bloque causa daño al jugador cuando se esta "
        << "en contacto con el o \"0\" si no." << endl;
        damage = ReadType<bool>("","Debes ingresar \"1\" si el bloque causa daño al jugador cuando se esta en contacto o \"0\" si no");
        
        cout << "\nIngresa \"1\" si el bloque obedece la gravedad, es decir, "
        << "es afectado si rompes su soporte, o \"0\" si no." << endl;
        obeysPhysics = ReadType<bool>("","Debes ingresar \"1\" si el bloque obedece la gravedad, es decir, es afectado si rompes su soporte, o \"0\" si no.");
        
        cout << "\nIngresa \"1\" si el bloque se consume y ayuda a propagar el fuego o \"0\" si no." << endl;
        flammable = ReadType<bool>("","Debes ingresar \"1\" si el bloque se consume y ayuda a propagar el fuego o \"0\" si no.");
        
        cout << "\nIngresa \"1\" si el bloque emite algún tipo de luz o \"0\" si no." << endl;
        luminous = ReadType<bool>("","Debes ingresar \"1\" si el bloque emite algún tipo de luz o \"0\" si no.");
        
        cout << "\nIngresa \"1\" si el bloque permite el paso de la luz o \"0\" si no." << endl;
        transparent = ReadType<bool>("","Debes ingresar \"1\" si el bloque permite el paso de la luz o \"0\" si no.");
        
        cout << endl << endl;

        wikidata.añadirBloque(identifier, nameIdentifier, name,\
        interactive, breakable, obtainable, canBeCrafted,\
        damage, obeysPhysics, flammable, luminous, transparent);

        menu(wikidata);
        break;
    case 2:
        cout << "Ingresa el ID del bloque líquido que deseas añadir, "
        << "es importante que sea distinto al resto de IDs y mayor a 0 o el programa no funcionará adecuadamente." << endl;
        cin >> identifier;
        while(identifier <= 0.0){
            cout << "\nEl ID debe ser mayor a 0 y distinto al resto de IDs" << endl;
            identifier = ReadType<float>("","El ID debe ser mayor a 0 y distinto al resto de IDs");
        }
        
        cout << "\nIngresa el ID del nombre del bloque líquido que deseas añadir." << endl;
        getline(cin >> ws,nameIdentifier);
        
        cout << "\nIngresa el nombre del bloque líquido que deseas añadir." << endl;
        getline(cin >> ws,name);

        cout << "\nIngresa \"1\" si el bloque líquido causa daño al jugador cuando se esta "
        << "en contacto con el o \"0\" si no." << endl;
        damage = ReadType<bool>("","Debes ingresar \"1\" si el bloque líquido causa daño al jugador cuando se esta en contacto o \"0\" si no");

        cout << "\nIngresa \"1\" si el bloque líquido emite algún tipo de luz o \"0\" si no." << endl;
        luminous = ReadType<bool>("","Debes ingresar \"1\" si el bloque líquido emite algún tipo de luz o \"0\" si no.");
        
        cout << "\nIngresa \"1\" si el bloque líquido permite el paso de la luz o \"0\" si no." << endl;
        transparent = ReadType<bool>("","Debes ingresar \"1\" si el bloque líquido permite el paso de la luz o \"0\" si no.");
        
        cout << "\nIngresa la distancia de propagación del bloque líquido." << endl;
        getline(cin >> ws,propagation);

        cout << "\nIngresa las propiedades del bloque líquido." << endl;
        getline(cin >> ws,properties);

        cout << endl << endl;

        wikidata.añadirLiquido(identifier, nameIdentifier, name, damage, luminous,\
        transparent, propagation, properties);

        menu(wikidata);
        break;
    case 3:
        cout << "Ingresa el ID del bloque de mineral que deseas añadir, "
        << "es importante que sea distinto al resto de IDs y mayor a 0 o el programa no funcionará adecuadamente." << endl;
        cin >> identifier;
        while(identifier <= 0.0){
            cout << "\nEl ID debe ser mayor a 0 y distinto al resto de IDs" << endl;
            identifier = ReadType<float>("","El ID debe ser mayor a 0 y distinto al resto de IDs");
        }
        
        cout << "\nIngresa el ID del nombre del bloque de mineral que deseas añadir." << endl;
        getline(cin >> ws,nameIdentifier);
        
        cout << "\nIngresa el nombre del mineral que deseas añadir." << endl;
        getline(cin >> ws,name);
        
        cout << "\nIngresa \"1\" si el mineral puede ser interactuado o \"0\" si no." << endl;
        interactive = ReadType<bool>("","Debes ingresar \"1\" si el bloque puede ser interactuado o \"0\" si no.");

        cout << "\nIntroduce la manera de conseguir este mineral." << endl;
        getline(cin >> ws,obtainable);

        cout << "\nIngresa \"1\" si el mineral emite algún tipo de luz o \"0\" si no." << endl;
        luminous = ReadType<bool>("","Debes ingresar \"1\" si el mineral emite algún tipo de luz o \"0\" si no.");

        cout << "\nIngresa el item que es dropeado al romper este mineral." << endl;
        getline(cin >> ws,itemDrop);

        cout << "\nIngresa la localización de generación de este mineral." << endl;
        getline(cin >> ws,localitation);

        cout << endl << endl;

        wikidata.añadirMineral(identifier, nameIdentifier, name,\
        interactive, obtainable, luminous, itemDrop, localitation);

        menu(wikidata);
        break;
    default:
    cout << "\nTip: Coloca el número de alguna de las opciones mostradas." << endl << endl;
    sleep(2.4);
    modoAdmin(wikidata);
        break;
    }
}