#ifndef LIQUIDO_H_
#define LIQUIDO_H_

#include "Bloque.h"
#include <string>

using namespace std;

class Liquido : public Bloque {
    //Atributos
    private:
    bool interactuable = true;
    bool puedeRomperse = false;
    string obtencion = "Puede obtenerse mediante una cubeta.\n";
    bool crafteable = false;
    bool obedeceGravedad = true;
    bool flamable = false;
    string propagacion;
    string propiedades;

    public:
    //Constructores
    Liquido();
    Liquido(float identifier, string nameIdentifier, string name,\
    bool damage,bool luminous, bool transparent,\
    string propagation, string properties);
    //Getters
    string getPropagacion();
    string getPropiedades();
    //Setters
    void setPropagacion(string propagation);
    void setPropiedades(string properties);
};

//Constructores
Liquido::Liquido(){
  idNumerico = -1.0;
  idNombre = "";
  nombre = "";
  danno = "";
  luminoso = false;
  transparente = false;
  propagacion = "";
  propiedades = "";
}

Liquido::Liquido(float identifier, string nameIdentifier, string name,\
  bool damage,bool luminous, bool transparent, string propagation, string properties){
  idNumerico = identifier;
  idNombre = nameIdentifier;
  nombre = name;
  danno = damage;
  luminoso = luminous;
  transparente = transparent;
  propagacion = propagation;
  propiedades = properties;
}

//Getters
string Liquido::getPropagacion(){
  return propagacion;
}

string Liquido::getPropiedades(){
  return propiedades;
}

//Setters
void Liquido::setPropagacion(string propagation){
  propagacion = propagation;
}

void Liquido::setPropiedades(string properties){
  propiedades = properties;
}

#endif