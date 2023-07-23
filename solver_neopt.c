/*
 * Tema 2 ASC
 * 2022 Spring
 */
#include "utils.h"

#define MAX(A, B) (A > B ? A : B)

/*
 * Add your unoptimized implementation here
 */

// Basic function for computing the transpose of a matrix.
double *transpose(int N, double *A) {
    double *At = (double *) calloc(N * N, sizeof(double));
    if (!At) {
        return NULL;
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            At[i * N + j] = A[j * N + i];
        }
    }

    return At;
}

// Function for multiplying an upper triangular matrix with its transpose.
double *multiply_upper_triangular_with_transpose(int N, double *A) {
    double *At = transpose(N, A);
    if (!At) {
        return NULL;
    }
    
    double *res = (double *) calloc(N * N, sizeof(double));
    if (!res) {
        return NULL;
    }

    // res = A * At
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = MAX(i, j); k < N; ++k) {
                res[i * N + j] += A[i * N + k] * At[k * N + j];
            }
        }
    }
    
    free(At);
    
    return res;
}

double *my_solver(int N, double *A, double *B) {
	// A_At = A * At
    double *A_At = multiply_upper_triangular_with_transpose(N, A);
    if (!A_At) {
        return NULL;
    }

    // Bt
    double *Bt = transpose(N, B);
    if (!Bt) {
        return NULL;
    }

    double *res = (double *) calloc(N * N, sizeof(double));
    if (!res) {
        return NULL;
    }

	// res = B * A_At + Bt * B = B * A * At + Bt * B
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                res[i * N + j] += B[i * N + k] * A_At[j * N + k] +
                                Bt[i * N + k] * B[k * N + j];
            }
        }
    }
    
    free(Bt);
    free(A_At);

    return res;
}
