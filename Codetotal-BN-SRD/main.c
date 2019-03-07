#include <stdio.h>

//Fonction affichage de la grille:
void Affgrille() {


}

int main() {
    //Espaces declarations de variables:
    int choixhelp;  //choix d'afficher l'aide ou pas, avec 0 ou 1.


    printf("Jeu de la bataille Navale.\n"
           "Voulez-vous apprendre à jouer ? (tapez 1 pour oui ou 0 pour non): ");
    scanf("%d", &choixhelp);

    switch (choixhelp) {
        default:
            while (choixhelp) {
                printf("Eh, il faut écrire 0 ou 1 !!! On vous demande pas la lune quand même… ");
                scanf("%d", &choixhelp);
            }
        case 0:
            printf("« Parfait, pas besoin de se fatiguer à vous apprendre comment faire ! Bonne chance d’avance et bonne partie !");
        case 1:
            //Afficher la grille:
            Affgrille();
            //Afficher l'aide:
            printf("\"LA GRILLE VIDE ICI.\"\n"
                   "\n"
                   "Jeu de la bataille Navale.\n"
                   "Voulez-vous apprendre à jouer ? \n"
                   "Oui\n"
                   "Vous êtes sur un jeu de bataille navale.\n"
                   "Voici les règles du jeu :\n"
                   "Le but : Couler tous les bateaux adverses placés quelque part en mer (sur le plateau de jeu de 64 cases), avec des explosifs.\n"
                   "Il y a trois bateaux : de 2, 3, et 4 cases de long. Les bateaux ne sont pas l’un à côté de l’autre.\n"
                   "Pour essayer de toucher les bateaux, vous devez entrez \n"
                   "la coordonnée de la case où vous voulez lancer un explosif (exemple, A5), puis tapez enter.\n"
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


    }

    return 0;
}