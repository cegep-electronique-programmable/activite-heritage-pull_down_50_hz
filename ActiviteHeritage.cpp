#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

class etudiant {
    protected:
        int numeroMatricule;
        int moyenne;

    public:
        void setMatricule(int);
        int getMatricule();
        void setMoyenne(int);
        int getMoyenne();
};

void etudiant::setMatricule(int nouveauMatricule){
    if ((nouveauMatricule >= 100000) && (nouveauMatricule <= 999999)){
        this->numeroMatricule = nouveauMatricule;    
    } else {
        this->numeroMatricule = 0;
    }
}

int etudiant::getMatricule(){
    return this->numeroMatricule;
}

void etudiant::setMoyenne(int nouvelleMoyenne){
    if (nouvelleMoyenne <= 100){
        this->moyenne = nouvelleMoyenne;
    } else {
        this->moyenne = 100;
    }
}

int etudiant::getMoyenne(){
    return this->moyenne;
}

class Cours_SabreLaser : public etudiant {
    protected:
        int note_etudiant;
        int nbr_victoire;
        int nbr_defaite;
        int nbr_egalite;
        int nbr_combat;
        string competance_aquise;
        const char* type_sabrelaser;
        const char* couleur_sabrelaser;
        const char* couleur_lame;
        const char* style_combat;

    public:
        void set_nbr_combat(int nbr_combat){
            this->nbr_combat = nbr_combat;
        }

        int get_nbr_combat(){
            return nbr_combat;
        }

        void set_statistiques(int victoires, int defaites, int egalites) {
            this->nbr_victoire = victoires;
            this->nbr_defaite = defaites;
            this->nbr_egalite = egalites;
            this->nbr_combat = victoires + defaites + egalites;
        }

        int get_victoires() const {
            return nbr_victoire;
        }

        int get_defaites() const {
            return nbr_defaite;
        }

        int get_egalites() const {
            return nbr_egalite;
        }

        double calculer_score() const {
            return nbr_victoire * 3 + nbr_egalite * 1 - nbr_defaite * 2; // Par exemple : 3 points pour une victoire, 1 pour une égalité, -2 pour une défaite
        }

        const char* get_type_sabrelaser() {
            return type_sabrelaser;
        }

        const char* get_couleur_sabrelaser() {
            return couleur_sabrelaser;
        }

        const char* get_couleur_lame() {
            return couleur_lame;
        }

        const char* get_style_combat() {
            return style_combat;
        }

        tuple<const char*, const char*, const char*, const char*> get_profil_cours() {
            return make_tuple(get_type_sabrelaser(), get_couleur_sabrelaser(), get_couleur_lame(), get_style_combat());
        }

        void set_profil_cours(const char* type, const char* couleurSabre, const char* couleurLame, const char* style) {
            type_sabrelaser = type;
            couleur_sabrelaser = couleurSabre;
            couleur_lame = couleurLame;
            style_combat = style;
        }

        tuple<int, int, int, int> get_statistiques() const {
            return make_tuple(nbr_victoire, nbr_defaite, nbr_egalite, nbr_combat);
        }

        void classement_eleve(vector<Cours_SabreLaser>& etudiants) {
    sort(etudiants.begin(), etudiants.end(), [](const Cours_SabreLaser& a, const Cours_SabreLaser& b) {
        return a.calculer_score() > b.calculer_score();
    });

    printf("Classement des étudiants :\n");
    for (size_t i = 0; i < etudiants.size(); ++i) {
        auto [victoires, defaites, egalites, combats] = etudiants[i].get_statistiques();
        auto [type, couleurSabre, couleurLame, styleCombat] = etudiants[i].get_profil_cours();
        printf("\r\nEtudiant %lu: Matricule %d, Score %.2f, Combats %d, Victoires %d, Défaites %d, Égalités %d\n",
               i + 1,
               etudiants[i].getMatricule(),
               etudiants[i].calculer_score(),
               combats,
               victoires,
               defaites,
               egalites);
        printf("\r\nProfil du cours - Type de sabrelaser: %s, Couleur du sabrelaser: %s, Couleur de la lame: %s, Style de combat: %s\n",
               type,
               couleurSabre,
               couleurLame,
               styleCombat);
        // Ajoutez d'autres informations ici si nécessaire
    }
}

};

int main() {
    vector<Cours_SabreLaser> etudiants;

    Cours_SabreLaser etudiant1;
    etudiant1.setMatricule(2134485);
    etudiant1.set_profil_cours("Double-bladed", "Black", "Red", "Aggressive");
    etudiant1.set_statistiques(10, 2, 1); // 10 victoires, 2 défaites, 1 égalité
    etudiants.push_back(etudiant1);

    Cours_SabreLaser etudiant2;
    etudiant2.setMatricule(2134486);
    etudiant2.set_profil_cours("Single-bladed", "Green", "Blue", "Defensive");
    etudiant2.set_statistiques(8, 4, 1); // 8 victoires, 4 défaites, 1 égalité
    etudiants.push_back(etudiant2);

    Cours_SabreLaser etudiant3;
    etudiant3.setMatricule(2134487);
    etudiant3.set_profil_cours("Double-bladed", "Blue", "Yellow", "Balanced");
    etudiant3.set_statistiques(7, 3, 3); // 7 victoires, 3 défaites, 3 égalités
    etudiants.push_back(etudiant3);

    // Classement des étudiants
    etudiant1.classement_eleve(etudiants);

    return 0;
}
