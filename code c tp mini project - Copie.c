

#include<stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char nom[50];
    char numCompte[20];
    char motDePasse[20];
    float solde;
} Compte;

Compte comptes[100];             
int nbComptes = 0;
void chargerComptes() {
    FILE *f = fopen("comptes.txt", "r");
    if (f == NULL) return;
    while (fscanf(f, "%s %s %s %f", comptes[nbComptes].nom, comptes[nbComptes].numCompte,
                  comptes[nbComptes].motDePasse, &comptes[nbComptes].solde) == 4) {
        nbComptes++;
    }
    fclose(f);
}
void sauvegarderComptes() {
    FILE *f = fopen("comptes.txt", "w");
    for (int i = 0; i < nbComptes; i++) {
        fprintf(f, "%s %s %s %.2f\n", comptes[i].nom, comptes[i].numCompte,
                comptes[i].motDePasse, comptes[i].solde);
    }
    fclose(f);
}
void creerCompte() {
    printf("Entrer votre nom : ");
    scanf("%s", comptes[nbComptes].nom);

    printf("Entrer un numero de compte : ");
    scanf("%s", comptes[nbComptes].numCompte);

    printf("Entrer un mot de passe : ");
    scanf("%s", comptes[nbComptes].motDePasse);

    comptes[nbComptes].solde = 0;
    nbComptes++;
    sauvegarderComptes();
    printf("Compte cree avec succes !\n");
}
int chercherIndex(char num[], char mdp[]) {
    for (int i = 0; i < nbComptes; i++) {
        if (strcmp(comptes[i].numCompte, num) == 0 &&
            strcmp(comptes[i].motDePasse, mdp) == 0) {
            return i;
        }
    }
    return -1;
}
void deposerArgent(Compte *c) {
    float montant;
    printf("Montant a deposer : ");
    scanf("%f", &montant);
    c->solde += montant;
    sauvegarderComptes();
    printf("Depot effectue. Nouveau solde : %.2f\n", c->solde);
}
void transfererArgent(Compte *c) {
    char cible[20];
    float montant;
    printf("Entrer numero du compte destinataire : ");
    scanf("%s", cible);
    int index = -1;
    for (int i = 0; i < nbComptes; i++) {
        if (strcmp(comptes[i].numCompte, cible) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Compte non trouve.\n");
        return;
    }
    printf("Montant a transferer : ");
    scanf("%f", &montant);
    if (c->solde >= montant) {
        c->solde -= montant;
        comptes[index].solde += montant;
        sauvegarderComptes();
        printf("Transfert reussi.\n");
    } else {
        printf("Solde insuffisant.\n");
    }
}
void afficherSolde(Compte *c) {
    printf("Votre solde est : %.2f\n", c->solde);
}
void supprimerComptesVides() {
    int i = 0;
    while (i < nbComptes) {
        if (comptes[i].solde == 0) {
            for (int j = i; j < nbComptes - 1; j++) {
                comptes[j] = comptes[j + 1];
            }
            nbComptes--;
        } else {
            i++;
        }
    }
    sauvegarderComptes();
    printf("Comptes vides supprimes.\n");
}
void seConnecter() {
    char num[20], mdp[20];
    printf("Numero de compte : ");
    scanf("%s", num);
    printf("Mot de passe : ");
    scanf("%s", mdp);
    int index = chercherIndex(num, mdp);
    if (index == -1) {
        printf("Echec de connexion.\n");
        return;
    }
    printf("Connecte avec succes.\n");

    int choix;
    do {
        printf("\n1. Deposer argent\n2. Transferer argent\n3. Voir solde\n4. Deconnexion\nVotre choix: ");
        scanf("%d", &choix);
        switch (choix) {
            case 1: deposerArgent(&comptes[index]); break;
            case 2: transfererArgent(&comptes[index]); break;
            case 3: afficherSolde(&comptes[index]); break;
        }
    } while (choix != 4);
}
int main() {
    chargerComptes();
    int choix;
    do {
        printf("\n----- Bienvenue a Notre Banque -----\n");
        printf("1. Creer un compte\n2. Se connecter\n3. Supprimer comptes vides\n4. Quitter\nVotre choix : ");
        scanf("%d", &choix);
        switch (choix) {
            case 1: creerCompte(); break;
            case 2: seConnecter(); break;
            case 3: supprimerComptesVides(); break;
        }
    } while (choix != 4);
    return 0;
}

















