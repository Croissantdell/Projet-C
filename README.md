# PROJET BIGBINARY - PHASE 1
## Pour CLion

## 📁 Structure du projet
```
BigBinary_CLion/
├── CMakeLists.txt          # Configuration CMake
├── src/
│   ├── BigBinary.h         # Fichier d'en-tête
│   └── BigBinary.c         # Implémentation
├── main.c                  # Programme principal (10 tests)
├── tests.c                 # Tests complets (8 fonctions)
├── exemples.c              # Exemples pratiques (7 exemples)
└── README.md               # Ce fichier
```

## 🚀 Ouvrir dans CLion

### Méthode 1 : Ouvrir le projet
1. Ouvrir CLion
2. File → Open
3. Sélectionner le dossier `BigBinary_CLion`
4. CLion détectera automatiquement le CMakeLists.txt

### Méthode 2 : Importer depuis ZIP
1. Extraire le ZIP
2. Dans CLion : File → Open
3. Sélectionner le dossier extrait

## ▶️ Exécuter le projet

### Configurations disponibles
CLion créera automatiquement 3 configurations :

1. **bigbinary_main** - Programme principal avec 10 tests
2. **bigbinary_tests** - Jeu de tests complet
3. **bigbinary_exemples** - 7 exemples d'utilisation

### Pour exécuter :
1. Sélectionner la configuration dans la barre d'outils
2. Cliquer sur le bouton ▶️ (Run) ou Shift+F10
3. Les résultats s'afficheront dans la console

### Pour déboguer :
1. Mettre des points d'arrêt (clic sur la marge gauche)
2. Cliquer sur le bouton 🐛 (Debug) ou Shift+F9

## 🔧 Compilation manuelle (optionnel)

Si vous voulez compiler en ligne de commande :

```bash
# Créer le dossier build
mkdir build
cd build

# Configurer avec CMake
cmake ..

# Compiler
cmake --build .

# Exécuter
./bigbinary_main
./bigbinary_tests
./bigbinary_exemples
```

## ✅ Fonctionnalités Phase 1

- [x] Structure BigBinary
- [x] Création depuis chaîne binaire
- [x] Addition
- [x] Soustraction
- [x] Comparaison Egal
- [x] Comparaison Inferieur
- [x] Division par 2
- [x] Affichage
- [x] Gestion mémoire

## 📝 Tests

### Programme principal (main.c)
- 10 tests de base
- Couvre toutes les fonctionnalités

### Tests complets (tests.c)
- 8 fonctions de test détaillées
- Tests de cas limites
- Validation exhaustive

### Exemples (exemples.c)
- 7 exemples pratiques
- Montre l'utilisation réelle
- Cas d'usage courants

## 🎯 Utilisation

```c
#include "BigBinary.h"

int main() {
    // Créer des nombres
    BigBinary a = creerBigBinaryDepuisChaine("1010");
    BigBinary b = creerBigBinaryDepuisChaine("0101");
    
    // Addition
    BigBinary somme = Addition(a, b);
    afficheBigBinary(somme);
    
    // Nettoyage
    libereBigBinary(&a);
    libereBigBinary(&b);
    libereBigBinary(&somme);
    
    return 0;
}
```

## 🔍 Débogage dans CLion

### Conseils :
- Utiliser les points d'arrêt sur les lignes importantes
- Inspecter les variables dans la fenêtre Variables
- Utiliser Step Over (F8) pour avancer ligne par ligne
- Utiliser Step Into (F7) pour entrer dans les fonctions

### Zones à surveiller :
- Allocation mémoire (malloc)
- Libération mémoire (free)
- Indices de tableaux
- Retenues et emprunts dans les opérations

## ⚙️ Configuration CLion

### Optimisations suggérées :
1. **Code Style** : Settings → Editor → Code Style → C/C++
2. **Inspections** : Settings → Editor → Inspections
3. **CMake** : Settings → Build, Execution → CMake

### Plugins utiles :
- Memory View (pour inspecter la mémoire)
- Rainbow Brackets (coloration des parenthèses)

## 🐛 Résolution de problèmes

### Erreur CMake
- Vérifier que CMake est installé
- Tools → CMake → Reload CMake Project

### Erreur de compilation
- Vérifier que le compilateur C est configuré
- Settings → Build, Execution → Toolchains

### Headers non trouvés
- Le CMakeLists.txt inclut automatiquement src/
- Rebuild le projet : Build → Rebuild Project

## 📚 Documentation

- **BigBinary.h** : Toutes les déclarations de fonctions
- **BigBinary.c** : Implémentation détaillée avec commentaires
- **Commentaires dans le code** : Explications des algorithmes

## 🎓 Pour aller plus loin

Ce projet est la Phase 1. Les phases suivantes incluront :
- Phase 2 : PGCD binaire, Modulo, Exponentiation
- Phase 3 : Chiffrement RSA (Bonus)

## 👤 Auteur

Projet ESIEA - 3ème Année
Année 2025-2026

---

**Prêt à utiliser dans CLion !** 🚀
