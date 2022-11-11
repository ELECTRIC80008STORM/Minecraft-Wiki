#include <iostream>

using namespace std;

class Cristal{
    private:
    string nombre_tecnico;
    string color_del_cristal;

    public:
    Cristal(){
        nombre_tecnico = "";
        color_del_cristal = "";
    }

    Cristal(string nt, string cdc): nombre_tecnico(nt), color_del_cristal(cdc){}

    string getNombre_tecnico();
    string getColor_del_cristal();
};

string Cristal::getNombre_tecnico(){
    cout << "Su nombre es: " << nombre_tecnico << endl;
    return nombre_tecnico;
}

string Cristal::getColor_del_cristal(){
    cout << "Es de color: " << color_del_cristal << "\n\n";
    return color_del_cristal;
}