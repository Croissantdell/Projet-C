# Projet BigBinary - ESIEA S5

## Description

Ce projet implémente une bibliothèque en C pour la manipulation de **grands entiers binaires** (BigBinary), permettant d'effectuer des calculs sur des nombres arbitrairement grands, au-delà des limites des types natifs (32/64 bits).


---

## Structure du Projet

```
bigbinary_projet/
├── main.c              # Programme principal avec interface interactive
├── Makefile            # Script de compilation
├── README.md           
└── src/
    ├── BigBinary.h     # Déclarations des structures et fonctions
    └── BigBinary.c     # Implémentation de la bibliothèque
```

---


## Fonctionnalités Implémentées

### Phase 1 : Fonctionnalités de Base
-  Structure `BigBinary` (tableau de bits, taille, signe)
-  Création depuis chaîne binaire
-  Addition (algorithme de l'école primaire)
-  Soustraction (avec gestion des emprunts)
-  Comparaisons (`Egal`, `Inferieur`, `Superieur`)
-  Division/Multiplication par 2 (décalages binaires)

### Phase 2 : Fonctionnalités Avancées
-  **PGCD** - Algorithme binaire d'Euclide (Stein)
-  **Modulo** - Division-free mod (sans division euclidienne)
-  **Multiplication Égyptienne** - Par doublement et addition
-  **Exponentiation Modulaire Rapide** - Square-and-multiply

### Phase 3 : RSA (Bonus)
-  **Chiffrement RSA** : C = M^E mod N
-  **Déchiffrement RSA** : M = C^D mod N
-  Support des grands exposants (BigBinary)

---

## Interface Utilisateur

Le programme propose un menu interactif avec :
1. **Tests automatiques** pour chaque phase
2. **Mode interactif** pour tester manuellement les opérations

### Exemple d'utilisation

```
============================================================
         MENU PRINCIPAL
============================================================

  [1] Tests automatiques Phase 1 (Base)
  [2] Tests automatiques Phase 2 (Avancée)
  [3] Tests automatiques Phase 3 (RSA Bonus)
  [4] Tous les tests automatiques

  --- Mode Interactif ---
  [5] Addition (A + B)
  [6] Soustraction (A - B)
  ...
  [12] RSA Chiffrement/Déchiffrement

  [0] Quitter
```

---

## Algorithmes Clés

### Algorithme Binaire d'Euclide (PGCD)
Calcule le PGCD sans division euclidienne :
- Si a et b pairs : PGCD(a,b) = 2 × PGCD(a/2, b/2)
- Si a pair, b impair : PGCD(a,b) = PGCD(a/2, b)
- Si a et b impairs : PGCD(a,b) = PGCD(|a-b|, min(a,b))

### Modulo sans Division
Algorithme "Division-free mod" :
1. Trouver k tel que 2^k × B ≤ A
2. A = A - 2^k × B
3. Répéter jusqu'à A < B

### Multiplication Égyptienne
A × B = Σ (A × 2^i) pour chaque bit i de B égal à 1

### Exponentiation Modulaire (Square-and-Multiply)
- Si e pair : base^e = (base²)^(e/2) mod n
- Si e impair : base^e = base × base^(e-1) mod n

---

## Exemples de Tests

### Addition
```
1010 + 101 = 1111  (10 + 5 = 15)
```

### PGCD
```
PGCD(741, 715) = 13
PGCD(48, 18) = 6
```

### RSA
```
Paramètres: p=3, q=11, N=33, E=7, D=3
Message M = 2
Chiffrement: C = 2^7 mod 33 = 29
Déchiffrement: M' = 29^3 mod 33 = 2 ✓
```

---

## Convention de Stockage

- `Tdigits[0]` = bit de poids fort (MSB)
- `Tdigits[Taille-1]` = bit de poids faible (LSB)
- Exemple : 13 = 1101 → Tdigits = {1, 1, 0, 1}

---

## Auteurs

Projet ESIEA - Année académique 2025-2026
