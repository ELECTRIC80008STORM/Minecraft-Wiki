/*
* Proyecto Minecraft Wiki
* Rommel T. C.
* A01709922
*/

/*
* Clase Mineral
* Tiene los atributos y métodos básicos de los minerales, y hereda de la clase
* padre (Bloque)
*/

#ifndef MINERAL_H_
#define MINERAL_H_

#include "Bloque.h"
#include <string>

using namespace std;

//Declaración de clase mineral, que es una clase hija
class Mineral : public Bloque {
    //Declaración de variables de instancia
    private:
    string drop;
    string localizacion;

    public:
    //Declaración de los constructores y métodos
    Mineral();
    Mineral(float identifier, string nameIdentifier, string name,\
    string obtainable, string itemDrop, string localitation);
    Mineral(float identifier, string nameIdentifier, string name,\
    bool interactive, string obtainable, bool luminous,\
    string itemDrop, string localitation);
    string getDrop();
    string getLocalizacion();
    void setDrop(string itemDrop);
    void setLocalizacion(string localitation);
};

/**
 * Constructor por default que inicializa con valores predeterminados
 *
 * @param
 * @return Objeto Mineral
 */
Mineral::Mineral(){
    idNumerico = -1.0;
    idNombre = "";
    nombre = "";
    interactuable = false;
    puedeRomperse = true;
    obtencion = "";
    crafteable = false;
    danno = false;
    obedeceGravedad = false;
    flamable = false;
    luminoso = false;
    transparente = false;
    drop = "";
    localizacion = "";
}

/**
 * Constructor que recibe parámetros para llenar las variables de instancia faltantes
 *
 * @param float identifier: id del mineral, string nameIdentifier: nombre usado para identificar el mineral,
 * string name: nombre del mineral, string obtainable: manera de obtener el mineral, string itemDrop: item o items que
 * dropea el mineral y string localitation: las capas y/o biomas en donde se genera el mineral.
 * @return Objeto Mineral
 */
Mineral::Mineral(float identifier, string nameIdentifier, string name,\
string obtainable, string itemDrop, string localitation){
    idNumerico = identifier;
    idNombre = nameIdentifier;
    nombre = name;
    interactuable = false;
    puedeRomperse = true;
    obtencion = obtainable;
    crafteable = false;
    danno = false;
    obedeceGravedad = false;
    flamable = false;
    luminoso = false;
    drop = itemDrop;
    localizacion = localitation;
}

/**
 * Constructor que recibe parámetros para llenar las variables de instancia faltantes
 *
 * @param float identifier: id del mineral, string nameIdentifier: nombre usado para identificar el mineral,
 * string name: nombre del mineral, bool interactive: si el mineral hace algo al ser interactuado con él,
 * string obtainable: manera de obtener el mineral, bool luminous: si emite algún tipo de luz, string itemDrop: item o items que
 * dropea el mineral y string localitation: las capas y/o biomas en donde se genera el mineral.
 * @return Objeto Mineral
 */
Mineral::Mineral(float identifier, string nameIdentifier, string name,\
bool interactive, string obtainable, bool luminous, string itemDrop, string localitation){
    idNumerico = identifier;
    idNombre = nameIdentifier;
    nombre = name;
    interactuable = interactive;
    puedeRomperse = true;
    obtencion = obtainable;
    crafteable = false;
    danno = false;
    obedeceGravedad = false;
    flamable = false;
    luminoso = luminous;
    transparente = false;
    drop = itemDrop;
    localizacion = localitation;
}

//Getters

/**
 * getter drop
 *
 * @param
 * @return string: item o items que dropea el mineral
*/
string Mineral::getDrop(){
    return drop;
}

/**
 * getter localizacion
 *
 * @param
 * @return string: las capas y/o biomas en donde se genera el mineral.
*/
string Mineral::getLocalizacion(){
    return localizacion;
}

//Setters

/**
 * setter drop
 *
 * @param string itemDrop: item o items que dropea el mineral
 * @return
*/
void Mineral::setDrop(string itemDrop){
    drop = itemDrop;
}

/**
 * setter localizacion
 *
 * @param string localitation: las capas y/o biomas en donde se genera el mineral.
 * @return
*/
void Mineral::setLocalizacion(string localitation){
    localizacion = localitation;
}

#endif