#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

int main() {
    Node* liste = initialiserListe();
    
    int choix;
    Etudiant e;
    int matricule;
    
    do {
        printf("\n===== MENU GESTION ETUDIANTS =====\n");
        printf("1. Ajouter un etudiant\n");
        printf("2. Afficher la liste\n");
        printf("3. Rechercher un etudiant\n");
        printf("4. Supprimer un etudiant\n");
        printf("5. Modifier un etudiant\n");
        printf("6. Compter les etudiants\n");
        printf("0. Quitter\n");
        printf("Choix : ");
        
        if (scanf("%d", &choix) != 1) {
            printf("Erreur de saisie\n");
            while (getchar() != '\n');
            continue;
        }
        
        switch(choix) {
            case 1:
                printf("Matricule : ");
                if (scanf("%d", &e.matricule) != 1) {
                    printf("Matricule invalide\n");
                    while (getchar() != '\n');
                    break;
                }
                
                printf("Nom : ");
                scanf("%49s", e.nom);
                
                printf("Moyenne : ");
                if (scanf("%f", &e.moyenne) != 1) {
                    printf("Moyenne invalide\n");
                    while (getchar() != '\n');
                    break;
                }
                
                if (e.moyenne < 0 || e.moyenne > 20) {
                    printf("Moyenne invalide (doit etre entre 0 et 20)\n");
                    break;
                }
                
                if (rechercher(liste, e.matricule)) {
                    printf("Erreur : Un etudiant avec ce matricule existe deja\n");
                    break;
                }
                
                liste = ajouterFin(liste, e);
                printf("Etudiant ajoute avec succes\n");
                break;
                
            case 2:
                afficherListe(liste);
                break;
                
            case 3:
                printf("Matricule a rechercher : ");
                if (scanf("%d", &matricule) == 1) {
                    if(rechercher(liste, matricule))
                        printf("Etudiant trouve\n");
                    else
                        printf("Non trouve\n");
                }
                break;
                
            case 4:
                printf("Matricule a supprimer : ");
                if (scanf("%d", &matricule) == 1) {
                    liste = supprimer(liste, matricule);
                }
                break;
                
            case 5:
                printf("Matricule a modifier : ");
                if (scanf("%d", &matricule) == 1) {
                    liste = modifier(liste, matricule);
                }
                break;
                
            case 6:
                printf("Nombre total d'etudiants : %d\n", compter(liste));
                break;
                
            case 0:
                printf("Au revoir !\n");
                break;
                
            default:
                printf("Choix invalide, veuillez reessayer\n");
        }
        
    } while(choix != 0);
    
    libererListe(liste);
    return 0;
}  