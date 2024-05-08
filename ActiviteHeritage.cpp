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

// avion hÃ©rite publiquement de vÃ©hicule.
class avion:public vehicule {
    int nbre_moteurs;

public:
    void init_avion(int nm) 
    {
        nbre_moteurs = nm;
    }
};

// moto hÃ©rite publiquement de vÃ©hicule.
class moto:public vehicule 
{
    double cylindree;

public:
    void init_moto(double cy) 
    {
        cylindree = cy;
    }
};

int main() {
    avion boeing767;
    boeing767.init_avion(2);
    // Fonctions hÃ©ritÃ©es de la classe de base.
    boeing767.init_vehicule(950,200);
    boeing767.affiche(); // affiche: 950, 200 mais pas 2.
    return 0;
} 

/*
int main() {
    avion boeing767;
    boeing767.init_avion(2);
    // Fonctions hÃ©ritÃ©es de la classe de base.
    boeing767.init_vehicule(950,200);
    boeing767.affiche(); // affiche: 950, 200 mais pas 2.
    // Err: accÃ¨s Ã  des donnÃ©es privÃ©es de la classe de base.
    boeing767.nbre_moteurs=4;
    boeing767.vitesse=800;
    // Err: accÃ¨s Ã  des donnÃ©es privÃ©es de la classe dÃ©rivÃ©e.
    boeing767.nbre_passagers=188;
    return 0;
} 
*/