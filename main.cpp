/*
* Proyecto Minecraft Wiki
* Rommel T. C.
* A01709922
*/

/*
* Descripción: Proyecto con el objetivo de facilitar el inicio del videojuego Minecraft brindando información básica
* acerca de bloques comúnes con los que se pueden encontrar jugadores no experimentados.
*/

//Bibliotecas
#include "WikiData.h"
#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int adminCounter = 0; //Contador usado en la función menu

//Declaración de las funciones
void sleep(float);
void menu(WikiData);
void modoAdmin(WikiData);

/*
Solución al problema en el cuál "cin" deja de tomar el input del usuario.
Copiado de: https://latedev.wordpress.com/2011/09/13/simple-input-bullet-proofing-in-c/
La función fue editada para ser de utilidad en el programa.
*/

//Template allows us to reutilize code that does the same but takes a different type of instance sometimes.
template <typename T>

//const string & prompt allows you to show a message eacht time the loop iterates (it doesn't recieve the input that it expects).
T ReadType(const string & prompt, string message) {
    T n;
    while( (cout << prompt) && ! (cin>> n) ) {
        cout << endl << message << endl;

        cin.clear(); //Helps in clearing the fail flag that the stream got after an incorrect form of input.
        
        //It ignores the bad form of input that stayed in the buffer, thanks to the code numeric_limits<int>::max(), '\n' 
        //which gives the biggest possible value of an int, so that ignore can ignore more that one character at a time
        cin.ignore( numeric_limits<int>::max(), '\n' );
    }
    return n;
}

int main(){
    WikiData wikidata;
    int opcion;

    //Inicialización de los Bloques usados en WikiData.
    wikidata.añadirBloque(1,"stone","Piedra","Puede ser obtenido mediante cualquier tipo de pico.",false,false);
    wikidata.añadirBloque(1.3,"stone","Diorita","Puede ser obtenido mediante cualquier tipo de pico.",false,false);
    wikidata.añadirBloque(2,"grass","Pasto","Puede ser obtenido mediante una herramienta con toque de seda.",false,false);
    wikidata.añadirBloque(3,"dirt","Tierra",\
    "Puede ser obtenido al romperse con cualquier cosa, pero la herramienta más eficiente para conseguirla es la pala.",false,false);
    wikidata.añadirBloque(4,"cobblestone","Roca","Puede ser obtenido mediante cualquier tipo de pico.",false,false);
    
    //Bloques de Tablones de Madera
    wikidata.añadirBloque(5,"planks","Tablones de Madera de Roble",false,true,\
    "Puede ser obtenido al romperse con cualquier cosa, pero la herramienta más eficiente es el hacha.",\
    true,false,false,true,false,false);
    wikidata.añadirBloque(5.1,"planks","Tablones de Madera de Abeto",false,true,\
    "Puede ser obtenido al romperse con cualquier cosa, pero la herramienta más eficiente es el hacha.",\
    true,false,false,true,false,false);
    wikidata.añadirBloque(5.2,"planks","Tablones de Madera de Abedul",false,true,\
    "Puede ser obtenido al romperse con cualquier cosa, pero la herramienta más eficiente es el hacha.",\
    true,false,false,true,false,false);
    wikidata.añadirBloque(5.3,"planks","Tablones de Madera de Jungla",false,true,\
    "Puede ser obtenido al romperse con cualquier cosa, pero la herramienta más eficiente es el hacha.",\
    true,false,false,true,false,false);
    wikidata.añadirBloque(5.4,"planks","Tablones de Madera de Acacia",false,true,\
    "Puede ser obtenido al romperse con cualquier cosa, pero la herramienta más eficiente es el hacha.",\
    true,false,false,true,false,false);
    wikidata.añadirBloque(5.5,"planks","Tablones de Madera de Roble Oscuro",false,true,\
    "Puede ser obtenido al romperse con cualquier cosa, pero la herramienta más eficiente es el hacha.",\
    true,false,false,true,false,false);

    //Bloques de Madera
    wikidata.añadirBloque(17,"log","Madera de Roble",false,true,\
    "Puede ser obtenido al romperse con cualquier cosa, pero la herramienta más eficiente es el hacha.",\
    false,false,false,true,false,false);
    wikidata.añadirBloque(17.1,"log","Madera de Abeto",false,true,\
    "Puede ser obtenido al romperse con cualquier cosa, pero la herramienta más eficiente es el hacha.",\
    false,false,false,true,false,false);
    wikidata.añadirBloque(17.2,"log","Madera de Abedul",false,true,\
    "Puede ser obtenido al romperse con cualquier cosa, pero la herramienta más eficiente es el hacha.",\
    false,false,false,true,false,false);
    wikidata.añadirBloque(17.3,"log","Madera de Jungla",false,true,\
    "Puede ser obtenido al romperse con cualquier cosa, pero la herramienta más eficiente es el hacha.",\
    false,false,false,true,false,false);
    wikidata.añadirBloque(17.4,"log","Madera de Acacia",false,true,\
    "Puede ser obtenido al romperse con cualquier cosa, pero la herramienta más eficiente es el hacha.",\
    false,false,false,true,false,false);
    wikidata.añadirBloque(17.5,"log","Madera de Roble Oscuro",false,true,\
    "Puede ser obtenido al romperse con cualquier cosa, pero la herramienta más eficiente es el hacha.",\
    false,false,false,true,false,false);  

     wikidata.añadirBloque(12,"sand","Arena",false,true,\
    "Puede ser obtenido al romperse con cualquier cosa, pero la herramienta más eficiente para conseguirla es la pala.",\
    false,false,true,false,false,false);
    wikidata.añadirBloque(13,"gravel","Grava",false,true,\
    "Puede ser obtenido al romperse con cualquier cosa, pero la herramienta más eficiente para conseguirla es la pala.",\
    false,false,true,false,false,false);
    wikidata.añadirBloque(7,"bedrock","Piedra Base",false,false,\
    "Solo puede ser obtenido mediante el creativo.",false,false,false,false,false,false);

    //Bloques líquidos
    wikidata.añadirLiquido(8,"flowing_water","Agua En Flujo",true,\
    false,true,"Tiene una propagación de 7 bloques en una superficie plana.\n",\
    "Sí un mob permanece mucho tiempo sumergido en el agua se consumirá su barra de oxígeno "
    "(también afecta a los jugadores). \nTambién tiene la capacidad de neutralizar explosiones "
    "para evitar el daño a bloques cercanos (pero no ha los mobs). \nAl mesclarze con lava puede producir "
    "distintos tipos de bloques.");
    wikidata.añadirLiquido(10,"flowing_lava","Lava En Flujo",true,\
    true,false,"Tiene una propagación de 3 bloques en una superfice plana en el mundo normal.",\
    "La lava prenderá en fuego cualquier entidad que entre en contacto con la misma,\nsi un objeto cae en "
    "ella se quemará y perdera para siempre al menos que tenga resistencia al fuego. \nTambién puede "
    "alimentar un horno para cocinar 100 bloques.");
    
    //Minerales
    wikidata.añadirMineral(14,"gold_ore","Mena de Oro","Puede ser obtenido mediante cualquier tipo de pico a partir del de hierro.",\
    "Bloque de Mena de Oro","Entre la capa 0 a 31 para todos los biomas y entre 28 y 80 para el bioma \"Badlands\".");
    wikidata.añadirMineral(15,"iron_ore","Mena de Hierro",\
    "Puede ser obtenido mediante cualquier tipo de pico a partir del de piedra.",\
    "Bloque de Mena de Hierro","Alrededor y por debajo del nivel del mar, es decir, bajo la capa 68.");
    wikidata.añadirMineral(16,"coal_ore","Mena de Carbón",\
    "Puede ser obtenido mediante cualquier tipo de pico a partir del de piedra.",\
    "Carbón","Entre la capa 0 a 127 para todos los biomas.");


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

/**
 * Esta función crea un delay mediante recorrer un arreglo vacío grande.
 *
 * @param float timeOfDelay: el tiempo que quieres que dure el delay. No es exacto.
 * @return
 */
void sleep(float timeOfDelay){
    timeOfDelay *= 10000;
    for(int i; i <= timeOfDelay; i++){}
};

/**
 * Esta función crea un menú para dar funcionalidad a la app y usar los métodos de la clase "WikiData".
 * Esto se realiza mediante el uso de una expresión switch la cual posee las distintas opciones del menú.
 *
 * @param WikiData wikidata: El objeto de tipo WikiData que requiere la función para acceder a los distintos métodos.
 * @return
 */
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
            cout << "¿Acaso este nuevo poder no fué suficiente para tí?..." << endl << endl;
            sleep(4.2);
        }
        menu(wikidata);
        break;
    case 4:
        sleep(2.2);
        printf("\e[1;1H\e[2J");
        cout << "Eso fue todo, esperamos que te haya gustado nuestra WIKI." << endl << "Vuelve pronto !!!" << endl;
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

/**
 * Esta subfunción de "menu" crea un menú para permitir añadir bloques mediante los métodos de la clase WikiData.
 * Los bloques que permite añadir son: "Bloque General", "Liquido" y "Mineral".
 * Los cuales hacen uso de la función añadirBloque(), añadirLiquido() y añadirMineral() respectivamente.
 *
 * @param WikiData wikidata: El objeto de tipo WikiData que requiere la función para acceder a los distintos métodos.
 * @return
 */
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
        
        cout << "\nIngresa el ID del nombre (tipo de bloque) del bloque que deseas añadir." << endl;
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
        
        cout << "\nIngresa el ID del nombre (tipo de bloque) del bloque líquido que deseas añadir." << endl;
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
        
        cout << "\nIngresa el ID del nombre (tipo de bloque) del bloque de mineral que deseas añadir." << endl;
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