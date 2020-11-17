#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//CONSTANTES
const int DEPART=0; //Correspond au minimu du plateau de jeu
const int ARRIVEE=66; //Correspond au maximum du plateau de jeu

const int VALMIN=2; //valeur minimum du jet des deux dés
const int VALMAX=12; //valeur maximum du jet des deux dés

const int MULTIPLE=9; //Correspond à la valeur des cases doublant la valeur
const int EXEPTION=63; //Correspond à la case qui n'aura pas la valeur des dés
const int MORT=58; //Correspond à la case tête de mort quifait un etour au départ


//PROTOTYPES
int RandomD(int jetD);
int plc_db_ou_s(int place, int jetD); //Savoir si placement simple ou double
int sup_ARRV(int place); //Savoir si le joueur doit reculer ou non
int Tt_Mrt(int place); //Condition de la case 58

//corps princiaple du programme
int main()
{
    int place; //Correspond à la position du joueur
    int jetD; // Correspond au jet des dés
    //Initialisation

    place=DEPART;
    jetD=DEPART;

    printf("Lancez les des : ");


     srand(time(0));

    while(place != ARRIVEE){
    //Limite au valeur max et min retirees pour le bon fonctionnement de la boucle
    //Vérifie que place n'a pas atteint 66

        jetD=RandomD(jetD); // obtention d'un nombre aleatoire

        place=plc_db_ou_s(place, jetD); // Savoir si placement simple ou double

        place=sup_ARRV(place); //Condition si place est plus élevé que 66

         place=Tt_Mrt(place); //Condition retour à la case DEPART

         //affichage de la place du joueur
        printf("\nle joueur est sur la case : %d\n",place);

         system("pause");
    }

    printf("\nVICTOIRE");


    return 0;
    }

    int RandomD( int jetD){
    //lancement des deux dés
        jetD= (rand() %
           (VALMAX - VALMIN + 1)) + VALMIN;
        printf("%d \n", jetD);

    return jetD;
}

    int plc_db_ou_s(int place, int jetD){

    //Savoir si placement simple ou double
    place=place+jetD;
    //Changement de position du joueur
    //Celui additionne le rendu des des avec sa place actuelle

    if(((place%MULTIPLE)==0) && (place!=EXEPTION)) {
    //Boucle vérifiant si place est un multiple de 9
    //Si c'est le cas, le joueur se deplace une seconde fois
            place=(place+jetD);
        }
        return place;
}

    int sup_ARRV(int place){
    //Savoir si le joueur doit reculer ou non
    int recul=0;
//Condition si place est plus eleve que 66
    if(place>ARRIVEE){
        recul=place-66;
        place=ARRIVEE-recul;
    }
    return place;
}


    int Tt_Mrt(int place){
    //Condition de la case 58

    if(place==MORT){
        //Condition de la case 58
            place=DEPART;
            printf("Retour a la case depart");
        }
        return place;
}
