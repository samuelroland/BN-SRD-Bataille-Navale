/*
 * Projet Bataille Navale. Module MA-20.
 * Samuel Roland
 * Date début du code: 7.03.2019
 * Date fin du code: xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
 */

#include <stdio.h>
#include <windows.h>

#pragma execution_character_set( "utf-8" )

#define DIMENSIONSTABLEAU 8 //dimensions du tableaux: 8*8 cases.

//TOUS LES SYMBOLES SPéCIAUX:
//TABLEAU DOUBLE-BANDE:
#define DTLC 201 // ╔, Double Top Left Corner
#define DTRC 187 // ╗, Double Top Right Corner
#define DBLC 200 // ╚, Double Bottom Left Corner
#define DBRC 188 // ╝, Double Bottom Right Corner
#define DVSB 186 // ║, Double Vertical Simple Border
#define DVRB 185 // ╣, Double Vertical Right Border
#define DVLB 204 // ╠, Double Vertical Left Border
#define DHSB 205 // ═, Double Horizontal Simple Border
#define DHBB 202 // ╩, Double Horizontal Bottom Border
#define DHTB 203 // ╦, Double Horizontal Top Border
#define DC   206 // ╬, Double Center

//Symboles sur la grille:
#define cazblanc 254    //caractère case blanche. ■

//Variables globales:
int typegrille;

int grilleexemple[8][8] = {     //Grille définie slt pour l'aide.
        12, 12, 0, 0, 0, 0, 1, 0,
        0, 0, 0, 13, 0, 0, 0, 0,
        0, 0, 0, 13, 0, -1, 0, 0,
        0, 0, 0, 13, 0, 0, 0, 0,
        0, -1, 0, 0, 0, 0, -1, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 2, 2
};

int grillejeu[8][8] = {     //Grille pour le jeu
        2, 2, 0, 0, 0, 0, 1, 0,
        0, 0, 0, 3, 0, 0, 0, 0,
        0, 0, 0, 3, 0, -1, 0, 0,
        0, 0, 0, 3, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, -1, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 2, 2
};


void printdataex(int i, int l) {  //i= numero de la ligne. l= numero de la case (en partant de 1 !).
    //SLT pou la grilleexemple !
    switch (grilleexemple[i - 1][l - 1]) {
        case 0:
            printf(" ");
            break;
        case 1:
        case 2:
        case 3:
            printf("O");
            break;
        case -1:    //Eau donc X
            printf("X");
            break;
        case 11:
        case 12:
        case 13:
            printf("%c", cazblanc);
    }
}

void printdatajeu(int i, int l) {  //i= numero de la ligne. l= numero de la case (en partant de 1 !).
    //SLT pou la grillejeu !
    switch (grillejeu[i - 1][l - 1]) {
        case 0:
            printf(" ");
            break;
        case 1:
        case 2:
        case 3:
            printf("O");
            break;
        case -1:    //Eau donc X
            printf("X");
            break;
        case 11:
        case 12:
        case 13:
            printf("%c", cazblanc);
    }
}

//Sous-fonctions pour la grille:
void traits3horiz() {
    printf("%c%c%c", DHSB, DHSB, DHSB);
}

//Lignes début et fin:
void lignesuperieurgrille(int Dimensions) {
    printf("   %c", DTLC);
    for (int a = 1; a < Dimensions; a++) {   //Faire 7 fois: ═ ═ ═ ╦
        traits3horiz();
        printf("%c", DHTB);
    }
    traits3horiz();
    printf("%c\n", DTRC);
}

void ligneinferieurgrille(int Dimensions) {
    printf("   %c", DBLC);
    for (int a = 1; a < Dimensions; a++) {   //Faire 7 fois: ═ ═ ═ ╩
        traits3horiz();
        printf("%c", DHBB);
    }
    traits3horiz();
    printf("%c\n", DBRC);
}

//Lignes entre deux:
void lignedonneegrille(int i, int Dimensions) {
    int l = 1;    //numero de case.

    printf(" %d %c ", i, DVSB);    // ça fera ça ║
    for (int b = 1; b < Dimensions; b++) {
        //Si 0 alors grille d'exemple de l'aide. Si 1 alors grille de jeu.
        if (typegrille == 0) {
            printdataex(i, l);
        } else {
            printdatajeu(i, l);
        }

        printf(" %c ", DVSB);
        l++;
    }
    if (typegrille == 0) {
        printdataex(i, l);
    } else {
        printdatajeu(i, l);
    }
    printf(" %c\n", DVSB);


}

void lignemilieugrille(int Dimensions) {
    printf("   %c", DVLB);
    for (int a = 1; a < Dimensions; a++) {   //Faire 7 fois: ═ ═ ═ ╦
        traits3horiz();
        printf("%c", DC);
    }
    traits3horiz();
    printf("%c\n", DVRB);
}

//Fonction affichage de la grille:
void Affgrille2() {  //autre manière de faire la fonction.
    SetConsoleOutputCP(65001); // For accented characters
    SetConsoleOutputCP(437); // For semi-graphic characters
    if (typegrille==1){
        printf("PARTIE EN COURS - BATAILLE NAVALE\n");
    }
    //premiere ligne de lettre:
    printf("     A   B   C   D   E   F   G   H\n"); //écrite en dur, 5 espaces avant.
    lignesuperieurgrille(DIMENSIONSTABLEAU);
    for (int row = 0; row < DIMENSIONSTABLEAU; row++) {
        if (row > 0) {
            lignemilieugrille(DIMENSIONSTABLEAU);
        }
        lignedonneegrille(row + 1, DIMENSIONSTABLEAU);
    }
    ligneinferieurgrille(DIMENSIONSTABLEAU);

    //partie légende des symboles:
    SetConsoleOutputCP(65001); // For accented characters
    printf("   Légendes:\n"
           "   X = A l'eau\n"
           "   O = Touché (bateau)\n"
           "   ■ = Coulé (le bateau est touché en entier)\n");
}
void tirerunecase(){
    char hits[2];   //deux cases pour les coups.
    printf("Entrez une case: ");
    scanf("%c%c", hits[0],hits[1]);
    hits[0]-=35;
    //pour test provisoire: possible de prendre un numero en char pour un int ?
    printf("%d", grillejeu[hits[0]][hits[1]]);

}

int main() {
    SetConsoleOutputCP(65001); // For accented characters
    SetConsoleOutputCP(437); // For semi-graphic characters

    //Espaces declarations de variables:
    char choixhelp[5];  //choix d'afficher l'aide ou pas, avec 0 ou 1.

    SetConsoleOutputCP(65001); // For accented characters
    printf("Jeu de la bataille Navale.\n"
           "Voulez-vous apprendre à jouer ? (tapez 1 pour oui ou 0 pour non): ");
    scanf("%s", &choixhelp);

    //Vérification du nombre si différent de 1 et 0:
    while ((choixhelp[0] != '1') && (choixhelp[0] != '0')) {
        SetConsoleOutputCP(65001); // For accented characters
        printf("Eh, il faut écrire 0 ou 1 !!! On vous demande pas la lune quand même… ");
        scanf("%s", &choixhelp);
    }

    switch (choixhelp[0]) {
        case '0':
            SetConsoleOutputCP(65001); // For accented characters
            printf("\n\nParfait, pas besoin de se fatiguer à vous apprendre comment faire ! Bonne chance d’avance et bonne partie !");
            break;
        case '1':
            system("cls");
            printf("Bataille Navale – Apprendre à jouer\n\n");
            printf("Voici une grille de jeu en cours, pour exemple:\n");
            typegrille = 0;
            Affgrille2();
            //Afficher l'aide:
            SetConsoleOutputCP(65001); // For accented characters
            printf("\n\nVous êtes sur un jeu de bataille navale.\n"
                   "Voici les règles du jeu :\n"
                   "Le but : Couler tous les bateaux adverses placés quelque part en mer (sur le plateau de jeu de 64 cases), avec des explosifs.\n"
                   "Il y a trois bateaux : de 2, 3, et 4 cases de long par défaut. Les bateaux ne sont pas l’un à côté de l’autre.\n"
                   "Pour essayer de toucher les bateaux, vous devez entrez la coordonnée de la case où vous voulez lancer un explosif (exemple, A5), puis tapez enter.\n"
                   "\n"
                   "Si le programme affiche « A l’eau », vous n’avez pas touché de bateau, une croix s’affiche dans la case. \n"
                   "\n"
                   "Si le programme affiche « Touché », c’est que vous avez touché un bateau. La case se remplit d’un carré.\n"
                   "\n"
                   "Si le programme affiche « Touché et coulé », ça signifie que le bateau entier à été touché et qu’il est coulé.\n"
                   "Vous devez ensuite cherchez les autres bateaux.\n"
                   "\n"
                   "Si vous retestez une case que vous avez déjà testée, le programme vous avertira et vous laissera recommencer.\n"
                   "\n"
                   "Une fois que vous avez touché les 3 bateaux, un message s’affiche vous annonçant que vous avez gagné.");
            break;
        default:
            printf("\nEh, il faut écrire 0 ou 1 !!! On vous demande pas la lune quand même…");
    }
    printf("\nTapez une touche pour quitter l’aide …");
    getchar();
    getchar();

    //PARTIE JEU:
    typegrille=1;   //Il n'y aura plus que des grilles de jeu !
    printf("Tapez une touche pour commencer la partie: ");
    getchar();

    //Tirer une case:
    tirerunecase();

    return 0;
}