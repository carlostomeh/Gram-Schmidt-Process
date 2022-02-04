#include <stdio.h>
#include <math.h>

/* Retorna o produto interno entre os vetores coluna */
 
double dot_product(double *x, double *y, int j) {
 
    double ans = 0;
 
    for(i=0; i<j; ++i)
        ans += x[i]*y[i];
 
    return ans;
}
 

/* Retorna a matriz normalizada */

void normalize(double *x) {
 
    /* Compute norm */
    double norm = sqrt(dot_product(x, x, 4));
    
    int i;
    for(i=0; i<4; ++i)
        x[i] /= norm;
}
 
/* Encontra a base ortonormal para o conjunto q
 * Usando o algoritmo Gram-Schmidt Orthogonalizacao */

void gram_schimdt(double q[][4], int n) {
 
    int i, j, k;

 
    for(i=1; i<n; ++i) {
        for(j=0; j<i; ++j) {
            double scaling_factor = dot_product(q[j], q[i], 4) / dot_product(q[j], q[j], 4);
            
            /* Subtract each scaled component of q_j from q_i */
            for(k=0; k<4; ++k)
                q[i][k] -= scaling_factor*q[j][k];
        }
    }
 
    /* Now normalize all the 'n' orthogonal vectors */
    for(i=0; i<n; ++i)
        normalize(q[i]);
}
 
int main() {
 
/* Escrevendo a matriz de interesse */

    double arr[][4] = {
        { 1, 2, 3, 0},
        {1, 2, 0, 0},
        {1, 0, 0, 1}
    };
 

 /* Aplica gram_schmidt para a matriz arr com 3 linhas */
 
    gram_schimdt(arr, 3);
    printf("Orthonormal basis :\n");
 
 
 /* Imprimindo a linha i na coluna j */
 
    for(int i=0; i<3; ++i) {
        printf("q[%d] = [ ", i);
        for(int j=0; j<4; ++j)
            printf("%lf  ", arr[i][j]);
        printf("]\n");
    }
}