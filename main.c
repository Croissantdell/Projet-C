/**
 * =============================================================================
 * main.c - Programme principal avec interface interactive
 * =============================================================================
 * 
 * ESIEA - Projet S5 Language C (2025-2026)
 * Projet BigBinary: Manipulation de grands entiers binaires
 * 
 * Ce programme propose:
 *   1. Une interface menu pour tester interactivement les fonctionnalités
 *   2. Des tests automatiques pour valider chaque phase
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BigBinary.h"

#define MAX_INPUT 1024  // Taille max pour les entrées utilisateur

/* =============================================================================
 * FONCTIONS D'AFFICHAGE
 * ============================================================================= */

void afficherLigne(void) {
    printf("------------------------------------------------------------\n");
}

void afficherSeparateur(void) {
    printf("============================================================\n");
}

void afficherTitre(const char *titre) {
    afficherSeparateur();
    printf("         %s\n", titre);
    afficherSeparateur();
}

void afficherMenu(void) {
    printf("\n");
    afficherTitre("MENU PRINCIPAL");
    printf("\n");
    printf("  [1] Tests automatiques Phase 1 (Base)\n");
    printf("  [2] Tests automatiques Phase 2 (Avancee)\n");
    printf("  [3] Tests automatiques Phase 3 (RSA Bonus)\n");
    printf("  [4] Tous les tests automatiques\n");
    printf("\n");
    printf("  --- Mode Interactif ---\n");
    printf("  [5] Addition (A + B)\n");
    printf("  [6] Soustraction (A - B)\n");
    printf("  [7] Comparaison (A == B, A < B)\n");
    printf("  [8] PGCD (Euclide binaire)\n");
    printf("  [9] Modulo (A mod B)\n");
    printf("  [10] Multiplication Egyptienne (A * B)\n");
    printf("  [11] Exponentiation Modulaire (A^e mod N)\n");
    printf("  [12] RSA Chiffrement/Dechiffrement\n");
    printf("\n");
    printf("  [0] Quitter\n");
    printf("\n");
    afficherLigne();
    printf("Votre choix: ");
}

// Lit un nombre binaire depuis l'entrée utilisateur
BigBinary lireBigBinary(const char *prompt) {
    char buffer[MAX_INPUT];
    printf("%s", prompt);
    if (scanf("%s", buffer) != 1) {
        return creerBigBinaryZero();
    }
    return creerBigBinaryDepuisChaine(buffer);
}

// Lit un entier unsigned depuis l'entrée
unsigned int lireUnsignedInt(const char *prompt) {
    unsigned int val;
    printf("%s", prompt);
    scanf("%u", &val);
    return val;
}

/* =============================================================================
 * TESTS AUTOMATIQUES PHASE 1
 * ============================================================================= */

void testerPhase1(void) {
    afficherTitre("PHASE 1: FONCTIONNALITES DE BASE");
    printf("\n");
    
    // Test 1: Création et affichage
    printf("TEST 1: Creation et affichage\n");
    afficherLigne();
    BigBinary a = creerBigBinaryDepuisChaine("1010");  // 10
    BigBinary b = creerBigBinaryDepuisChaine("101");   // 5
    printf("a (10 en decimal) = "); afficheBigBinary(a);
    printf("b (5 en decimal)  = "); afficheBigBinary(b);
    printf("\n");
    
    // Test 2: Addition
    printf("TEST 2: Addition\n");
    afficherLigne();
    BigBinary somme = Addition(a, b);
    printf("a + b = "); afficheBigBinary(somme);
    printf("Attendu: 1111 (15 en decimal)\n\n");
    
    // Test 3: Soustraction
    printf("TEST 3: Soustraction\n");
    afficherLigne();
    BigBinary diff = Soustraction(a, b);
    printf("a - b = "); afficheBigBinary(diff);
    printf("Attendu: 101 (5 en decimal)\n\n");
    
    // Test 4: Comparaison Egal
    printf("TEST 4: Comparaison Egal\n");
    afficherLigne();
    BigBinary c = creerBigBinaryDepuisChaine("1010");
    printf("a == c ? %s\n", Egal(a, c) ? "OUI" : "NON");
    printf("a == b ? %s\n", Egal(a, b) ? "OUI" : "NON");
    printf("Attendu: OUI, NON\n\n");
    
    // Test 5: Comparaison Inferieur
    printf("TEST 5: Comparaison Inferieur\n");
    afficherLigne();
    printf("b < a ? %s\n", Inferieur(b, a) ? "OUI" : "NON");
    printf("a < b ? %s\n", Inferieur(a, b) ? "OUI" : "NON");
    printf("Attendu: OUI, NON\n\n");
    
    // Test 6: Division par 2
    printf("TEST 6: Division par 2\n");
    afficherLigne();
    BigBinary d = creerBigBinaryDepuisChaine("10100");  // 20
    printf("d = "); afficheBigBinary(d);
    divisePar2(&d);
    printf("d / 2 = "); afficheBigBinary(d);
    printf("Attendu: 1010 (10 en decimal)\n\n");
    
    // Test 7: Multiplication par 2
    printf("TEST 7: Multiplication par 2\n");
    afficherLigne();
    BigBinary e = creerBigBinaryDepuisChaine("1010");  // 10
    printf("e = "); afficheBigBinary(e);
    BigBinary e2 = multiplierPar2(e);
    printf("e * 2 = "); afficheBigBinary(e2);
    printf("Attendu: 10100 (20 en decimal)\n\n");
    
    // Test 8: Addition avec retenue
    printf("TEST 8: Addition avec retenue (15 + 1 = 16)\n");
    afficherLigne();
    BigBinary f = creerBigBinaryDepuisChaine("1111");  // 15
    BigBinary g = creerBigBinaryDepuisChaine("1");     // 1
    BigBinary somme2 = Addition(f, g);
    printf("1111 + 1 = "); afficheBigBinary(somme2);
    printf("Attendu: 10000 (16 en decimal)\n\n");
    
    // Test 9: Grands nombres
    printf("TEST 9: Grands nombres (255 + 1 = 256)\n");
    afficherLigne();
    BigBinary h = creerBigBinaryDepuisChaine("11111111");  // 255
    BigBinary i = creerBigBinaryDepuisChaine("1");         // 1
    BigBinary somme3 = Addition(h, i);
    printf("11111111 + 1 = "); afficheBigBinary(somme3);
    printf("Attendu: 100000000 (256 en decimal)\n\n");
    
    // Test 10: Soustraction avec emprunt
    printf("TEST 10: Soustraction avec emprunt (16 - 1 = 15)\n");
    afficherLigne();
    BigBinary j = creerBigBinaryDepuisChaine("10000");  // 16
    BigBinary k = creerBigBinaryDepuisChaine("1");      // 1
    BigBinary diff2 = Soustraction(j, k);
    printf("10000 - 1 = "); afficheBigBinary(diff2);
    printf("Attendu: 1111 (15 en decimal)\n\n");
    
    // Libération mémoire
    libereBigBinary(&a); libereBigBinary(&b); libereBigBinary(&c);
    libereBigBinary(&d); libereBigBinary(&e); libereBigBinary(&e2);
    libereBigBinary(&f); libereBigBinary(&g); libereBigBinary(&h);
    libereBigBinary(&i); libereBigBinary(&j); libereBigBinary(&k);
    libereBigBinary(&somme); libereBigBinary(&somme2); libereBigBinary(&somme3);
    libereBigBinary(&diff); libereBigBinary(&diff2);
    
    printf("Phase 1 terminee avec succes!\n\n");
}

/* =============================================================================
 * TESTS AUTOMATIQUES PHASE 2
 * ============================================================================= */

void testerPhase2(void) {
    afficherTitre("PHASE 2: FONCTIONNALITES AVANCEES");
    printf("\n");
    
    // Test PGCD
    printf("TEST 1: PGCD (Algorithme Binaire d'Euclide)\n");
    afficherLigne();
    
    // PGCD(48, 18) = 6
    BigBinary a1 = creerBigBinaryDepuisChaine("110000");   // 48
    BigBinary b1 = creerBigBinaryDepuisChaine("10010");    // 18
    printf("PGCD(48, 18):\n");
    printf("  48 = "); afficheBigBinary(a1);
    printf("  18 = "); afficheBigBinary(b1);
    BigBinary pgcd1 = PGCD(a1, b1);
    printf("  Resultat = "); afficheBigBinary(pgcd1);
    printf("  Attendu: 110 (6)\n\n");
    
    // PGCD(51, 57) = 3 (exemple du document)
    BigBinary a2 = creerBigBinaryDepuisChaine("110011");   // 51
    BigBinary b2 = creerBigBinaryDepuisChaine("111001");   // 57
    printf("PGCD(51, 57):\n");
    BigBinary pgcd2 = PGCD(a2, b2);
    printf("  Resultat = "); afficheBigBinary(pgcd2);
    printf("  Attendu: 11 (3)\n\n");
    
    // PGCD(741, 715) = 13
    BigBinary a3 = creerBigBinaryDepuisChaine("1011100101");  // 741
    BigBinary b3 = creerBigBinaryDepuisChaine("1011001011");  // 715
    printf("PGCD(741, 715):\n");
    BigBinary pgcd3 = PGCD(a3, b3);
    printf("  Resultat = "); afficheBigBinary(pgcd3);
    printf("  Attendu: 1101 (13)\n\n");
    
    // Test Modulo
    printf("TEST 2: Modulo (sans division)\n");
    afficherLigne();
    
    // 192 mod 33 = 27
    BigBinary m1 = creerBigBinaryDepuisChaine("11000000");  // 192
    BigBinary n1 = creerBigBinaryDepuisChaine("100001");    // 33
    printf("192 mod 33:\n");
    BigBinary mod1 = Modulo(m1, n1);
    printf("  Resultat = "); afficheBigBinary(mod1);
    printf("  Attendu: 11011 (27)\n\n");
    
    // 100 mod 7 = 2
    BigBinary m2 = creerBigBinaryDepuisChaine("1100100");  // 100
    BigBinary n2 = creerBigBinaryDepuisChaine("111");      // 7
    printf("100 mod 7:\n");
    BigBinary mod2 = Modulo(m2, n2);
    printf("  Resultat = "); afficheBigBinary(mod2);
    printf("  Attendu: 10 (2)\n\n");
    
    // Test Multiplication Égyptienne
    printf("TEST 3: Multiplication Egyptienne\n");
    afficherLigne();
    
    // 13 * 11 = 143
    BigBinary x1 = creerBigBinaryDepuisChaine("1101");  // 13
    BigBinary y1 = creerBigBinaryDepuisChaine("1011");  // 11
    printf("13 * 11:\n");
    BigBinary prod1 = MultiplicationEgyptienne(x1, y1);
    printf("  Resultat = "); afficheBigBinary(prod1);
    printf("  Attendu: 10001111 (143)\n\n");
    
    // 25 * 4 = 100
    BigBinary x2 = creerBigBinaryDepuisChaine("11001");  // 25
    BigBinary y2 = creerBigBinaryDepuisChaine("100");    // 4
    printf("25 * 4:\n");
    BigBinary prod2 = MultiplicationEgyptienne(x2, y2);
    printf("  Resultat = "); afficheBigBinary(prod2);
    printf("  Attendu: 1100100 (100)\n\n");
    
    // Test Exponentiation Modulaire
    printf("TEST 4: Exponentiation Modulaire\n");
    afficherLigne();
    
    // 3^7 mod 11 = 9
    BigBinary base1 = creerBigBinaryDepuisChaine("11");     // 3
    BigBinary modulo1 = creerBigBinaryDepuisChaine("1011"); // 11
    printf("3^7 mod 11:\n");
    BigBinary exp1 = ExponentiationModulaire(base1, 7, modulo1);
    printf("  Resultat = "); afficheBigBinary(exp1);
    printf("  Attendu: 1001 (9)\n\n");
    
    // 2^10 mod 13 = 10
    BigBinary base2 = creerBigBinaryDepuisChaine("10");     // 2
    BigBinary modulo2 = creerBigBinaryDepuisChaine("1101"); // 13
    printf("2^10 mod 13:\n");
    BigBinary exp2 = ExponentiationModulaire(base2, 10, modulo2);
    printf("  Resultat = "); afficheBigBinary(exp2);
    printf("  Attendu: 1010 (10)\n\n");
    
    // Libération mémoire
    libereBigBinary(&a1); libereBigBinary(&b1); libereBigBinary(&pgcd1);
    libereBigBinary(&a2); libereBigBinary(&b2); libereBigBinary(&pgcd2);
    libereBigBinary(&a3); libereBigBinary(&b3); libereBigBinary(&pgcd3);
    libereBigBinary(&m1); libereBigBinary(&n1); libereBigBinary(&mod1);
    libereBigBinary(&m2); libereBigBinary(&n2); libereBigBinary(&mod2);
    libereBigBinary(&x1); libereBigBinary(&y1); libereBigBinary(&prod1);
    libereBigBinary(&x2); libereBigBinary(&y2); libereBigBinary(&prod2);
    libereBigBinary(&base1); libereBigBinary(&modulo1); libereBigBinary(&exp1);
    libereBigBinary(&base2); libereBigBinary(&modulo2); libereBigBinary(&exp2);
    
    printf("Phase 2 terminee avec succes!\n\n");
}

/* =============================================================================
 * TESTS AUTOMATIQUES PHASE 3 (RSA BONUS)
 * ============================================================================= */

void testerPhase3(void) {
    afficherTitre("PHASE 3 (BONUS): RSA");
    printf("\n");
    
    // Test RSA 1: N=33
    printf("TEST RSA 1: Exemple simple (N=33)\n");
    afficherLigne();
    printf("  Parametres:\n");
    printf("    p = 3, q = 11, N = 33\n");
    printf("    phi(N) = 20, E = 7, D = 3\n");
    printf("    Message M = 2\n\n");
    
    BigBinary N1 = creerBigBinaryDepuisChaine("100001");  // 33
    BigBinary M1 = creerBigBinaryDepuisChaine("10");      // 2
    
    // Chiffrement: C = 2^7 mod 33 = 29
    printf("  Chiffrement: C = M^E mod N = 2^7 mod 33\n");
    BigBinary C1 = RSA_Chiffrement(M1, 7, N1);
    printf("    C = "); afficheBigBinary(C1);
    printf("    Attendu: 11101 (29)\n\n");
    
    // Déchiffrement: M' = 29^3 mod 33 = 2
    printf("  Dechiffrement: M' = C^D mod N = 29^3 mod 33\n");
    BigBinary M1_dec = RSA_Dechiffrement(C1, 3, N1);
    printf("    M' = "); afficheBigBinary(M1_dec);
    printf("    Attendu: 10 (2)\n");
    printf("    Verification: M == M' ? %s\n\n", Egal(M1, M1_dec) ? "OUI - RSA fonctionne!" : "NON");
    
    // Test RSA 2: N=143
    printf("TEST RSA 2: Exemple moyen (N=143)\n");
    afficherLigne();
    printf("  Parametres:\n");
    printf("    p = 11, q = 13, N = 143\n");
    printf("    phi(N) = 120, E = 7, D = 103\n");
    printf("    Message M = 9\n\n");
    
    BigBinary N2 = creerBigBinaryDepuisChaine("10001111");  // 143
    BigBinary M2 = creerBigBinaryDepuisChaine("1001");      // 9
    
    // Chiffrement: C = 9^7 mod 143 = 48
    printf("  Chiffrement: C = 9^7 mod 143\n");
    BigBinary C2 = RSA_Chiffrement(M2, 7, N2);
    printf("    C = "); afficheBigBinary(C2);
    printf("    Attendu: 110000 (48)\n\n");
    
    // Déchiffrement: M' = 48^103 mod 143 = 9
    printf("  Dechiffrement: M' = 48^103 mod 143\n");
    BigBinary M2_dec = RSA_Dechiffrement(C2, 103, N2);
    printf("    M' = "); afficheBigBinary(M2_dec);
    printf("    Attendu: 1001 (9)\n");
    printf("    Verification: M == M' ? %s\n\n", Egal(M2, M2_dec) ? "OUI - RSA fonctionne!" : "NON");
    
    // Test RSA 3: Message plus grand
    printf("TEST RSA 3: Message M=100 (N=143)\n");
    afficherLigne();
    BigBinary M3 = creerBigBinaryDepuisChaine("1100100");  // 100
    BigBinary C3 = RSA_Chiffrement(M3, 7, N2);
    BigBinary M3_dec = RSA_Dechiffrement(C3, 103, N2);
    printf("  Chiffrement puis dechiffrement de M=100\n");
    printf("    M original = "); afficheBigBinary(M3);
    printf("    C (chiffre) = "); afficheBigBinary(C3);
    printf("    M' (dechiffre) = "); afficheBigBinary(M3_dec);
    printf("    Verification: M == M' ? %s\n\n", Egal(M3, M3_dec) ? "OUI - RSA fonctionne!" : "NON");
    
    // Libération mémoire
    libereBigBinary(&N1); libereBigBinary(&M1); libereBigBinary(&C1); libereBigBinary(&M1_dec);
    libereBigBinary(&N2); libereBigBinary(&M2); libereBigBinary(&C2); libereBigBinary(&M2_dec);
    libereBigBinary(&M3); libereBigBinary(&C3); libereBigBinary(&M3_dec);
    
    printf("Phase 3 (Bonus RSA) terminee avec succes!\n\n");
}

/* =============================================================================
 * MODE INTERACTIF
 * ============================================================================= */

void modeAddition(void) {
    afficherTitre("ADDITION");
    printf("\nEntrez deux nombres en binaire:\n");
    BigBinary a = lireBigBinary("A = ");
    BigBinary b = lireBigBinary("B = ");
    
    printf("\nCalcul: A + B\n");
    printf("  A = "); afficheBigBinary(a);
    printf("  B = "); afficheBigBinary(b);
    
    BigBinary resultat = Addition(a, b);
    printf("  A + B = "); afficheBigBinary(resultat);
    
    libereBigBinary(&a);
    libereBigBinary(&b);
    libereBigBinary(&resultat);
}

void modeSoustraction(void) {
    afficherTitre("SOUSTRACTION");
    printf("\nEntrez deux nombres en binaire (A >= B):\n");
    BigBinary a = lireBigBinary("A = ");
    BigBinary b = lireBigBinary("B = ");
    
    printf("\nCalcul: A - B\n");
    printf("  A = "); afficheBigBinary(a);
    printf("  B = "); afficheBigBinary(b);
    
    BigBinary resultat = Soustraction(a, b);
    printf("  A - B = "); afficheBigBinary(resultat);
    
    libereBigBinary(&a);
    libereBigBinary(&b);
    libereBigBinary(&resultat);
}

void modeComparaison(void) {
    afficherTitre("COMPARAISON");
    printf("\nEntrez deux nombres en binaire:\n");
    BigBinary a = lireBigBinary("A = ");
    BigBinary b = lireBigBinary("B = ");
    
    printf("\nComparaisons:\n");
    printf("  A = "); afficheBigBinary(a);
    printf("  B = "); afficheBigBinary(b);
    printf("  A == B ? %s\n", Egal(a, b) ? "OUI" : "NON");
    printf("  A < B  ? %s\n", Inferieur(a, b) ? "OUI" : "NON");
    printf("  A > B  ? %s\n", Superieur(a, b) ? "OUI" : "NON");
    
    libereBigBinary(&a);
    libereBigBinary(&b);
}

void modePGCD(void) {
    afficherTitre("PGCD (Algorithme Binaire d'Euclide)");
    printf("\nEntrez deux nombres en binaire:\n");
    BigBinary a = lireBigBinary("A = ");
    BigBinary b = lireBigBinary("B = ");
    
    printf("\nCalcul: PGCD(A, B)\n");
    printf("  A = "); afficheBigBinary(a);
    printf("  B = "); afficheBigBinary(b);
    
    BigBinary resultat = PGCD(a, b);
    printf("  PGCD = "); afficheBigBinary(resultat);
    
    libereBigBinary(&a);
    libereBigBinary(&b);
    libereBigBinary(&resultat);
}

void modeModulo(void) {
    afficherTitre("MODULO");
    printf("\nEntrez deux nombres en binaire:\n");
    BigBinary a = lireBigBinary("A = ");
    BigBinary b = lireBigBinary("B = ");
    
    printf("\nCalcul: A mod B\n");
    printf("  A = "); afficheBigBinary(a);
    printf("  B = "); afficheBigBinary(b);
    
    BigBinary resultat = Modulo(a, b);
    printf("  A mod B = "); afficheBigBinary(resultat);
    
    libereBigBinary(&a);
    libereBigBinary(&b);
    libereBigBinary(&resultat);
}

void modeMultiplication(void) {
    afficherTitre("MULTIPLICATION EGYPTIENNE");
    printf("\nEntrez deux nombres en binaire:\n");
    BigBinary a = lireBigBinary("A = ");
    BigBinary b = lireBigBinary("B = ");
    
    printf("\nCalcul: A * B\n");
    printf("  A = "); afficheBigBinary(a);
    printf("  B = "); afficheBigBinary(b);
    
    BigBinary resultat = MultiplicationEgyptienne(a, b);
    printf("  A * B = "); afficheBigBinary(resultat);
    
    libereBigBinary(&a);
    libereBigBinary(&b);
    libereBigBinary(&resultat);
}

void modeExponentiation(void) {
    afficherTitre("EXPONENTIATION MODULAIRE");
    printf("\nEntrez les parametres:\n");
    BigBinary base = lireBigBinary("Base (binaire) = ");
    unsigned int exposant = lireUnsignedInt("Exposant (decimal) = ");
    BigBinary modulo = lireBigBinary("Modulo (binaire) = ");
    
    printf("\nCalcul: base^exposant mod modulo\n");
    printf("  Base = "); afficheBigBinary(base);
    printf("  Exposant = %u\n", exposant);
    printf("  Modulo = "); afficheBigBinary(modulo);
    
    BigBinary resultat = ExponentiationModulaire(base, exposant, modulo);
    printf("  Resultat = "); afficheBigBinary(resultat);
    
    libereBigBinary(&base);
    libereBigBinary(&modulo);
    libereBigBinary(&resultat);
}

void modeRSA(void) {
    afficherTitre("RSA CHIFFREMENT / DECHIFFREMENT");
    printf("\nEntrez les parametres RSA:\n");
    BigBinary N = lireBigBinary("N (modulus, binaire) = ");
    unsigned int E = lireUnsignedInt("E (exposant public, decimal) = ");
    unsigned int D = lireUnsignedInt("D (exposant prive, decimal) = ");
    BigBinary M = lireBigBinary("M (message, binaire) = ");
    
    printf("\n--- Chiffrement ---\n");
    printf("  M = "); afficheBigBinary(M);
    BigBinary C = RSA_Chiffrement(M, E, N);
    printf("  C = M^E mod N = "); afficheBigBinary(C);
    
    printf("\n--- Dechiffrement ---\n");
    printf("  C = "); afficheBigBinary(C);
    BigBinary M_dec = RSA_Dechiffrement(C, D, N);
    printf("  M' = C^D mod N = "); afficheBigBinary(M_dec);
    
    printf("\n--- Verification ---\n");
    printf("  M == M' ? %s\n", Egal(M, M_dec) ? "OUI - RSA fonctionne!" : "NON");
    
    libereBigBinary(&N);
    libereBigBinary(&M);
    libereBigBinary(&C);
    libereBigBinary(&M_dec);
}

/* =============================================================================
 * PROGRAMME PRINCIPAL
 * ============================================================================= */

int main(void) {
    int choix = -1;
    
    printf("\n");
    afficherTitre("PROJET BIGBINARY - ESIEA S5");
    printf("       Manipulation de Grands Entiers Binaires\n");
    printf("           Phases 1, 2 et 3 (RSA Bonus)\n");
    afficherSeparateur();
    
    while (choix != 0) {
        afficherMenu();
        scanf("%d", &choix);
        
        switch (choix) {
            case 1:
                testerPhase1();
                break;
            case 2:
                testerPhase2();
                break;
            case 3:
                testerPhase3();
                break;
            case 4:
                testerPhase1();
                testerPhase2();
                testerPhase3();
                break;
            case 5:
                modeAddition();
                break;
            case 6:
                modeSoustraction();
                break;
            case 7:
                modeComparaison();
                break;
            case 8:
                modePGCD();
                break;
            case 9:
                modeModulo();
                break;
            case 10:
                modeMultiplication();
                break;
            case 11:
                modeExponentiation();
                break;
            case 12:
                modeRSA();
                break;
            case 0:
                printf("\nAu revoir!\n\n");
                break;
            default:
                printf("\nChoix invalide. Veuillez reessayer.\n");
        }
    }
    
    return 0;
}
