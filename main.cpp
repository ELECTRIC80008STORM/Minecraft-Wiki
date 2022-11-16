//Biblioteca
#include <iostream>
#include "Bloque.h"
#include "Madera.h"
#include "Cristal.h"

using namespace std;

//Código Principal
int main(){
    Bloque tierra("Tierra","Sólido",true);
    tierra.getNombre_tecnico();
    tierra.getTipo_de_bloque();
    tierra.getPuede_romperse();

    Madera roble_oscuro("Tronco de Roble Oscuro", "Madera", true, "Tronco de Roble Oscuro Objeto", "Café Oscuro", "Roble Oscuro");
    roble_oscuro.getdrop();
    roble_oscuro.getColor();
    roble_oscuro.getTipo_de_madera();

    Cristal cristal_tintado_cyan("Cristal Cyan Tintado", "Cristal",true,"Cyan",true);
    cristal_tintado_cyan.getNombre_tecnico();
    cristal_tintado_cyan.getColor_del_cristal();


    return 0;
}