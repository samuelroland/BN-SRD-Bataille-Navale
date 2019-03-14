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


//Sous-fonctions pour la grille:
void traits3horiz() {
    printf("%c%c%c", DHSB, DHSB, DHSB);
}

//Lignes début et fin:
void lignesuperieurgrille() {
    SetConsoleOutputCP(437); // For semi-graphic characters
    printf("   %c", DTLC);
    for (int a = 1; a < DIMENSIONSTABLEAU; a++) {   //Faire 7 fois: ═ ═ ═ ╦
        traits3horiz();
        printf("%c", DHTB);
    }
    traits3horiz();
    printf("%c\n", DTRC);
}

void ligneinferieurgrille() {
    printf("   %c", DBLC);
    for (int a = 1; a < DIMENSIONSTABLEAU; a++) {   //Faire 7 fois: ═ ═ ═ ╩
        traits3horiz();
        printf("%c", DHBB);
    }
    traits3horiz();
    printf("%c\n", DBRC);
}


//Lignes entre deux:
void lignedonneegrille(int i) {
    SetConsoleOutputCP(65001); // For accented characters
    SetConsoleOutputCP(437); // For semi-graphic characters

    printf(" %d %c ", i, DVSB);    // ca fera ca ║

    for (int b = 1; b < DIMENSIONSTABLEAU; b++) {
        //Symbole selon donnée du tableau:
        //.................. * pour test slt:
        printf("*");
        printf(" %c ", DVSB);
    }
    printf("*");
    printf(" %c\n", DVSB);

}

void lignemilieugrille() {
    printf("   %c", DVLB);
    for (int a = 1; a < DIMENSIONSTABLEAU; a++) {   //Faire 7 fois: ═ ═ ═ ╦
        traits3horiz();
        printf("%c", DC);
    }
    traits3horiz();
    printf("%c\n", DVRB);
}

//Fonction affichage de la grille:
void Affgrille() {
    int i = 1;
    //premiere ligne de lettre:
    printf("     A   B   C   D   E   F   G   H\n"); //écrite en dur, 5 espaces avant.

    lignesuperieurgrille();
    for (int c = 1; c < DIMENSIONSTABLEAU; c++) {
        lignedonneegrille(i);
        i++;    //pour le numero avant la ligne.
        lignemilieugrille();
    }
    lignedonneegrille(i);    //c'est la derniere ligne de donnée.
    ligneinferieurgrille();


}

int main() {
    SetConsoleOutputCP(65001); // For accented characters
    SetConsoleOutputCP(437); // For semi-graphic characters

    //Espaces declarations de variables:
    int choixhelp;  //choix d'afficher l'aide ou pas, avec 0 ou 1.

    SetConsoleOutputCP(65001); // For accented characters
    printf("Jeu de la bataille Navale.\n"
           "Voulez-vous apprendre à jouer ? (tapez 1 pour oui ou 0 pour non): ");
    scanf("%d", &choixhelp);

    //Vérification du nombre si différent de 1 et 0:
    while ((choixhelp != 1) && (choixhelp != 0)) {
        SetConsoleOutputCP(65001); // For accented characters
        printf("Eh, il faut écrire 0 ou 1 !!! On vous demande pas la lune quand même… ");
        scanf("%d", &choixhelp);
    }

    switch (choixhelp) {
        case 0:
            SetConsoleOutputCP(65001); // For accented characters
            printf("\n\nParfait, pas besoin de se fatiguer à vous apprendre comment faire ! Bonne chance d’avance et bonne partie !");
            break;
        case 1:

            system("cls");
            printf("Bataille Navale – Apprendre à jouer\n\n");
            Affgrille();
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
    }
    printf("\nTapez une touche pour quitter l’aide …");
    getchar();
    getchar();


    return 0;
}