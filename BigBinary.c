#include "BigBinary.h"

// ============================================================================
// FONCTIONS DE CRÉATION ET INITIALISATION
// ============================================================================

// Initialise un BigBinary vide (tous les bits à 0)
BigBinary initBigBinary(int taille, int signe) {
    BigBinary nb;
    nb.Taille = taille;
    nb.Signe = signe;
    nb.Tdigits = malloc(sizeof(int) * taille);
    for (int i = 0; i < taille; i++) {
        nb.Tdigits[i] = 0;
    }
    return nb;
}

// Création depuis une chaîne binaire
BigBinary creerBigBinaryDepuisChaine(const char *chaine) {
    BigBinary nb;
    int n = strlen(chaine);
    nb.Taille = 0;
    
    // Compte uniquement les caractères valides ('0' ou '1')
    for (int i = 0; i < n; i++) {
        if (chaine[i] == '0' || chaine[i] == '1') {
            nb.Taille++;
        }
    }
    
    if (nb.Taille == 0) {
        nb.Taille = 1;
        nb.Tdigits = malloc(sizeof(int) * 1);
        nb.Tdigits[0] = 0;
        nb.Signe = 0;
        return nb;
    }
    
    nb.Tdigits = malloc(sizeof(int) * nb.Taille);
    nb.Signe = +1;
    int index = 0;
    int tousZeros = 1;
    
    for (int i = 0; i < n; i++) {
        if (chaine[i] == '0' || chaine[i] == '1') {
            nb.Tdigits[index] = chaine[i] - '0';
            if (nb.Tdigits[index] == 1) tousZeros = 0;
            index++;
        }
    }
    
    if (tousZeros) nb.Signe = 0;
    return nb;
}

// Libération de la mémoire
void libereBigBinary(BigBinary *nb) {
    if (nb->Tdigits != NULL) {
        free(nb->Tdigits);
        nb->Tdigits = NULL;
    }
    nb->Taille = 0;
    nb->Signe = 0;
}

// ============================================================================
// FONCTIONS D'AFFICHAGE
// ============================================================================

// Affichage du nombre binaire
void afficheBigBinary(BigBinary nb) {
    if (nb.Signe == -1) printf("-");
    if (nb.Signe == 0 || nb.Taille == 0) {
        printf("0\n");
        return;
    }
    for (int i = 0; i < nb.Taille; i++) {
        printf("%d", nb.Tdigits[i]);
    }
    printf("\n");
}

// ============================================================================
// FONCTIONS UTILITAIRES
// ============================================================================

// Compte le nombre de bits significatifs (sans les zéros de tête)
static int compterBitsSignificatifs(BigBinary nb) {
    int count = nb.Taille;
    for (int i = 0; i < nb.Taille; i++) {
        if (nb.Tdigits[i] != 0) {
            break;
        }
        count--;
    }
    return (count > 0) ? count : 1;
}

// Supprime les zéros de tête et retourne un nouveau BigBinary
static BigBinary supprimerZerosDeTete(BigBinary nb) {
    int debut = 0;
    while (debut < nb.Taille - 1 && nb.Tdigits[debut] == 0) {
        debut++;
    }
    
    int nouvelleTaille = nb.Taille - debut;
    BigBinary resultat;
    resultat.Taille = nouvelleTaille;
    resultat.Signe = nb.Signe;
    resultat.Tdigits = malloc(sizeof(int) * nouvelleTaille);
    
    for (int i = 0; i < nouvelleTaille; i++) {
        resultat.Tdigits[i] = nb.Tdigits[debut + i];
    }
    
    // Vérifier si c'est zéro
    int tousZeros = 1;
    for (int i = 0; i < nouvelleTaille; i++) {
        if (resultat.Tdigits[i] != 0) {
            tousZeros = 0;
            break;
        }
    }
    if (tousZeros) resultat.Signe = 0;
    
    return resultat;
}

// ============================================================================
// FONCTIONS DE COMPARAISON
// ============================================================================

// Teste l'égalité de deux BigBinary
bool Egal(BigBinary A, BigBinary B) {
    // Si les signes sont différents
    if (A.Signe != B.Signe) {
        return false;
    }
    
    // Si les deux sont nuls
    if (A.Signe == 0 && B.Signe == 0) {
        return true;
    }
    
    // Compter les bits significatifs
    int tailleA = compterBitsSignificatifs(A);
    int tailleB = compterBitsSignificatifs(B);
    
    if (tailleA != tailleB) {
        return false;
    }
    
    // Comparer les bits significatifs
    int debutA = A.Taille - tailleA;
    int debutB = B.Taille - tailleB;
    
    for (int i = 0; i < tailleA; i++) {
        if (A.Tdigits[debutA + i] != B.Tdigits[debutB + i]) {
            return false;
        }
    }
    
    return true;
}

// Teste si A < B (pour A et B positifs)
bool Inferieur(BigBinary A, BigBinary B) {
    // Cas avec les signes
    if (A.Signe == 0 && B.Signe == 1) return true;
    if (A.Signe == 1 && B.Signe == 0) return false;
    if (A.Signe == 0 && B.Signe == 0) return false;
    
    // Compter les bits significatifs
    int tailleA = compterBitsSignificatifs(A);
    int tailleB = compterBitsSignificatifs(B);
    
    // Si A a moins de bits que B, alors A < B
    if (tailleA < tailleB) return true;
    if (tailleA > tailleB) return false;
    
    // Même nombre de bits, comparer bit par bit
    int debutA = A.Taille - tailleA;
    int debutB = B.Taille - tailleB;
    
    for (int i = 0; i < tailleA; i++) {
        if (A.Tdigits[debutA + i] < B.Tdigits[debutB + i]) return true;
        if (A.Tdigits[debutA + i] > B.Tdigits[debutB + i]) return false;
    }
    
    return false;
}

// ============================================================================
// OPÉRATIONS ARITHMÉTIQUES
// ============================================================================

// Addition de deux BigBinary positifs
BigBinary Addition(BigBinary A, BigBinary B) {
    // Déterminer la taille maximale + 1 pour la retenue
    int maxTaille = (A.Taille > B.Taille) ? A.Taille : B.Taille;
    BigBinary resultat = initBigBinary(maxTaille + 1, 1);
    
    int retenue = 0;
    int i = A.Taille - 1;
    int j = B.Taille - 1;
    int k = resultat.Taille - 1;
    
    // Addition bit par bit de droite à gauche
    while (i >= 0 || j >= 0 || retenue > 0) {
        int bitA = (i >= 0) ? A.Tdigits[i] : 0;
        int bitB = (j >= 0) ? B.Tdigits[j] : 0;
        
        int somme = bitA + bitB + retenue;
        resultat.Tdigits[k] = somme % 2;
        retenue = somme / 2;
        
        i--;
        j--;
        k--;
    }
    
    // Supprimer les zéros de tête
    BigBinary resultatFinal = supprimerZerosDeTete(resultat);
    libereBigBinary(&resultat);
    
    return resultatFinal;
}

// Soustraction A - B (avec A >= B positifs)
BigBinary Soustraction(BigBinary A, BigBinary B) {
    // Vérifier que A >= B
    if (Inferieur(A, B)) {
        printf("Erreur: A doit être >= B pour la soustraction\n");
        return initBigBinary(1, 0);
    }
    
    BigBinary resultat = initBigBinary(A.Taille, 1);
    
    int emprunt = 0;
    int i = A.Taille - 1;
    int j = B.Taille - 1;
    int k = resultat.Taille - 1;
    
    // Soustraction bit par bit de droite à gauche
    while (i >= 0) {
        int bitA = A.Tdigits[i];
        int bitB = (j >= 0) ? B.Tdigits[j] : 0;
        
        int diff = bitA - bitB - emprunt;
        
        if (diff < 0) {
            diff += 2;
            emprunt = 1;
        } else {
            emprunt = 0;
        }
        
        resultat.Tdigits[k] = diff;
        
        i--;
        j--;
        k--;
    }
    
    // Supprimer les zéros de tête
    BigBinary resultatFinal = supprimerZerosDeTete(resultat);
    libereBigBinary(&resultat);
    
    return resultatFinal;
}

// Division par 2 (décalage à droite)
void divisePar2(BigBinary *nb) {
    if (nb->Signe == 0 || nb->Taille == 0) {
        return;
    }
    
    // Si le nombre est 1, il devient 0
    if (nb->Taille == 1 && nb->Tdigits[0] == 1) {
        nb->Tdigits[0] = 0;
        nb->Signe = 0;
        return;
    }
    
    // Créer un nouveau tableau avec une taille réduite de 1
    int nouvelleTaille = nb->Taille - 1;
    if (nouvelleTaille <= 0) {
        nb->Taille = 1;
        nb->Tdigits[0] = 0;
        nb->Signe = 0;
        return;
    }
    
    int *nouveauxDigits = malloc(sizeof(int) * nouvelleTaille);
    
    // Copier les bits en supprimant le dernier (LSB)
    for (int i = 0; i < nouvelleTaille; i++) {
        nouveauxDigits[i] = nb->Tdigits[i];
    }
    
    free(nb->Tdigits);
    nb->Tdigits = nouveauxDigits;
    nb->Taille = nouvelleTaille;
}
