# PROJET BIGBINARY - PHASE 1

## Description
Bibliothèque C pour manipuler des grands entiers en binaire.

## Fichiers
- `BigBinary.h` : Fichier d'en-tête
- `BigBinary.c` : Implémentation des fonctions
- `main.c` : Programme de test
- `Makefile` : Pour compiler

## Compilation

### Avec Makefile (Linux/Mac)
```bash
make
./bigbinary
```

### Manuellement
```bash
gcc -Wall -Wextra -std=c99 -c BigBinary.c
gcc -Wall -Wextra -std=c99 -c main.c
gcc -Wall -Wextra -std=c99 -o bigbinary BigBinary.o main.o
./bigbinary
```

### Windows
```cmd
gcc -Wall -Wextra -std=c99 -c BigBinary.c
gcc -Wall -Wextra -std=c99 -c main.c
gcc -Wall -Wextra -std=c99 -o bigbinary.exe BigBinary.o main.o
bigbinary.exe
```

## Fonctionnalités implémentées

### Phase 1
✓ Structure BigBinary
✓ Création depuis une chaîne binaire
✓ Affichage
✓ Addition (A + B)
✓ Soustraction (A - B avec A >= B)
✓ Comparaison : Egal(A, B)
✓ Comparaison : Inferieur(A, B)
✓ Division par 2
✓ Libération mémoire

## Tests
Le fichier `main.c` contient 10 tests qui vérifient toutes les fonctionnalités.

## Exemple d'utilisation
```c
#include "BigBinary.h"

int main() {
    // Créer deux nombres
    BigBinary a = creerBigBinaryDepuisChaine("1010");  // 10
    BigBinary b = creerBigBinaryDepuisChaine("0101");  // 5
    
    // Addition
    BigBinary somme = Addition(a, b);
    afficheBigBinary(somme);  // Affiche: 1111
    
    // Libérer la mémoire
    libereBigBinary(&a);
    libereBigBinary(&b);
    libereBigBinary(&somme);
    
    return 0;
}
```

## Auteur
Projet ESIEA - 3ème Année
Année 2025-2026
