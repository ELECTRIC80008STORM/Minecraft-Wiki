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

class Mineral : public Bloque {
    //Atributos
    private:
    string drop;
    string localizacion;

    public:
    //Constructores
    Mineral();
    Mineral(float identifier, string nameIdentifier, string name,\
    string obtainable, string itemDrop, string localitation);
    Mineral(float identifier, string nameIdentifier, string name,\
    bool interactive, string obtainable, bool luminous,\
    string itemDrop, string localitation);
    //Getters
    string getDrop();
    string getLocalizacion();
    //Setters
    void setDrop(string itemDrop);
    void setLocalizacion(string localitation);
};

//Constructores
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
string Mineral::getDrop(){
  return drop;
}

string Mineral::getLocalizacion(){
  return localizacion;
}

//Setters
void Mineral::setDrop(string itemDrop){
    drop = itemDrop;
}

void Mineral::setLocalizacion(string localitation){
    localizacion = localitation;
}

#endif