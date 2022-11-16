#include <iostream>

using namespace std;

class Cristal{
    private:
    string nombre_tecnico;
    string tipo_de_bloque;
    bool puede_romperse;
    string color_del_cristal;
    bool dejar_pasar_luz;

    public:
    Cristal(){
        nombre_tecnico = "";
        tipo_de_bloque = "";
        puede_romperse = 0;
        color_del_cristal = "";
        dejar_pasar_luz = false;
    }

    Cristal(string nt, string tdb, bool pr, string cdc, bool dpl):\
    nombre_tecnico(nt), tipo_de_bloque(tdb), puede_romperse(pr), color_del_cristal(cdc), dejar_pasar_luz(dpl){}

    string getNombre_tecnico();
    string getTipo_de_bloque();
    bool getPuede_romperse();
    string getColor_del_cristal();
    void setDejar_pasar_luz(bool);
};

string Cristal::getNombre_tecnico(){
    cout << "Su nombre es: " << nombre_tecnico << endl;
    return nombre_tecnico;
}

string Cristal::getTipo_de_bloque(){
    cout << "Tipo: " << tipo_de_bloque << endl;
    return tipo_de_bloque;
}

bool Cristal::getPuede_romperse(){
    if(puede_romperse == true){
        cout << "Sí puede romperse.\n\n";
    }
    else{
        cout << "No puede romperse.\n\n";
    }
    return puede_romperse;
}

string Cristal::getColor_del_cristal(){
    cout << "Es de color: " << color_del_cristal << "\n\n";
    return color_del_cristal;
}

void Cristal::setDejar_pasar_luz(bool ans){
    dejar_pasar_luz = ans;
};