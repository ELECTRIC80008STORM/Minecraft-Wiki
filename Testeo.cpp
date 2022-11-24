#include <iostream>
#include <iomanip>
#include "WikiData.h"

using namespace std;

// Bloque arreglo[3] = {
//     madera_de_roble,
//     madera_de_roble_oscuro,
//     madera_de_abedul
// };

// Bloque madera_de_roble(2.3,"Madera","Madera de Roble",\
// "Puede ser partido con la mano pero la herramienta más eficiente es el hacha",\
// false,false);
// Bloque madera_de_roble_oscuro(1.8,"Madera","Madera de Roble Oscuro",\
// "Puede ser partido con la mano pero la herramienta más eficiente es el hacha",\
// false,false);
// Bloque madera_de_abedul(1,"Madera","Madera de Abedul",\
// "Puede ser partido con la mano pero la herramienta más eficiente es el hacha",\
// false,false);

// /* Requiere del tamaño del arreglo al llamar la función el cual se obtiene mediante
// int tamaño = sizeof(arreglo) / sizeof(float); */
// void organizarListaDeBloques(Bloque arreglo[], int tamaño){
//     Bloque aux;
//     for(int i = 1; i < tamaño; i++){
//         if(arreglo[i].getIdNumerico() < arreglo[i-1].getIdNumerico()){
//             aux = arreglo[i];
//             arreglo[i] = arreglo[i-1];
//             arreglo[i-1] = aux;
//         }
//     }

// };

int main(){
    WikiData brain;
    brain.añadirBloque(1,"stone","Piedra","Puede ser obtenido mediante cualquier tipo de pico.",false,false);
    brain.añadirBloque(1.3,"stone","Diorita","Puede ser obtenido mediante cualquier tipo de pico.",false,false);
    brain.añadirBloque(13,"gravel","Grava",false,true,"Puede ser obtenido de cualquier manera pero la más eficiente es una pala.",false,false,true,false,false,false);
    // brain.añadirLiquido(8,"flowing_water","Agua Fluyente",true,false,true,"Tiene una propagación de 7 bloques.","Sí el jugador permanece mucho tiempo debajo se consumirá su barra de oxígeno.");
    // brain.añadirMineral(14,"gold_ore","Oro","Puede ser obtenido mediante cualquier tipo de pico.","Item de Oro","Entre la capa 10");
    brain.mostrarListaDeBloques();
    return 0;
}