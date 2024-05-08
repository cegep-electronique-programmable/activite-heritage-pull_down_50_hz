#include <iostream>
using namespace std;

class etudiant {
    double numeroMatricule;
    int moyenne;
	
public:
    etudiant(double);
    double getMatricule();
    void setMoyenne(int);
    int getMoyenne();
};


etudiant::etudiant(double nouveauMatricule){
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
    

int main() {
    printf("Hello world !\n\r\n\r");
    etudiant etudiant147(147);
    etudiant147.setMoyenne(100);
    printf("Etudiant147, matricule # %d, moyenne %d", etudiant147.getMatricule(), etudiant147.getMoyenne());
    
    return 0;
} 