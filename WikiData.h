/*
* Proyecto Minecraft Wiki
* Rommel T. C.
* A01709922
*/

/*
* Clase WikiData, la cuál maneja la información de los objetos de las
* clases "Bloque", "Liquido" y "Mineral".
*/

#ifndef WIKIDATA_H_
#define WIKIDATA_H_

#include "Bloque.h"
#include "Liquido.h"
#include "Mineral.h"
#include <iostream>
#include <iomanip>

using namespace std;
const int MAX = 100; //Constante del tamaño de los arreglos


//Declaración de clase wikidata
class WikiData {
    private:
    //Declaración de variables de instancia
    int indiceBloques = -1;
    int indiceLiquidos = -1;
    int indiceMinerales = -1;
    Bloque bloques[MAX];
    Liquido liquidos[MAX];
    Mineral minerales[MAX];
    //Declaración de funciones privadas
    void obtenerInformacionBloque(Bloque);
    void obtenerInformacionBloque(Liquido);
    void obtenerInformacionBloque(Mineral);

    public:
    //Declaración de los constructores y métodos
    WikiData();
    void añadirBloque(float, string, string, string, bool, bool);
    void añadirBloque(float, string, string, bool, bool, string, bool,\
    bool, bool, bool, bool, bool);
    void añadirLiquido(float, string, string, bool, bool , bool, string, string);
    void añadirMineral(float, string, string, string, string, string);
    void añadirMineral(float, string, string, bool,\
    string, bool, string, string);
    void mostrarListaDeBloques();
    void encontrarEnListaDeBloques(float identifier);

};

/**
 * Constructor por default
 *
 * @param
 * @return Objeto WikiData
 */
WikiData::WikiData(){}

/**
 * Suma uno al "indiceBloques" de los Bloques.
 * Después utiliza el primer constructor (constructor corto) de la clase Bloque
 * para crear y guardar un objeto de tipo Bloque en el arreglo "bloques" tras pasarle las variables de  al objeto.
 *
 * @param float identifier: id del bloque,
 * string nameIdentifier: nombre usado para identificar el bloque,
 * string name: nombre del bloque, string obtainable: manera de obtener el bloque,
 * bool canBeCrafted: si el bloque puede craftearse,
 * bool flammable: si se consume por el fuego y ayuda a propagarlo.
 * @return 
 */
void WikiData::añadirBloque(float identifier, string nameIdentifier, string name,\
string obtainable, bool canBeCrafted, bool flammable){
    indiceBloques += 1;
    Bloque aux(identifier, nameIdentifier, name,\
    obtainable, canBeCrafted, flammable);
    bloques[indiceBloques] = aux;
}

/**
 * Suma uno al "indiceBloques" de los Bloques.
 * Después utiliza el segundo constructor (constructor detallado) de la clase Bloque
 * para crear y guardar un objeto de tipo Bloque en el arreglo "bloques" tras pasarle las variables de instancia al objeto
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
 * @return 
 */
void WikiData::añadirBloque(float identifier, string nameIdentifier, string name,\
bool interactive, bool breakable, string obtainable, bool canBeCrafted,\
bool damage, bool obeysPhysics, bool flammable, bool luminous, bool transparent){
    indiceBloques += 1;
    Bloque aux(identifier, nameIdentifier, name,\
    interactive, breakable, obtainable, canBeCrafted,\
    damage, obeysPhysics, flammable, luminous, transparent);
    bloques[indiceBloques] = aux;
}

/**
 * Suma uno al "indiceLiquidos" de los Liquidos.
 * Después utiliza el contructor de la clase Liquido para crear y guardar un objeto de tipo Liquido en el arreglo "liquidos"
 * tras pasarle las variables de instancia al objeto
 *
 * @param float identifier: id del bloque líquido,
 * string nameIdentifier: nombre usado para identificar el bloque líquido,
 * string name: nombre del bloque líquido,
 * bool damage: si el bloque líquido causa daño al estar en contacto con él,
 * bool luminous: si emite algún tipo de luz, bool transparent: si permite el paso de la luz,
 * string propagation: la distancia que el bloque líquido puede propagarse,
 * string properties: las propiedades del bloque líquido.
 * @return 
 */
void WikiData::añadirLiquido(float identifier, string nameIdentifier, string name,\
bool damage,bool luminous, bool transparent,\
string propagation, string properties){
    indiceLiquidos += 1;
    Liquido aux(identifier, nameIdentifier, name,\
    damage,luminous, transparent, propagation, properties);
    liquidos[indiceLiquidos] = aux;
}

/**
 * Suma uno al "indiceMinerales" de los Minerales.
 * Después utiliza el primer constructor (constructor corto) de la clase Mineral
 * para crear y guardar un objeto de tipo Mineral en el arreglo "minerales" tras pasarle las variables de  al objeto.
 *
 * @param float identifier: id del mineral, string nameIdentifier: nombre usado para identificar el mineral,
 * string name: nombre del mineral, string obtainable: manera de obtener el mineral, string itemDrop: item o items que
 * dropea el mineral y string localitation: las capas y/o biomas en donde se genera el mineral.
 * @return 
 */
void WikiData::añadirMineral(float identifier, string nameIdentifier, string name,\
string obtainable, string itemDrop, string localitation){
    indiceMinerales += 1;
    Mineral aux(identifier, nameIdentifier, name,\
    obtainable, itemDrop, localitation);
    minerales[indiceMinerales] = aux;
}

/**
 * Suma uno al "indiceMinerales" de los Minerales.
 * Después utiliza el segundo constructor (constructor detallado) de la clase Mineral
 * para crear y guardar un objeto de tipo Mineral en el arreglo "minerales" tras pasarle las variables de instancia al objeto
 *
 * @param float identifier: id del mineral, string nameIdentifier: nombre usado para identificar el mineral,
 * string name: nombre del mineral, bool interactive: si el mineral hace algo al ser interactuado con él,
 * string obtainable: manera de obtener el mineral, bool luminous: si emite algún tipo de luz, string itemDrop: item o items que
 * dropea el mineral y string localitation: las capas y/o biomas en donde se genera el mineral.
 * @return 
 */
void WikiData::añadirMineral(float identifier, string nameIdentifier, string name,\
bool interactive, string obtainable, bool luminous,\
string itemDrop, string localitation){
    indiceMinerales += 1;
    Mineral aux(identifier, nameIdentifier, name,\
    interactive, obtainable, luminous, itemDrop, localitation);
    minerales[indiceMinerales] = aux;
}

/**
 * Utiliza los arreglos "bloques", "liquidos" y "minerales" para mostrar en la consola todas las IDs numéricas
 * de los bloques junto a su nombre a la derecha del ID. Esto a través de un ciclo for usando los índices de cada tipo
 * de bloque.
 *
 * @param
 * @return 
 */
void WikiData::mostrarListaDeBloques(){
    int width = 6;
    cout << "Bloques Sólidos Regulares:" << endl;
    cout << left << setw(width) << "ID" << left << "Nombre del Bloque" << endl;
    for(int i = 0; i <= indiceBloques; i++){
        cout << left << setw(width) <<\
        bloques[i].getIdNumerico() <<\
        left << bloques[i].getNombre() << endl;  
    }

    cout << "\nBloques Líquidos:" << endl;
    cout << left << setw(width) << "ID" << left << "Nombre del Bloque" << endl;
    for(int i = 0; i <= indiceLiquidos; i++){
        cout << left << setw(width) <<\
        liquidos[i].getIdNumerico() <<\
        left << liquidos[i].getNombre() << endl;  
    }

    cout << "\nMinerales:" << endl;
    cout << left << setw(width) << "ID" << left << "Nombre del Bloque" << endl;
    for(int i = 0; i <= indiceMinerales; i++){
        cout << left << setw(width) <<\
        minerales[i].getIdNumerico() <<\
        left << minerales[i].getNombre() << endl;  
    }
    cout << endl << endl;
}

/**
 * Utiliza el objeto de tipo bloque para mostrar su información en pantalla.
 *
 * @param Bloque bloque: es el objeto de tipo bloque que utiliza la función para llamar la información que contenga.
 * @return 
 */
void WikiData::obtenerInformacionBloque(Bloque bloque){
    int width = 36;
    
    cout << bloque.getNombre() << endl << endl;
    cout << left << setw(width) << "Id Númerico:" << left << bloque.getIdNumerico() << endl;
    cout << left << setw(width - 1) << "Id del Nombre:" << left << bloque.getIdNombre() << endl;
    cout << left << setw(width - 1) << "Nombre:" << left << bloque.getNombre() << endl;
    
    if(bloque.getInteractuable() == 1){
        cout << left << setw(width) << "¿Interactuable?:" << left << "Se puede interactuar con este bloque." << endl;
    }
    else{
        cout << left << setw(width) << "¿Interactuable?:" << left << "No se puede interactuar con este bloque." << endl;
    }
    
    if(bloque.getPuedeRomperse() == 1){
        cout << left << setw(width) << "¿Puede romperse?:" << left << "Este bloque puede ser roto." << endl;
    }
    else{
        cout << left << setw(width) << "¿Puede romperse?:" << left << "Este bloque es irrompible, por lo tanto solo " <<
        "podrá romperse mediante creativo." << endl;
    }
    
    cout << left << setw(width + 1) << "¿Obtención?:" << left << bloque.getObtencion() << endl;
    if(bloque.getCrafteable() == 1){
        cout << left << setw(width) << "¿Crafteable?:" << left << "Este bloque puede craftearse." << endl;
    }
    else{
        cout << left << setw(width) << "¿Crafteable?:" << left << "Este bloque no puede ser crafteado." << endl;
    }
    
    if(bloque.getDanno() == 0){
        cout << left << setw(width + 1) << "¿Produce daño al jugador?:" << left << "Este bloque no ocasionará daño al jugador " <<
        "de manera general." << endl;
    }
    else{
        cout << left << setw(width + 1) << "¿Produce daño al jugador?:" << left << "Este bloque puede ocasionar daño al " <<
        "jugador sí se esta en contacto." << endl;
    }
    
    if(bloque.getObedeceGravedad() == 0){
        cout << left << setw(width) << "¿Es afectado por la gravedad?:" << left << "Este bloque no será afectado si rompes " <<
        "su bloque de soporte." << endl;
    }
    else{
        cout << left << setw(width) << "¿Es afectado por la gravedad?:" << left << "Este bloque sufrirá cambios si rompes " <<
        "el bloque que lo soporta" << endl;
    }
    
    if(bloque.getFlamable() == 1){
        cout << left << setw(width) << "¿Es flamable?:" << left << "Este bloque puede prenderse en fuego al estar en proximidad " <<
        "de lava o fuego, y puede ayudar a propagarlo." << endl;
    }
    else{
        cout << left << setw(width) << "¿Es flamable?:" << left << "Este bloque no desaparecerá ni será consumido al ser afectado "
        << "por fuego o lava." << endl;
    }
    
    if(bloque.getLuminoso() == 1){
        cout << left << setw(width) << "¿Produce luz?:" << left << "Este bloque tiene la capacidad de producir luz." << endl;
    }
    else{
        cout << left << setw(width) << "¿Produce luz?:" << left << "Este bloque no emite ningún tipo de luz." << endl;
    }
    
    if(bloque.getTransparente() == 1){
        cout << left << setw(width) << "¿Es transparente?:" << left << "Este bloque permite el paso de la luz." << endl;
    }
    else{
        cout << left << setw(width) << "¿Es transparente?:" << left << "Este bloque no permitirá que la luz lo atraviese." << endl;
        }
    
    cout << endl << endl;
}

/**
 * Utiliza el objeto de tipo liquido para mostrar su información en pantalla.
 *
 * @param Liquido liquido: es el objeto de tipo liquido que utiliza la función para llamar la información que contenga.
 * @return 
 */
void WikiData::obtenerInformacionBloque(Liquido liquido){
    int width = 36;
    
    cout << liquido.getNombre() << endl << endl;
    cout << left << setw(width) << "Id Númerico: " << left << liquido.getIdNumerico() << endl;
    cout << left << setw(width - 1) << "Id del Nombre: " << left << liquido.getIdNombre() << endl;
    cout << left << setw(width - 1) << "Nombre: " << left << liquido.getNombre() << endl;
    
    if(liquido.getInteractuable() == 1){
        cout << left << setw(width) << "¿Interactuable?: " << left << "Se puede interactuar con este bloque." << endl;
    }
    else{
        cout << left << setw(width) << "¿Interactuable?: " << left << "No se puede interactuar con este bloque." << endl;
    }
    
    cout << left << setw(width) << "¿Puede romperse?: " << left << "Este bloque no puede romperse al ser un líquido pero " <<
    "podrá quitarse al sustituir el espacio" << left << setw(width + 29) << "" << left << "con un bloque físico o tomandolo con una cubeta." << endl;
    
    cout << left << setw(width + 1) << "¿Obtención?: " << left << liquido.getObtencion() << endl;
    
    if(liquido.getCrafteable() == 1){
        cout << left << setw(width) << "¿Crafteable?: " << left << "Este bloque puede craftearse." << endl;
    }
    else{
        cout << left << setw(width) << "¿Crafteable?: " << left << "Este bloque no puede ser crafteado." << endl;
    }
    
    if(liquido.getDanno() == 0){
        cout << left << setw(width) << "¿Produce daño al jugador?: " << left << "Este bloque no ocasionará daño al jugador " <<
        "de manera general." << endl;
    }
    else{
        cout << left << setw(width + 1) << "¿Produce daño al jugador?: " << left << "Este bloque puede ocasionar daño al " <<
        "jugador sí se esta en contacto." << endl;
    }
    
    if(liquido.getObedeceGravedad() == 0){
        cout << left << setw(width + 1) << "¿Es afectado por la gravedad?: " << left << "Este bloque no será afectado si rompes " <<
        "su bloque de soporte." << endl;
    }
    else{
        cout << left << setw(width) << "¿Es afectado por la gravedad?: " << left << "Este bloque buscará extenderse hacia los lados " <<
        "y hacia abajo." << endl;
    }
    
    if(liquido.getFlamable() == 1){
        cout << left << setw(width) << "¿Es flamable?: " << left << "Este bloque puede prenderse en fuego al estar en proximidad " <<
        "de lava o fuego, y puede ayudar a propagarlo." << endl;
    }
    else{
        cout << left << setw(width) << "¿Es flamable?: " << left << "Al ser un líquido el bloque no será afectado por el fuego." << endl;
    }
    
    if(liquido.getLuminoso() == 1){
        cout << left << setw(width) << "¿Produce luz?: " << left << "Este bloque tiene la capacidad de producir luz." << endl;
    }
    else{
        cout << left << setw(width) << "¿Produce luz?: " << left << "Este bloque no emite ningún tipo de luz." << endl;
    }
    
    if(liquido.getTransparente() == 1){
        cout << left << setw(width) << "¿Es transparente?: " << left << "Este bloque permite el paso de la luz." << endl;
    }
    else{
        cout << left << setw(width) << "¿Es transparente?: " << left << "Este bloque no permitirá que la luz lo atraviese." << endl;
        }
    
    cout << left << setw(width) << "Distancia de Propagación: " << left << liquido.getPropagacion() << endl;
    
    cout << left << "Propiedades: " << endl << liquido.getPropiedades() << endl;
    
    cout << endl << endl;
}

/**
 * Utiliza el objeto de tipo mineral para mostrar su información en pantalla.
 *
 * @param Mineral mineral: es el objeto de tipo mineral que utiliza la función para llamar la información que contenga.
 * @return 
 */
void WikiData::obtenerInformacionBloque(Mineral mineral){
    int width = 36;
    
    cout << mineral.getNombre() << endl << endl;
    cout << left << setw(width) << "Id Númerico: " << left << mineral.getIdNumerico() << endl;
    cout << left << setw(width - 1) << "Id del Nombre: " << left << mineral.getIdNombre() << endl;
    cout << left << setw(width - 1) << "Nombre: " << left << mineral.getNombre() << endl;
    
    if(mineral.getInteractuable() == 1){
        cout << left << setw(width) << "¿Interactuable?: " << left << "Se puede interactuar con este bloque." << endl;
    }
    else{
        cout << left << setw(width) << "¿Interactuable?: " << left << "No se puede interactuar con este bloque." << endl;
    }
    
    if(mineral.getPuedeRomperse() == 1){
        cout << left << setw(width) << "¿Puede romperse?: " << left << "Este bloque puede ser roto siempre " << 
        "que se tenga la herramienta correcta." << endl;
    }
    else{
        cout << left << setw(width) << "¿Puede romperse?: " << left << "Este bloque es irrompible, por lo tanto solo " <<
        "podrá romperse mediante creativo." << endl;
    }
    
    cout << left << setw(width + 1) << "¿Obtención?: " << left << mineral.getObtencion() << endl;
    
    if(mineral.getCrafteable() == 1){
        cout << left << setw(width) << "¿Crafteable?: " << left << "Este bloque puede craftearse." << endl;
    }
    else{
        cout << left << setw(width) << "¿Crafteable?: " << left << "Este bloque no puede ser crafteado." << endl;
    }
    
    if(mineral.getDanno() == 0){
        cout << left << setw(width + 1) << "¿Produce daño al jugador?: " << left << "Este bloque no ocasionará daño al jugador " <<
        "de manera general." << endl;
    }
    else{
        cout << left << setw(width + 1) << "¿Produce daño al jugador?: " << left << "Este bloque puede ocasionar daño al " <<
        "jugador sí se esta en contacto." << endl;
    }
    
    if(mineral.getObedeceGravedad() == 0){
        cout << left << setw(width) << "¿Es afectado por la gravedad?: " << left << "Este bloque no será afectado si rompes " <<
        "su bloque de soporte." << endl;
    }
    else{
        cout << left << setw(width) << "¿Es afectado por la gravedad?: " << left << "Este bloque sufrirá cambios si rompes el " <<
        "bloque que lo soporta" << endl;
    }
    
    if(mineral.getFlamable() == 1){
        cout << left << setw(width) << "¿Es flamable?: " << left << "Este bloque puede prenderse en fuego al estar en proximidad " <<
        "de lava o fuego, y puede ayudar a propagarlo." << endl;
    }
    else{
        cout << left << setw(width) << "¿Es flamable?: " << left << "Este bloque no desaparecerá ni será consumido al ser afectado "
        << "por fuego o lava." << endl;
    }
    
    if(mineral.getLuminoso() == 1){
        cout << left << setw(width) << "¿Produce luz?: " << left << "Este bloque tiene la capacidad de producir luz." << endl;
    }
    else{
        cout << left << setw(width) << "¿Produce luz?: " << left << "Este bloque no emite ningún tipo de luz." << endl;
    }
    
    if(mineral.getTransparente() == 1){
        cout << left << setw(width) << "¿Es transparente?: " << left << "Este bloque permite el paso de la luz." << endl;
    }
    else{
        cout << left << setw(width) << "¿Es transparente?: " << left << "Este bloque no permitirá que la luz lo atraviese." << endl;
        }
    
    cout << left << setw(width) << "¿Drops?: " << left << mineral.getDrop() << endl;
    
    cout << left << setw(width + 1) << "Localización de generación: " << left << mineral.getLocalizacion() << endl;
    
    cout << endl << endl;
}

/**
 * Busca el bloque que posea el ID dado entre los arreglos de los "bloques", "liquidos" y "minerales" mediante ciclos for
 * y el uso de los índices.
 * 
 * Después utiliza la función obtenerInformacionBloque() para mostrar todos los datos en pantalla.
 * Si no se encuentra notifica al usuario.
 *
 * @param float identifier: utiliza el ID númerico del bloque que debe buscar
 * @return 
 */
void WikiData::encontrarEnListaDeBloques(float identifier){
    bool encontrado = false;
    
    for(int i = 0; i <= indiceBloques; i++){
        if(bloques[i].getIdNumerico() == identifier) {obtenerInformacionBloque(bloques[i]); encontrado = true;}
    }
    
    for(int i = 0; i <= indiceLiquidos; i++){
        if(liquidos[i].getIdNumerico() == identifier) {obtenerInformacionBloque(liquidos[i]); encontrado = true;}
    }
    
    for(int i = 0; i <= indiceMinerales; i++){
        if(minerales[i].getIdNumerico() == identifier) {obtenerInformacionBloque(minerales[i]); encontrado = true;}
    }
    
    if(encontrado == false){
        cout << "\nEl bloque que deseas buscar no fue encontrado." << endl <<
        "Tip: Revisa que hayas escrito el número correctamente." << endl << endl;
    }
}


#endif