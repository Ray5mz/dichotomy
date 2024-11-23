#include <stdio.h>
#include <math.h>
#include "tinyexpr.h"

typedef struct {  //on fait un enrengistrement pour stocker les resultat dans un element d'un tableau dans chaque iteration
    int n;
    double a, b, xn, fxn;
    char S[2];  // chaine de charactere pour stocker les resultats de comparaison
} Result;

int main() {
    char expression[100];
    float p, n;
    double a, b, d, x, fa, fxn, xn;
    char T[6][11] = {
        "n",
        "an",
        "bn",
        "xn",
        "f(xn)",
        "f(an).f(xn)"
    };
    
    Result M[50];  // Only need a single dimension for M
    
    // Get user input for the function
    printf("Entrez la fonction f(x)\n");
    fgets(expression, sizeof(expression), stdin); //une fonction pour lire la fonction entree par l'utilisateur
    int err;
    
    // Compiler la fonction en utilisant la bibliotheque TinyExpr
    te_variable vars[] = {{"x", &x}};
    te_expr *expr = te_compile(expression, vars, 1, &err);
    if (!expr) {
        printf("Erreur dans la fonction à la position %d\n", err);
        return 1;
    }

    
    printf("Entrez l'intervalle du résultat\n"); 
    do {
        printf("a = ");
        scanf("%lf", &a);
        printf("b = ");
        scanf("%lf", &b);
        if (a >= b) {
            printf("Erreur, mettez les bonnes valeurs de l'intervalle\n");
        }
    } while (a >= b);


    printf("Entrez la précision : ");
    scanf("%f", &p);

    // calculer le nombre d'iterations 
    d = b - a;
    n = (log(fabs(d) / p) / log(2)) - 1;
    n = floor(n); //floor cest une fonction de la partie entiere E(x)

    //faire une boucle pour calculer les resultats jusqu'a arriver a l'iteration n
    for (int i = 0; i < n; i++) {
        d = b + a;
        xn = d / 2;

        // calculer f(a)
        x = a;
        fa = te_eval(expr); //une expressio pour cacluler l'image de a en utilisant la bibliotheque tinyexpr
        
        // Evaluate f(xn)
        x = xn;
        fxn = te_eval(expr);//une expressio pour cacluler l'image de xn en utilisant la bibliotheque tinyexpr 

        // Store results in the matrix
        M[i].n = i;
        M[i].a = a;
        M[i].b = b;
        M[i].xn = xn;
        M[i].fxn = fxn;

        // comparer les tesulatat et choisir les nouvelle bornes de l'intervalle
        if (fa * fxn > 0) {
            a = xn;
            snprintf(M[i].S, sizeof(M[i].S), ">0");
        } else {
            b = xn;
            snprintf(M[i].S, sizeof(M[i].S), "<0");
        }
    }

    // libereer ou supprimer l'expression pour ne pas consommer l'espace memoire
    te_free(expr);

    // affichage du tableau des resulats
    printf("\nTableau des résultats :\n");
    printf("| %2s | %8s | %8s | %8s | %8s | %8s |\n", T[0], T[1], T[2], T[3], T[4], T[5]);
    for (int i = 0; i < n; i++) {
        printf("| %2d | %8.4lf | %8.4lf | %8.4lf | %8.4lf | %8s |\n",
               M[i].n, M[i].a, M[i].b, M[i].xn, M[i].fxn, M[i].S);
    }

    
    printf("\nLa solution approchée est x = %.8lf\n", xn);

    return 0;
}

