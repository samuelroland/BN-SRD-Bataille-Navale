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
int compteurcoups = 0;    //compte le nombre de coups avant de gagner.

int grilleexemple[8][8] = {     //Grille définie slt pour l'aide.
        22, 22, 0, 0, 0, 0, 11, 0,
        0, 0, 0, 23, 0, 0, 0, 0,
        0, 0, 0, 23, 0, -1, 0, 0,
        0, 0, 0, 23, 0, 0, 0, 0,
        0, -1, 0, 0, 0, 0, -1, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 22, 2
};

int grillejeu[8][8] = {     //Grille pour le jeu
        0, 0, 0, 0, 0, 0, 1, 0,
        0, 0, 0, 3, 0, 0, 0, 0,
        0, 0, 0, 3, 0, 0, 0, 0,
        0, 0, 0, 3, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
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
            printf(" ");
            break;
        case -1:    //Eau donc X
            printf("X");
            break;
        case 11:
        case 12:
        case 13:
            printf("O");
            break;
        case 21:
        case 22:
        case 23:
            printf("%c", cazblanc);
            break;
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
            printf(" ");
            break;
        case -1:    //Eau donc X
            printf("X");
            break;
        case 11:
        case 12:
        case 13:
            printf("O");
            break;
        case 21:
        case 22:
        case 23:
            printf("%c", cazblanc);
            break;
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
    if (typegrille == 1) {
        system("cls");
        SetConsoleOutputCP(65001); // For accented characters
        printf("Bataille Navale – Partie en cours\n\n");
    }
    //premiere ligne de lettre:
    SetConsoleOutputCP(437); // For semi-graphic characters
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

int result = -2; //-2=pas de résultat, -1=déja tiré ici, 0=a l'eau, 1=touché, 2=touché coulé.
char hits[2];   //deux cases pour les coups.
int batotouches[4] = {0, 0, 0, 0};    //Cases touchées par bateaux:    0=inutile! donc 4 cases.
int compt_batotouches = 0;  //compteur de bateaux touchés. dès que =3 alors victoire.

void tirerunecase() {
    int typbato;   //type du bateau: 1 ou 2 ou 3 !

    printf("\nEntrez une case: ");
    //prendre la case et verifier la valeur:
    do {
        scanf("%s", &hits);
        if ((hits[0] < 65) || (hits[0] > 72) || (hits[1] < 49) || (hits[1] > 56)) {
            printf("Cette valeur ne correspond pas à une case ! Recommencez: ");
        }
    } while ((hits[0] < 65) || (hits[0] > 72) || (hits[1] < 49) || (hits[1] > 56));

    //transformation pour le tableau de 8*8 de 0 à 7:
    hits[0] -= 65;
    hits[1] -= 49;
    //Traitement du tir, slt dans le modèle. Affichage du résultat avec resultaff().
    switch (grillejeu[hits[1]][hits[0]]) {
        case -1:
            //déja tiré ici:
            result = -1;
            break;
        case 0:
            //A l'eau !
            grillejeu[hits[1]][hits[0]] = -1;
            compteurcoups++;
            result = 0;
            break;
        case 1:
        case 2:
        case 3:
            //de toute facon en tous cas touché:
            typbato = grillejeu[hits[1]][hits[0]];
            grillejeu[hits[1]][hits[0]] += 10;
            batotouches[grillejeu[hits[1]][hits[0]] - 10]++;
            compteurcoups++;
            //Coulé ??
            if (typbato == batotouches[typbato]) {
                //Mise à jour +10, pour tous les cases du bateau, pour arriver à 21, 22, 23:
                for (int row = 0; row < DIMENSIONSTABLEAU; row++) {
                    for (int col = 0; col < DIMENSIONSTABLEAU; col++) {
                        if (grillejeu[row][col] == typbato + 10) {
                            grillejeu[row][col] += 10;
                        }
                    }
                }
                result = 2; //donc touché + coulé
                compt_batotouches++;
            } else {
                //Si pas touché et coulé, alors slt Touché !
                result = 1;
            }
            break;
        case 11:
        case 12:
        case 13:
        case 21:
        case 22:
        case 23:
            //déja tiré ici:
            result = -1;
            break;
        default:
            break;
    }
}

void resultaff() {
    printf("\nPour %c%c: ", hits[0] + 65, hits[1] + 49);
    switch (result) {
        case -2:
            //Ne rien faire.
            break;
        case -1:
            printf("Déjà tiré ici ! Refaites votre choix… ");
            break;
        case 0:
            printf("A l'eau ...");
            break;
        case 1:
            printf("Touché ! ");
            break;
        case 2:
            //wip couler
            printf("Touché et coulé ! ");
            break;
    }
}

void affvictoire() {
    printf("\n"
           "\n"
           " /$$    /$$ /$$             /$$               /$$                           /$$\n"
           "| $$   | $$|__/            | $$              |__/                          | $$\n"
           "| $$   | $$ /$$  /$$$$$$$ /$$$$$$    /$$$$$$  /$$  /$$$$$$   /$$$$$$       | $$\n"
           "|  $$ / $$/| $$ /$$_____/|_  $$_/   /$$__  $$| $$ /$$__  $$ /$$__  $$      | $$\n"
           " \\  $$ $$/ | $$| $$        | $$    | $$  \\ $$| $$| $$  \\__/| $$$$$$$$      |__/\n"
           "  \\  $$$/  | $$| $$        | $$ /$$| $$  | $$| $$| $$      | $$_____/          \n"
           "   \\  $/   | $$|  $$$$$$$  |  $$$$/|  $$$$$$/| $$| $$      |  $$$$$$$       /$$\n"
           "    \\_/    |__/ \\_______/   \\___/   \\______/ |__/|__/       \\_______/      |__/\n"
           "                                                                               \n"
           "                                                                               \n"
           "                                                                               \n"
           "");
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
    typegrille = 1;   //Il n'y aura plus que des grilles de jeu !
    printf("Tapez une touche dès que vous êtes prêt à jouer ! ");
    getchar();
    system("cls");
    Affgrille2();

    //Jouer une partie complète:
    while (compt_batotouches != 3) {
        tirerunecase();
        Affgrille2();
        resultaff();
    }
    affvictoire();
    //Si choix des grilles:
    printf("Bravo vous avez gagné en %d coups !  Essayez une autre grille ! Pour cela relancez le programme ! ",
           compteurcoups);
    system("pause");
    return 0;
}