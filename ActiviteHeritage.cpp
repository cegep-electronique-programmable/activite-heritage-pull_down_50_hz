//Compilateur en ligne recommandÃ©: https://www.tutorialspoint.com/compile_cpp_online.php 

#include <iostream>
using namespace std;

class vehicule {
//membres privÃ©s par dÃ©faut
    double vitesse;
    int nbre_passagers;
	
public:
    // Fonction remplace le constructeur.
    void init_vehicule(double v,int np) 
    {
        vitesse = v;
        nbre_passagers = np;
    }
    
    // Pour afficher les membres private.
    void affiche() {
        cout << "vitesse: " << vitesse << \
        " ; nbre_passagers: " << nbre_passagers << endl;
    }
}; 

int main() {
    
    return 0;
} 