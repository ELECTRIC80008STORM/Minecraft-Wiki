#include <iostream>

using namespace std;

class Bloque{
    private:
    string nombre_tecnico;
    string tipo_de_bloque;
    bool puede_romperse;

    public:
    Bloque(){
        nombre_tecnico = "";
        tipo_de_bloque = "";
        puede_romperse = 0;
    }

    Bloque(string nt, string tdb, bool pr):\
    nombre_tecnico(nt), tipo_de_bloque(tdb), puede_romperse(pr){}

    string getNombre_tecnico();
    string getTipo_de_bloque();
    bool getPuede_romperse();
};

string Bloque::getNombre_tecnico(){
    cout << "Su nombre es: " << nombre_tecnico << endl;
    return nombre_tecnico;
}

string Bloque::getTipo_de_bloque(){
    cout << "Tipo: " << tipo_de_bloque << endl;
    return tipo_de_bloque;
}

bool Bloque::getPuede_romperse(){
    if(puede_romperse == true){
        cout << "Sí puede romperse.\n\n";
    }
    else{
        cout << "No puede romperse.\n\n";
    }
    return puede_romperse;
}