/*
 * EXEMPLES D'UTILISATION DE LA BIBLIOTHÈQUE BIGBINARY
 * ====================================================
 */

#include "BigBinary.h"

// ============================================
// EXEMPLE 1 : Créer et afficher un nombre
// ============================================
void exemple1() {
    printf("=== EXEMPLE 1 : Créer et afficher ===\n");
    
    BigBinary nb = creerBigBinaryDepuisChaine("10101010");
    printf("Mon nombre : ");
    afficheBigBinary(nb);
    
    libereBigBinary(&nb);
}

// ============================================
// EXEMPLE 2 : Addition de deux nombres
// ============================================
void exemple2() {
    printf("\n=== EXEMPLE 2 : Addition ===\n");
    
    BigBinary a = creerBigBinaryDepuisChaine("1100");  // 12
    BigBinary b = creerBigBinaryDepuisChaine("0101");  // 5
    BigBinary somme = Addition(a, b);
    
    printf("a = ");
    afficheBigBinary(a);
    printf("b = ");
    afficheBigBinary(b);
    printf("a + b = ");
    afficheBigBinary(somme);
    
    libereBigBinary(&a);
    libereBigBinary(&b);
    libereBigBinary(&somme);
}

// ============================================
// EXEMPLE 3 : Soustraction
// ============================================
void exemple3() {
    printf("\n=== EXEMPLE 3 : Soustraction ===\n");
    
    BigBinary a = creerBigBinaryDepuisChaine("11111");  // 31
    BigBinary b = creerBigBinaryDepuisChaine("01010");  // 10
    BigBinary diff = Soustraction(a, b);
    
    printf("a = ");
    afficheBigBinary(a);
    printf("b = ");
    afficheBigBinary(b);
    printf("a - b = ");
    afficheBigBinary(diff);
    
    libereBigBinary(&a);
    libereBigBinary(&b);
    libereBigBinary(&diff);
}

// ============================================
// EXEMPLE 4 : Comparer deux nombres
// ============================================
void exemple4() {
    printf("\n=== EXEMPLE 4 : Comparaisons ===\n");
    
    BigBinary a = creerBigBinaryDepuisChaine("1010");
    BigBinary b = creerBigBinaryDepuisChaine("1010");
    BigBinary c = creerBigBinaryDepuisChaine("0101");
    
    printf("a = ");
    afficheBigBinary(a);
    printf("b = ");
    afficheBigBinary(b);
    printf("c = ");
    afficheBigBinary(c);
    
    printf("a == b ? %s\n", Egal(a, b) ? "OUI" : "NON");
    printf("a == c ? %s\n", Egal(a, c) ? "OUI" : "NON");
    printf("c < a ? %s\n", Inferieur(c, a) ? "OUI" : "NON");
    
    libereBigBinary(&a);
    libereBigBinary(&b);
    libereBigBinary(&c);
}

// ============================================
// EXEMPLE 5 : Division par 2
// ============================================
void exemple5() {
    printf("\n=== EXEMPLE 5 : Division par 2 ===\n");
    
    BigBinary nb = creerBigBinaryDepuisChaine("11110000");  // 240
    
    printf("Valeur initiale : ");
    afficheBigBinary(nb);
    
    divisePar2(&nb);
    printf("Après /2 : ");
    afficheBigBinary(nb);
    
    divisePar2(&nb);
    printf("Après /2 encore : ");
    afficheBigBinary(nb);
    
    libereBigBinary(&nb);
}

// ============================================
// EXEMPLE 6 : Calculer 2^10 = 1024
// ============================================
void exemple6() {
    printf("\n=== EXEMPLE 6 : Calculer 2^10 ===\n");
    
    // Commencer avec 1
    BigBinary resultat = creerBigBinaryDepuisChaine("1");
    BigBinary deux = creerBigBinaryDepuisChaine("10");  // 2 en binaire
    
    printf("Calcul de 2^10 :\n");
    printf("Départ : ");
    afficheBigBinary(resultat);
    
    // Multiplier par 2 dix fois (en ajoutant à lui-même)
    for (int i = 0; i < 10; i++) {
        BigBinary temp = Addition(resultat, resultat);
        libereBigBinary(&resultat);
        resultat = temp;
    }
    
    printf("2^10 = ");
    afficheBigBinary(resultat);
    printf("(devrait être 10000000000 en binaire = 1024 en décimal)\n");
    
    libereBigBinary(&resultat);
    libereBigBinary(&deux);
}

// ============================================
// EXEMPLE 7 : Algorithme simple
// ============================================
void exemple7() {
    printf("\n=== EXEMPLE 7 : Diviser jusqu'à 1 ===\n");
    
    BigBinary nb = creerBigBinaryDepuisChaine("10000");  // 16
    int compteur = 0;
    
    printf("Nombre de départ : ");
    afficheBigBinary(nb);
    
    // Diviser par 2 jusqu'à atteindre 1
    while (nb.Taille > 1 || nb.Tdigits[0] != 1) {
        divisePar2(&nb);
        compteur++;
        printf("Étape %d : ", compteur);
        afficheBigBinary(nb);
    }
    
    printf("Nombre de divisions : %d\n", compteur);
    printf("(log2(16) = 4)\n");
    
    libereBigBinary(&nb);
}

// ============================================
// PROGRAMME PRINCIPAL
// ============================================
int main() {
    printf("============================================\n");
    printf("   EXEMPLES D'UTILISATION - BIGBINARY\n");
    printf("============================================\n");
    
    exemple1();
    exemple2();
    exemple3();
    exemple4();
    exemple5();
    exemple6();
    exemple7();
    
    printf("\n============================================\n");
    printf("   FIN DES EXEMPLES\n");
    printf("============================================\n");
    
    return 0;
}
