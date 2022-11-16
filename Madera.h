#include <iostream>

using namespace std;

class Madera{
    private:
    string nombre_tecnico;
    string tipo_de_bloque;
    bool puede_romperse;
    string drop;
    string color;
    string tipo_de_madera;

    public:
    Madera(){
        nombre_tecnico = "";
        tipo_de_bloque = "";
        puede_romperse = 0;
        drop = "";
        color = "";
        tipo_de_madera = "";
    }

    Madera(string nt, string tdb, bool pr, string drp, string cl, string tdm):\
    nombre_tecnico(nt), tipo_de_bloque(tdb), puede_romperse(pr), drop(drp), color(cl), tipo_de_madera(tdm){}

    string getNombre_tecnico();
    string getTipo_de_bloque();
    bool getPuede_romperse();
    string getdrop();
    string getColor();
    string getTipo_de_madera(); 
};

string Madera::getNombre_tecnico(){
    cout << "Su nombre es: " << nombre_tecnico << endl;
    return nombre_tecnico;
}

string Madera::getTipo_de_bloque(){
    cout << "Tipo: " << tipo_de_bloque << endl;
    return tipo_de_bloque;
}

bool Madera::getPuede_romperse(){
    if(puede_romperse == true){
        cout << "Sí puede romperse.\n\n";
    }
    else{
        cout << "No puede romperse.\n\n";
    }
    return puede_romperse;
}

string Madera::getdrop(){
    cout << "Drop: " << drop << endl;
    return drop;
}

string Madera::getColor(){
    cout << "El color es: " << color << endl;
    return color;
}

string Madera::getTipo_de_madera(){
    cout << "El tipo de madera es: " << tipo_de_madera << "\n\n";
    return tipo_de_madera;
}