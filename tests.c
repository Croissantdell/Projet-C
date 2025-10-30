#include "BigBinary.h"

void test_addition_simple() {
    printf("\n=== TEST: Addition Simple ===\n");
    BigBinary a = creerBigBinaryDepuisChaine("1100");  // 12
    BigBinary b = creerBigBinaryDepuisChaine("0011");  // 3
    BigBinary resultat = Addition(a, b);
    
    printf("1100 + 0011 = ");
    afficheBigBinary(resultat);
    printf("Attendu: 1111 (15)\n");
    
    libereBigBinary(&a);
    libereBigBinary(&b);
    libereBigBinary(&resultat);
}

void test_addition_retenue() {
    printf("\n=== TEST: Addition avec Retenue ===\n");
    BigBinary a = creerBigBinaryDepuisChaine("1111");  // 15
    BigBinary b = creerBigBinaryDepuisChaine("1111");  // 15
    BigBinary resultat = Addition(a, b);
    
    printf("1111 + 1111 = ");
    afficheBigBinary(resultat);
    printf("Attendu: 11110 (30)\n");
    
    libereBigBinary(&a);
    libereBigBinary(&b);
    libereBigBinary(&resultat);
}

void test_soustraction_simple() {
    printf("\n=== TEST: Soustraction Simple ===\n");
    BigBinary a = creerBigBinaryDepuisChaine("11001");  // 25
    BigBinary b = creerBigBinaryDepuisChaine("01010");  // 10
    BigBinary resultat = Soustraction(a, b);
    
    printf("11001 - 01010 = ");
    afficheBigBinary(resultat);
    printf("Attendu: 1111 (15)\n");
    
    libereBigBinary(&a);
    libereBigBinary(&b);
    libereBigBinary(&resultat);
}

void test_soustraction_emprunt() {
    printf("\n=== TEST: Soustraction avec Emprunt ===\n");
    BigBinary a = creerBigBinaryDepuisChaine("100000");  // 32
    BigBinary b = creerBigBinaryDepuisChaine("000001");  // 1
    BigBinary resultat = Soustraction(a, b);
    
    printf("100000 - 000001 = ");
    afficheBigBinary(resultat);
    printf("Attendu: 11111 (31)\n");
    
    libereBigBinary(&a);
    libereBigBinary(&b);
    libereBigBinary(&resultat);
}

void test_egal() {
    printf("\n=== TEST: Fonction Egal ===\n");
    
    // Test 1: Nombres égaux
    BigBinary a = creerBigBinaryDepuisChaine("10101");
    BigBinary b = creerBigBinaryDepuisChaine("10101");
    printf("10101 == 10101 ? %s (Attendu: OUI)\n", Egal(a, b) ? "OUI" : "NON");
    
    // Test 2: Nombres différents
    BigBinary c = creerBigBinaryDepuisChaine("10101");
    BigBinary d = creerBigBinaryDepuisChaine("01010");
    printf("10101 == 01010 ? %s (Attendu: NON)\n", Egal(c, d) ? "OUI" : "NON");
    
    // Test 3: Avec zéros de tête
    BigBinary e = creerBigBinaryDepuisChaine("00101");
    BigBinary f = creerBigBinaryDepuisChaine("101");
    printf("00101 == 101 ? %s (Attendu: OUI)\n", Egal(e, f) ? "OUI" : "NON");
    
    libereBigBinary(&a);
    libereBigBinary(&b);
    libereBigBinary(&c);
    libereBigBinary(&d);
    libereBigBinary(&e);
    libereBigBinary(&f);
}

void test_inferieur() {
    printf("\n=== TEST: Fonction Inferieur ===\n");
    
    // Test 1: A < B (vrai)
    BigBinary a = creerBigBinaryDepuisChaine("0101");  // 5
    BigBinary b = creerBigBinaryDepuisChaine("1010");  // 10
    printf("0101 < 1010 ? %s (Attendu: OUI)\n", Inferieur(a, b) ? "OUI" : "NON");
    
    // Test 2: A > B (faux)
    BigBinary c = creerBigBinaryDepuisChaine("1111");  // 15
    BigBinary d = creerBigBinaryDepuisChaine("0011");  // 3
    printf("1111 < 0011 ? %s (Attendu: NON)\n", Inferieur(c, d) ? "OUI" : "NON");
    
    // Test 3: A == B (faux)
    BigBinary e = creerBigBinaryDepuisChaine("1010");
    BigBinary f = creerBigBinaryDepuisChaine("1010");
    printf("1010 < 1010 ? %s (Attendu: NON)\n", Inferieur(e, f) ? "OUI" : "NON");
    
    libereBigBinary(&a);
    libereBigBinary(&b);
    libereBigBinary(&c);
    libereBigBinary(&d);
    libereBigBinary(&e);
    libereBigBinary(&f);
}

void test_division_par_2() {
    printf("\n=== TEST: Division par 2 ===\n");
    
    // Test 1: Nombre pair
    BigBinary a = creerBigBinaryDepuisChaine("11110");  // 30
    printf("Avant: ");
    afficheBigBinary(a);
    divisePar2(&a);
    printf("Après /2: ");
    afficheBigBinary(a);
    printf("Attendu: 1111 (15)\n");
    
    // Test 2: Nombre impair
    BigBinary b = creerBigBinaryDepuisChaine("10101");  // 21
    printf("\nAvant: ");
    afficheBigBinary(b);
    divisePar2(&b);
    printf("Après /2: ");
    afficheBigBinary(b);
    printf("Attendu: 1010 (10)\n");
    
    libereBigBinary(&a);
    libereBigBinary(&b);
}

void test_grands_nombres() {
    printf("\n=== TEST: Très Grands Nombres ===\n");
    
    // 2^10 - 1 = 1023
    BigBinary a = creerBigBinaryDepuisChaine("1111111111");
    // 1
    BigBinary b = creerBigBinaryDepuisChaine("0000000001");
    
    printf("Calcul de 1111111111 + 0000000001\n");
    BigBinary somme = Addition(a, b);
    printf("Résultat: ");
    afficheBigBinary(somme);
    printf("Attendu: 10000000000 (1024)\n");
    
    libereBigBinary(&a);
    libereBigBinary(&b);
    libereBigBinary(&somme);
}

void test_cas_limites() {
    printf("\n=== TEST: Cas Limites ===\n");
    
    // Test 1: Addition de zéros
    BigBinary zero1 = creerBigBinaryDepuisChaine("0000");
    BigBinary zero2 = creerBigBinaryDepuisChaine("0000");
    BigBinary somme_zeros = Addition(zero1, zero2);
    printf("0000 + 0000 = ");
    afficheBigBinary(somme_zeros);
    
    // Test 2: Soustraction donnant zéro
    BigBinary c = creerBigBinaryDepuisChaine("1010");
    BigBinary d = creerBigBinaryDepuisChaine("1010");
    BigBinary diff_zero = Soustraction(c, d);
    printf("1010 - 1010 = ");
    afficheBigBinary(diff_zero);
    
    libereBigBinary(&zero1);
    libereBigBinary(&zero2);
    libereBigBinary(&somme_zeros);
    libereBigBinary(&c);
    libereBigBinary(&d);
    libereBigBinary(&diff_zero);
}

int main() {
    printf("============================================\n");
    printf("   JEU DE TESTS COMPLET - BIGBINARY\n");
    printf("============================================\n");
    
    test_addition_simple();
    test_addition_retenue();
    test_soustraction_simple();
    test_soustraction_emprunt();
    test_egal();
    test_inferieur();
    test_division_par_2();
    test_grands_nombres();
    test_cas_limites();
    
    printf("\n============================================\n");
    printf("   TOUS LES TESTS SONT TERMINÉS !\n");
    printf("============================================\n");
    
    return 0;
}
