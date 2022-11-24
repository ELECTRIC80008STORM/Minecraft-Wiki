#ifndef MINERAL_H_
#define MINERAL_H_

#include "Bloque.h"
#include <string>

using namespace std;

class Mineral : public Bloque {
    //Atributos
    private:
    bool puedeRomperse = true;
    bool crafteable = false;
    bool danno = false;
    bool obedeceGravedad = false;
    bool flamable = false;
    bool transparente = false;
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
  obtencion = "";
  luminoso = false;
  drop = "";
  localizacion = "";
}

Mineral::Mineral(float identifier, string nameIdentifier, string name,\
    string obtainable, string itemDrop, string localitation){
  idNumerico = identifier;
  idNombre = nameIdentifier;
  nombre = name;
  interactuable = false;
  obtencion = obtainable;
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
  obtencion = obtainable;
  luminoso = luminous;
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