/*
* Proyecto Minecraft Wiki
* Rommel T. C.
* A01709922
*/

/*
* Clase Liquido
* Tiene los atributos y métodos básicos de los liquidos, y hereda de la clase
* padre (Bloque)
*/

#ifndef LIQUIDO_H_
#define LIQUIDO_H_

#include "Bloque.h"
#include <string>

using namespace std;

//Declaración de clase liquido, que es una clase hijo
class Liquido : public Bloque {
    //Declaración de variables de instancia
    private:
    string propagacion;
    string propiedades;

    public:
    //Declaración de los constructores y métodos
    Liquido();
    Liquido(float identifier, string nameIdentifier, string name,\
    bool damage,bool luminous, bool transparent,\
    string propagation, string properties);
    string getPropagacion();
    string getPropiedades();
    void setPropagacion(string propagation);
    void setPropiedades(string properties);
};

/**
 * Constructor por default que inicializa con valores predeterminados
 *
 * @param
 * @return Objeto Liquido
 */
Liquido::Liquido(){
    idNumerico = -1.0;
    idNombre = "";
    nombre = "";
    interactuable = true;
    puedeRomperse = false;
    obtencion = "Puede obtenerse mediante una cubeta.";
    crafteable = false;
    danno = "";
    obedeceGravedad = true;
    flamable = false;
    luminoso = false;
    transparente = false;
    propagacion = "";
    propiedades = "";
}

/**
 * Constructor que recibe parámetros para llenar las variables de instancia faltantes
 *
 * @param float identifier: id del bloque líquido,
 * string nameIdentifier: nombre usado para identificar el bloque líquido,
 * string name: nombre del bloque líquido,
 * bool damage: si el bloque líquido causa daño al estar en contacto con él,
 * bool luminous: si emite algún tipo de luz, bool transparent: si permite el paso de la luz,
 * string propagation: la distancia que el bloque líquido puede propagarse,
 * string properties: las propiedades del bloque líquido.
 * @return Objeto Liquido
 */
Liquido::Liquido(float identifier, string nameIdentifier, string name,\
bool damage, bool luminous, bool transparent, string propagation, string properties){
    idNumerico = identifier;
    idNombre = nameIdentifier;
    nombre = name;
    interactuable = true;
    puedeRomperse = false;
    obtencion = "Puede obtenerse mediante una cubeta.";
    crafteable = false;
    danno = damage;
    obedeceGravedad = true;
    flamable = false;
    luminoso = luminous;
    transparente = transparent;
    propagacion = propagation;
    propiedades = properties;
}

//Getters

/**
 * getter propagacion
 *
 * @param
 * @return string: la distancia que el bloque líquido puede propagarse
*/
string Liquido::getPropagacion(){
    return propagacion;
}

/**
 * getter propiedades
 *
 * @param
 * @return string: las propiedades del bloque líquido
*/
string Liquido::getPropiedades(){
    return propiedades;
}

//Setters

/**
 * setter propagacion
 *
 * @param string propagation: la distancia que el bloque líquido puede propagarse
 * @return
*/
void Liquido::setPropagacion(string propagation){
    propagacion = propagation;
}

/**
 * setter propiedades
 *
 * @param string properties: las propiedades del bloque líquido
 * @return
*/
void Liquido::setPropiedades(string properties){
    propiedades = properties;
}

#endif