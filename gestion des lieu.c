#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


int gold = 0;
int PV = 100;
typedef struct Chapter{
    char descr[300];
    int index;
    int gold;
    int PV;
    int id[3];
}chapter;

void travel(chapter * vartravel){
    printf("Description : %s\n", (*vartravel).descr);
    printf("Gain et perte d'or : %d\n", (*vartravel).gold);
    if((gold + (*vartravel).gold)>=0){
    gold += (*vartravel).gold;
    }
    printf("Gain et perte de points de vie : %d\n", (*vartravel).PV);
    if((PV +(*vartravel).PV) >= 0 && (PV +(*vartravel).PV)<100){
    PV += (*vartravel).PV;
    }
    printf("Destinations possibles : %d %d %d\n", (*vartravel).id[0],(*vartravel).id[1],(*vartravel).id[2]);
}


int main(){
    int destination = 0;

    chapter chapter1 = {"Le Château", 1, 5, 15, {7, 6, 2} };
    chapter chapter2 = {"La Forêt", 2, 20, 5, {7, 4, 1} };
    chapter chapter3 = {"Le Roc", 5, 15, -5, {7, 5, 1} };
    chapter chapter4 = {"La Tanière", 4, 50, -30, {1, 6, 2} };
    chapter chapter5 = {"", 3, -30, 10, {3, 6, 2} };

    printf("Vous vous trouvez seul dans le froid, au milieu d'une plaine déserte. Derrière vous, une pierre maculée de sang séché. Vous avez dû vous cogner la tête dessus, mais impossible de vous souvenir de quoi que ce soit... Si ce n'est votre nom. Entrez votre nom ici :\n");
    char nom[20] = { 0 },    /* tableau de 20 caractères pour le nom */
         prenom[20] = { 0 }; /* de même pour le prénom */

    scanf( "%19s", nom ); /* le nom de tableau représentant l'adresse de son premier élément pas besoin d'utiliser l'opérateur d'adressage & */
    printf( "Très bien, %s !\n", nom );

    printf("Votre crâne vous fait encore souffrir, mais vous recouvrez peu à peu votre vue habituelle. Vous remarquez plusieurs endroits qui vous semblent dignes d'intérêt. Où souhaitez-vous aller ?\n");
    printf("(1) Vos yeux vagabondent vers le sentier qui serpente vers l'énorme Château qui trône sur la colline d'en face. Les fenêtres laissent filtrer de fins rayons de lumière : l'endroit semble habité.\n");
    printf("(2) Un autre chemin, plus sinueux, mène vers une forêt, rendue insondable par l'obscurité environnante. Les pins vous dominent de leurs silhouettes menaçantes, et vous percevez le lointain écho des cris des créatures qui la peuplent.\n");
    printf("(3) Un énorme Roc vous surplombe de sa hauteur, grandiose et inquiétant.\n");
    printf("(4) La Tanière laisse échapper une odeur fétide de ses entrailles embrumées.\n");
    printf("(5) Le Manoir, encore endormi, semble vous inviter.\n");

    while(PV>=0){
        scanf("%d", &destination);

        switch (destination){

            case 1 :
                travel(&chapter1);
                printf("Vous vous élancez vers le château, bien déterminé à en rencontrer les occupants. Toutefois, quelque chose ne semble pas tourner rond... \n");
                printf("Il vous reste %d PV\nEt %d pieces d'or\n", PV, gold);
            break;

            case 2 :
                travel(&chapter2);
                printf("Vous avancez d'un pas mal assuré vers la forêt, et vous enfoncez sous le couvert des arbres.  \n");
                printf("Il vous reste %d PV\nEt %d pieces d'or\n", PV, gold);
            break;

            case 3 :
                travel(&chapter3);
                printf("Il vous reste %d PV\nEt %d pieces d'or\n", PV, gold);
            break;

            case 4 :
                travel(&chapter4);
                printf("Il vous reste %d PV\nEt %d pieces d'or\n", PV, gold);
            break;

            case 5 :
                travel(&chapter5);
                printf("Il vous reste %d PV\nEt %d pieces d'or\n", PV, gold);
            break;

        }
    };
    return 0;
}

