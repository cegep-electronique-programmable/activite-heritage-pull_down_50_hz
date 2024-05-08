#include <iostream>
using namespace std;

class etudiant {
    double numeroMatricule;
    int moyenne;
	
public:
    double getMatricule();
    void setMoyenne(int);
    int getMoyenne();
    void etudiantsetMatricule(double);
};

void etudiant::etudiantsetMatricule(double nouveauMatricule){
    //Le numÃ©rod de matricule doit nÃ©cessairement avoir 6 chiffres
    if ((nouveauMatricule >= 100000) && (nouveauMatricule <= 999999)){
        this->numeroMatricule = nouveauMatricule;    
    }
    else{
        this->numeroMatricule = 0;
    }
}

double etudiant::getMatricule(void){
    return (this->moyenne);
}

void etudiant::setMoyenne(int nouvelleMoyenne){
    if (nouvelleMoyenne <= 100){
        this->moyenne = nouvelleMoyenne;
    }
    else{
        this->moyenne = 100;
    }
}

int etudiant::getMoyenne(void){
    return (this->numeroMatricule);
}
//classe de mon cours de sabre laser
class Cours_SabreLaser:public etudiant
{
    private:
        int note_etudiant;
        int nbr_victoire;
        int nbr_defaite;
        int nbr_egalite;
        int nbr_combat;
        const char* competance_aquise;
        void classement_eleve(int,int,int,int);
    
    public:
        const char* type_sabrelaser;
        const char* couleur_sabrelaser;
        const char* couleur_lame;
        const char* style_combat;
        void set_nbr_combat(int nbr_combat){
        this -> nbr_combat = nbr_combat;
        }
        int get_nbr_combat(){return nbr_combat;}
};
    

int main() {
    printf("Hello world !\n\r\n\r");
    Cours_SabreLaser etudiant147;
    etudiant147.etudiantsetMatricule(147);
    etudiant147.setMoyenne(100);
    printf("Etudiant147, matricule # %d, moyenne %d", etudiant147.getMatricule(), etudiant147.getMoyenne());
    
    etudiant147.set_nbr_combat(10);
    printf ("\rEtudiant147 a fait %d combat", etudiant147.get_nbr_combat());
    
    
    return 0;
} 