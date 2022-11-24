#ifndef WIKIDATA_H_
#define WIKIDATA_H_

#include "Bloque.h"
#include "Liquido.h"
#include "Mineral.h"
#include <iostream>
#include <iomanip>

using namespace std;
const int MAX = 100; //Quitar después y adaptar a los valores exactos.


class WikiData {
    private:
    int indiceBloques = -1;
    int indiceLiquidos = -1;
    int indiceMinerales = -1;
    Bloque bloques[MAX];
    Liquido liquidos[MAX];
    Mineral minerales[MAX];

    public:
    //Constructor
    WikiData(){};
    void añadirBloque(float, string, string, string, bool, bool);
    void añadirBloque(float, string, string, bool, bool, string, bool,\
    bool, bool, bool, bool, bool);
    void añadirLiquido(float, string, string, bool, bool , bool, string, string);
    void añadirMineral(float, string, string, string, string, string);
    void añadirMineral(float, string, string, bool,\
    string, bool, string, string);
    void mostrarListaDeBloques();
    void encontrarEnListaDeBloques();
    string obtenerInformacionBloque(Bloque);
    string obtenerInformacionBloque(Liquido);
    string obtenerInformacionBloque(Mineral);
};

void WikiData::añadirBloque(float identifier, string nameIdentifier, string name,\
    string obtainable, bool canBeCrafted, bool flammable){
        indiceBloques += 1;
        Bloque aux(identifier, nameIdentifier, name,\
        obtainable, canBeCrafted, flammable);
        bloques[indiceBloques] = aux;
};

void WikiData::añadirBloque(float identifier, string nameIdentifier, string name,\
    bool interactive, bool breakable, string obtainable, bool canBeCrafted,\
    bool damage, bool obeysPhysics, bool flammable, bool luminous, bool transparent){
        indiceBloques += 1;
        Bloque aux(identifier, nameIdentifier, name,\
    interactive, breakable, obtainable, canBeCrafted,\
    damage, obeysPhysics, flammable, luminous, transparent);
        bloques[indiceBloques] = aux;
};

void WikiData::añadirLiquido(float identifier, string nameIdentifier, string name,\
    bool damage,bool luminous, bool transparent,\
    string propagation, string properties){
        indiceBloques += 1;
        Liquido aux(identifier, nameIdentifier, name,\
    damage,luminous, transparent, propagation, properties);
        liquidos[indiceLiquidos] = aux;
};

void WikiData::añadirMineral(float identifier, string nameIdentifier, string name,\
    string obtainable, string itemDrop, string localitation){
        indiceBloques += 1;
        Mineral aux(identifier, nameIdentifier, name,\
        obtainable, itemDrop, localitation);
        minerales[indiceMinerales] = aux;
};

void WikiData::añadirMineral(float identifier, string nameIdentifier, string name,\
    bool interactive, string obtainable, bool luminous,\
    string itemDrop, string localitation){
        indiceBloques += 1;
        Mineral aux(identifier, nameIdentifier, name,\
    interactive, obtainable, luminous, itemDrop, localitation);
        minerales[indiceMinerales] = aux;
};

void WikiData::mostrarListaDeBloques(){
    cout << "Bloques Sólidos Regulares:" << endl;
    cout << left << setw(6) << "ID" << left << "Nombre del Bloque" << endl;
    for(int i = 0; i <= indiceBloques; i++){
        cout << left << setw(6) <<\
        bloques[i].getIdNumerico() <<\
        left << bloques[i].getNombre() << endl;  
    }

    cout << "\nBloques Líquidos:" << endl;
    cout << left << setw(6) << "ID" << left << "Nombre del Bloque" << endl;
    for(int i = 0; i <= indiceLiquidos; i++){
        cout << left << setw(6) <<\
        liquidos[i].getIdNumerico() <<\
        left << liquidos[i].getNombre() << endl;  
    }

    cout << "\nMinerales:" << endl;
    cout << left << setw(6) << "ID" << left << "Nombre del Bloque" << endl;
    for(int i = 0; i <= indiceMinerales; i++){
        cout << left << setw(6) <<\
        minerales[i].getIdNumerico() <<\
        left << minerales[i].getNombre() << endl;  
    }
};

#endif
    // string Bloque::getIdNumerico(){
    //     return "Id Númerico: " + idNumerico + "\n";
    // }
    
    // string Bloque::getIdNombre(){
    //     return "Id del Nombre: " + idNombre + "\n";
    // }
    
    // string Bloque::getNombre(){
    //     return "Nombre: " + nombre + "\n";
    // }
    
    // string Bloque::getInteractuable(){
    //     if(interactuable == 1){
    //         return "¿Interactuable?: Se puede interactuar con este bloque.\n";
    //     }
    //     else{
    //         return "¿Interactuable?: No se puede interactuar con este bloque.\n";
    //     }
    // }
    
    // string Bloque::getPuedeRomperse(){
    //     if(puedeRomperse == 1){
    //         return "¿Puede romperse?: Este bloque puede ser roto.\n";
    //     }
    //     else{
    //         return "¿Puede romperse?: Este bloque es irrompible.\n";
    //     }
    // }
    
    // string Bloque::getObtencion(){
    //     if(puedeRomperse == 0){
    //         return "¿Cómo se obtiene?: Este bloque solo puede conseguirse\
    //         mediante el creativo o mediante comandos.\n";
    //     }
    //     else{
    //         return "¿Cómo se obtiene?: " + obtencion + "\n";
    //     }
    // }
    
    // string Bloque::getCrafteable(){
    //     if(crafteable == 1){
    //         return "¿Crafteable?: Este bloque puede craftearse.\n";
    //     }
    //     else{
    //         return "¿Crafteable?: Este bloque no puede ser crafteado.\n";
    //     }
    // }

    // string Bloque::getDanno(){
    //     return "¿Produce daño al jugador?: Este bloque no ocasionará daño al jugador\
    //     de manera general.\n";
    // }

    // string Bloque::getDanno(string metodo_danno){
    //     return "¿Produce daño al jugador?: " + metodo_danno + "\n";
    // }
    
    // string Bloque::getObedeceGravedad(){
    //     return "¿Es afectado por la gravedad?: Este bloque no será afectado si rompes\
    //     su bloque de soporte.\n";
    // }

    // string Bloque::getObedeceGravedad(string efecto){
    //     return "¿Es afectado por la gravedad?: " + efecto + "\n";
    // }
    
    // string Bloque::getFlamable(){
    //     if(flamable == 1){
    //         return "¿Es flamable?: Este objeto puede prenderse en fuego al estar en proximidad\
    //         de lava o fuego, y puede ayudar a propagarlo.\n";
    //     }
    //     else{
    //         return "¿Es flamable?: Este objeto no desaparecerá ni será consumido al ser afectado\
    //         por fuego o lava.\n";
    //     }
    // }
    
    // string Bloque::getLuminoso(){
    //     if(luminoso == 1){
    //         return "¿Produce luz?: Este bloque tiene la capacidad de producir luz.\n";
    //     }
    //     else{
    //         return "¿Produce luz?: Este bloque no emite ningún tipo de luz.\n";
    //     }
    // }
    
    // string Bloque::getTransparente(){
    //     if(transparente == 1){
    //         return "¿Es transparente?: Este bloque permite el paso de la luz.\n";
    //     }
    //     else{
    //         return "¿Es transparente?: Este bloque no permitirá que la luz lo atraviese.\n";
    //     }
    // }