/*
* Proyecto Minecraft Wiki
* Rommel T. C.
* A01709922
*/

/*
* Clase Bloque
* Tiene los atributos y métodos básicos, y funciona como creador de objetos y
* padre de clases
*/

#ifndef BLOQUE_H_
#define BLOQUE_H_

#include <string>

using namespace std;

//Declaración de clase liquido, la clase padre
class Bloque {
    //Declaración de variables de instancia
    protected:
    float idNumerico;
    string idNombre;
    string nombre;
    bool interactuable;
    bool puedeRomperse;
    string obtencion;
    bool crafteable;
    bool danno;
    bool obedeceGravedad;
    bool flamable;
    bool luminoso;
    bool transparente;

    public:
    //Declaración de los constructores y métodos
    Bloque();
    Bloque(float identifier, string nameIdentifier, string name,\
    string obtainable, bool canBeCrafted, bool flammable);
    Bloque(float identifier, string nameIdentifier, string name,\
    bool interactive, bool breakable, string obtainable, bool canBeCrafted,\
    bool damage, bool obeysPhysics, bool flammable, bool luminous, bool transparent);
    float getIdNumerico();
    string getIdNombre();
    string getNombre();
    bool getInteractuable();
    bool getPuedeRomperse();
    string getObtencion();
    bool getCrafteable();
    bool getDanno();
    bool getObedeceGravedad();
    bool getFlamable();
    bool getLuminoso();
    bool getTransparente();
    void setIdNumerico(float identifier);
    void setIdNombre(string nameIdentifier);
    void setNombre(string name);
    void setInteractuable(bool interactive);
    void setPuedeRomperse(bool breakable);
    void setObtencion(string obtainable);
    void setCrafteable(bool canBeCrafted);
    void setDanno(bool damage);
    void setObedeceGravedad(bool obeysPhysics);
    void setFlamable(bool flammable);
    void setLuminoso(bool luminous);
    void setTransparente(bool transparent);
};

/**
 * Constructor por default que inicializa con valores predeterminados
 *
 * @param
 * @return Objeto Bloque
 */
Bloque::Bloque(){
    idNumerico = -1.0;
    idNombre = "";
    nombre = "";
    interactuable = false;
    puedeRomperse = false;
    obtencion = "";
    crafteable = false;
    danno = false;
    obedeceGravedad = false;
    flamable = false;
    luminoso = false;
    transparente = false;
}

/**
 * Constructor que recibe parámetros para llenar las variables de instancia faltantes
 *
 * @param float identifier: id del bloque,
 * string nameIdentifier: nombre usado para identificar el bloque,
 * string name: nombre del bloque, string obtainable: manera de obtener el bloque,
 * bool canBeCrafted: si el bloque puede craftearse,
 * bool flammable: si se consume por el fuego y ayuda a propagarlo.
 * @return Objeto Bloque
 */
Bloque::Bloque(float identifier, string nameIdentifier, string name,\
string obtainable, bool canBeCrafted, bool flammable){
    idNumerico = identifier;
    idNombre = nameIdentifier;
    nombre = name;
    interactuable = false;
    puedeRomperse = true;
    obtencion = obtainable;
    crafteable = canBeCrafted;
    danno = false;
    obedeceGravedad = false;
    flamable = flammable;
    luminoso = false;
    transparente = false;
}

/**
 * Constructor que recibe parámetros para llenar todas las variables de instancia
 *
 * @param float identifier: id del bloque,
 * string nameIdentifier: nombre usado para identificar el bloque,
 * string name: nombre del bloque,
 * bool interactive: si el bloque hace algo al ser interactuado con él,
 * bool breakable: si el bloque puede romperse,
 * string obtainable: manera de obtener el bloque,
 * bool canBeCrafted: si el bloque puede craftearse,
 * bool damage: si el bloque causa daño al estar en contacto con él,
 * bool obeysPhysics: si el bloque es afectado al romper su soporte,
 * bool flammable: si se consume por el fuego y ayuda a propagarlo,
 * bool luminous: si emite algún tipo de luz,
 * bool transparent: si permite el paso de la luz.
 * @return Objeto Bloque
 */
Bloque::Bloque(float identifier, string nameIdentifier, string name,\
bool interactive, bool breakable, string obtainable, bool canBeCrafted,\
bool damage, bool obeysPhysics, bool flammable, bool luminous, bool transparent){
    idNumerico = identifier;
    idNombre = nameIdentifier;
    nombre = name;
    interactuable = interactive;
    puedeRomperse = breakable;
    obtencion = obtainable;
    crafteable = canBeCrafted;
    danno = damage;
    obedeceGravedad = obeysPhysics;
    flamable = flammable;
    luminoso = luminous;
    transparente = transparent;
}

//Getters

/**
 * getter idNumerico
 *
 * @param
 * @return float: id del bloque
*/
float Bloque::getIdNumerico(){
    return idNumerico;
}

/**
 * getter idNombre
 *
 * @param
 * @return string: nombre usado para identificar el bloque
*/
string Bloque::getIdNombre(){
    return idNombre;
}

/**
 * getter nombre
 *
 * @param
 * @return string: nombre del bloque
*/
string Bloque::getNombre(){
    return nombre;
}

/**
 * getter interactuable
 *
 * @param
 * @return bool: si el bloque hace algo al ser interactuado con él
*/
bool Bloque::getInteractuable(){
    return interactuable;
}

/**
 * getter puedeRomperse
 *
 * @param
 * @return bool: si el bloque puede romperse
*/
bool Bloque::getPuedeRomperse(){
    return puedeRomperse;
}

/**
 * getter obtencion
 *
 * @param
 * @return string: manera de obtener el bloque
*/
string Bloque::getObtencion(){
    return obtencion;
}

/**
 * getter crafteable
 *
 * @param
 * @return bool: si el bloque puede craftearse
*/
bool Bloque::getCrafteable(){
    return crafteable;
}

/**
 * getter danno
 *
 * @param
 * @return bool: si el bloque causa daño al estar en contacto con él
*/
bool Bloque::getDanno(){
    return danno;
}

/**
 * getter obedeceGravedad
 *
 * @param
 * @return bool: si el bloque es afectado al romper su soporte
*/
bool Bloque::getObedeceGravedad(){
    return obedeceGravedad;
}

/**
 * getter flamable
 *
 * @param
 * @return bool: si se consume por el fuego y ayuda a propagarlo
*/
bool Bloque::getFlamable(){
    return flamable;
}

/**
 * getter luminoso
 *
 * @param
 * @return bool: si emite algún tipo de luz
*/
bool Bloque::getLuminoso(){
    return luminoso;
}

/**
 * getter transparente
 *
 * @param
 * @return bool: si permite el paso de la luz
*/
bool Bloque::getTransparente(){
    return transparente;
}

//Setters

/**
 * setter idNumerico
 *
 * @param float identifier: id del bloque,
 * @return
*/
void Bloque::setIdNumerico(float identifier){
    idNumerico = identifier;
}

/**
 * setter 
 *
 * @param string nameIdentifier: nombre usado para identificar el bloque
 * @return
*/
void Bloque::setIdNombre(string nameIdentifier){
    idNombre = nameIdentifier;
}

/**
 * setter 
 *
 * @param string name: nombre del bloque
 * @return
*/
void Bloque::setNombre(string name){
    nombre = name;
}

/**
 * setter 
 *
 * @param bool interactive: si el bloque hace algo al ser interactuado con él
 * @return
*/
void Bloque::setInteractuable(bool interactive){
    interactuable = interactive;
}

/**
 * setter 
 *
 * @param bool breakable: si el bloque puede romperse
 * @return
*/
void Bloque::setPuedeRomperse(bool breakable){
    puedeRomperse = breakable;
}

/**
 * setter 
 *
 * @param string obtainable: manera de obtener el bloque
 * @return
*/
void Bloque::setObtencion(string obtainable){
    obtencion = obtainable;
}

/**
 * setter 
 *
 * @param bool canBeCrafted: si el bloque puede craftearse
 * @return
*/
void Bloque::setCrafteable(bool canBeCrafted){
    crafteable = canBeCrafted;
}

/**
 * setter 
 *
 * @param bool damage: si el bloque causa daño al estar en contacto con él
 * @return
*/
void Bloque::setDanno(bool damage){
    danno = damage;
}

/**
 * setter 
 *
 * @param bool obeysPhysics: si el bloque es afectado al romper su soporte
 * @return
*/
void Bloque::setObedeceGravedad(bool obeysPhysics){
    obedeceGravedad = obeysPhysics;
}

/**
 * setter 
 *
 * @param bool flammable: si se consume por el fuego y ayuda a propagarlo
 * @return
*/
void Bloque::setFlamable(bool flammable){
    flamable = flammable;
}

/**
 * setter 
 *
 * @param bool luminous: si emite algún tipo de luz
 * @return
*/
void Bloque::setLuminoso(bool luminous){
    luminoso = luminous;
}

/**
 * setter 
 *
 * @param bool transparent: si permite el paso de la luz
 * @return
*/
void Bloque::setTransparente(bool transparent){
    transparente = transparent;
}


#endif