#ifndef BLOQUE_H_
#define BLOQUE_H_

#include <string>

using namespace std;

class Bloque {
    //Atributos
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
    //Constructores
    Bloque();
    Bloque(float identifier, string nameIdentifier, string name,\
    string obtainable, bool canBeCrafted, bool flammable);
    Bloque(float identifier, string nameIdentifier, string name,\
    bool interactive, bool breakable, string obtainable, bool canBeCrafted,\
    bool damage, bool obeysPhysics, bool flammable, bool luminous, bool transparent);
    //Getters
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
    //Setters
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

//Constructores
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

Bloque::Bloque(float identifier, string nameIdentifier, string name,\
string obtainable, bool canBeCrafted, bool flammable){
    idNumerico = identifier;
    idNombre = nameIdentifier;
    nombre = name;
    interactuable = false;
    puedeRomperse = true;
    obtencion = "";
    crafteable = false;
    danno = false;
    obedeceGravedad = false;
    flamable = false;
    luminoso = false;
    transparente = false;
}

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
float Bloque::getIdNumerico(){
    return idNumerico;
}

string Bloque::getIdNombre(){
    return idNombre;
}

string Bloque::getNombre(){
    return nombre;
}

bool Bloque::getInteractuable(){
    return interactuable;
}

bool Bloque::getPuedeRomperse(){
    return puedeRomperse;
}

string Bloque::getObtencion(){
    return obtencion;
}

bool Bloque::getCrafteable(){
    return crafteable;
}

bool Bloque::getDanno(){
    return danno;
}

bool Bloque::getObedeceGravedad(){
    return obedeceGravedad;
}

bool Bloque::getFlamable(){
    return flamable;
}

bool Bloque::getLuminoso(){
    return luminoso;
}

bool Bloque::getTransparente(){
    return transparente;
}

//Setters
void Bloque::setIdNumerico(float identifier){
    idNumerico = identifier;
}

void Bloque::setIdNombre(string nameIdentifier){
    idNombre = nameIdentifier;
}

void Bloque::setNombre(string name){
    nombre = name;
}

void Bloque::setInteractuable(bool interactive){
    interactuable = interactive;
}

void Bloque::setPuedeRomperse(bool breakable){
    puedeRomperse = breakable;
}

void Bloque::setObtencion(string obtainable){
    obtencion = obtainable;
}

void Bloque::setCrafteable(bool canBeCrafted){
    crafteable = canBeCrafted;
}

void Bloque::setDanno(bool damage){
    danno = damage;
}

void Bloque::setObedeceGravedad(bool obeysPhysics){
    obedeceGravedad = obeysPhysics;
}

void Bloque::setFlamable(bool flammable){
    flamable = flammable;
}

void Bloque::setLuminoso(bool luminous){
    luminoso = luminous;
}

void Bloque::setTransparente(bool transparent){
    transparente = transparent;
}


#endif
