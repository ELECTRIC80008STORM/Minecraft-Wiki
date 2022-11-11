#include <iostream>

using namespace std;

class Madera{
    private:
    string drop;
    string color;
    string tipo_de_madera;

    public:
    Madera(){
        drop = "";
        color = "";
        tipo_de_madera = "";
    }

    Madera(string drp, string cl, string tdm): drop(drp), color(cl), tipo_de_madera(tdm){}

    string getdrop();
    string getColor();
    string getTipo_de_madera(); 
};

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