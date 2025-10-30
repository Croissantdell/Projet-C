#include "BigBinary.h"

int main() {
    printf("===========================================\n");
    printf("   PROJET BIGBINARY - PHASE 1 - TESTS\n");
    printf("===========================================\n\n");
    
    printf("TEST 1: Création et affichage\n");
    printf("------------------------------\n");
    BigBinary a = creerBigBinaryDepuisChaine("1010");  // 10 en décimal
    BigBinary b = creerBigBinaryDepuisChaine("0101");  // 5 en décimal
    printf("a = ");
    afficheBigBinary(a);
    printf("b = ");
    afficheBigBinary(b);
    printf("\n");
    
    // TEST 2: Addition
    printf("TEST 2: Addition\n");
    printf("----------------\n");
    printf("a = ");
    afficheBigBinary(a);
    printf("b = ");
    afficheBigBinary(b);
    BigBinary somme = Addition(a, b);
    printf("a + b = ");
    afficheBigBinary(somme);
    printf("Attendu: 1111 (15 en decimal)\n\n");
    
    // TEST 3: Soustraction
    printf("TEST 3: Soustraction\n");
    printf("--------------------\n");
    printf("a = ");
    afficheBigBinary(a);
    printf("b = ");
    afficheBigBinary(b);
    BigBinary diff = Soustraction(a, b);
    printf("a - b = ");
    afficheBigBinary(diff);
    printf("Attendu: 0101 (5 en decimal)\n\n");
    
    // TEST 4: Comparaison Egal
    printf("TEST 4: Comparaison Egal\n");
    printf("------------------------\n");
    BigBinary c = creerBigBinaryDepuisChaine("1010");
    printf("a = ");
    afficheBigBinary(a);
    printf("c = ");
    afficheBigBinary(c);
    printf("a == c ? %s\n", Egal(a, c) ? "OUI" : "NON");
    printf("Attendu: OUI\n\n");
    
    // TEST 5: Comparaison Inferieur
    printf("TEST 5: Comparaison Inferieur\n");
    printf("------------------------------\n");
    printf("b = ");
    afficheBigBinary(b);
    printf("a = ");
    afficheBigBinary(a);
    printf("b < a ? %s\n", Inferieur(b, a) ? "OUI" : "NON");
    printf("Attendu: OUI\n\n");
    
    // TEST 6: Division par 2
    printf("TEST 6: Division par 2\n");
    printf("----------------------\n");
    BigBinary d = creerBigBinaryDepuisChaine("10100");  // 20 en décimal
    printf("Avant: d = ");
    afficheBigBinary(d);
    divisePar2(&d);
    printf("Après division par 2: d = ");
    afficheBigBinary(d);
    printf("Attendu: 1010 (10 en decimal)\n\n");
    
    // TEST 7: Addition avec retenue
    printf("TEST 7: Addition avec retenue\n");
    printf("------------------------------\n");
    BigBinary e = creerBigBinaryDepuisChaine("1111");  // 15
    BigBinary f = creerBigBinaryDepuisChaine("0001");  // 1
    printf("e = ");
    afficheBigBinary(e);
    printf("f = ");
    afficheBigBinary(f);
    BigBinary somme2 = Addition(e, f);
    printf("e + f = ");
    afficheBigBinary(somme2);
    printf("Attendu: 10000 (16 en decimal)\n\n");
    
    // TEST 8: Grands nombres
    printf("TEST 8: Grands nombres\n");
    printf("----------------------\n");
    BigBinary g = creerBigBinaryDepuisChaine("11111111");  // 255
    BigBinary h = creerBigBinaryDepuisChaine("00000001");  // 1
    printf("g = ");
    afficheBigBinary(g);
    printf("h = ");
    afficheBigBinary(h);
    BigBinary somme3 = Addition(g, h);
    printf("g + h = ");
    afficheBigBinary(somme3);
    printf("Attendu: 100000000 (256 en decimal)\n\n");
    
    // TEST 9: Exemple du document (83)
    printf("TEST 9: Exemple du document\n");
    printf("---------------------------\n");
    BigBinary nb83 = creerBigBinaryDepuisChaine("1010011");  // 83
    printf("Valeur initiale: ");
    afficheBigBinary(nb83);
    divisePar2(&nb83);
    printf("Après division par 2: ");
    afficheBigBinary(nb83);
    printf("Attendu: 101001 (41 en decimal)\n\n");
    
    // TEST 10: Soustraction complexe
    printf("TEST 10: Soustraction complexe\n");
    printf("-------------------------------\n");
    BigBinary i = creerBigBinaryDepuisChaine("10000");  // 16
    BigBinary j = creerBigBinaryDepuisChaine("00001");  // 1
    printf("i = ");
    afficheBigBinary(i);
    printf("j = ");
    afficheBigBinary(j);
    BigBinary diff2 = Soustraction(i, j);
    printf("i - j = ");
    afficheBigBinary(diff2);
    printf("Attendu: 1111 (15 en decimal)\n\n");
    
    // Libération de la mémoire
    libereBigBinary(&a);
    libereBigBinary(&b);
    libereBigBinary(&c);
    libereBigBinary(&d);
    libereBigBinary(&e);
    libereBigBinary(&f);
    libereBigBinary(&g);
    libereBigBinary(&h);
    libereBigBinary(&i);
    libereBigBinary(&j);
    libereBigBinary(&somme);
    libereBigBinary(&somme2);
    libereBigBinary(&somme3);
    libereBigBinary(&diff);
    libereBigBinary(&diff2);
    libereBigBinary(&nb83);
    
    printf("===========================================\n");
    printf("       TOUS LES TESTS SONT TERMINÉS\n");
    printf("===========================================\n");
    
    return 0;
}
