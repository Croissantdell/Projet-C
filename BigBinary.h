#ifndef BIGBINARY_H
#define BIGBINARY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BASE 2

// Structure pour représenter un grand entier binaire
typedef struct {
    int *Tdigits;  // Tableau de bits : Tdigits[0] = bit de poids fort
    int Taille;    // Nombre de bits significatifs
    int Signe;     // +1 pour positif, -1 pour négatif, 0 pour nul
} BigBinary;

// Fonctions de création et initialisation
BigBinary initBigBinary(int taille, int signe);
BigBinary creerBigBinaryDepuisChaine(const char *chaine);
void libereBigBinary(BigBinary *nb);

// Fonctions d'affichage
void afficheBigBinary(BigBinary nb);

// Fonctions de comparaison
bool Egal(BigBinary A, BigBinary B);
bool Inferieur(BigBinary A, BigBinary B);

// Opérations arithmétiques
BigBinary Addition(BigBinary A, BigBinary B);
BigBinary Soustraction(BigBinary A, BigBinary B);

// Fonction utilitaire
void divisePar2(BigBinary *nb);

#endif
