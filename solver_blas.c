/*
 * Tema 2 ASC
 * 2022 Spring
 */
#include "utils.h"
#include "cblas.h"
#include <string.h>

/* 
 * Add your BLAS implementation here
 */
double *my_solver(int N, double *A, double *B) {
    double *A_At = (double *) calloc(N * N, sizeof(double));
    if (!A_At) {
        return NULL;
    }

	// Copy A's content in A_At.
    memcpy(A_At, A, N * N * sizeof(double));

	/* 
	 * Multiply A with it's transpose and store it in A_At.
	 * A_At = A * At
	 */
    cblas_dtrmm(CblasRowMajor, CblasRight, CblasUpper, CblasTrans, CblasNonUnit,
                N, N, 1, A, N, A_At, N);

    double *res = (double *) calloc(N * N, sizeof(double));
    if (!res) {
        return NULL;
    }

	/*
	 * Multiply B with A_At and store it in res.
	 * res = B * A_At = B * A * At
	 */
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, N, N, N, 1, B, N, A_At,
                N, 1, res, N);

    double *Bt = (double *) calloc(N * N, sizeof(double));
    if (!res) {
        return NULL;
    }

	// Copy B's content in Bt.
    memcpy(Bt, B, N * N * sizeof(double));

	/*
	 * Multiply B's transpose with B and add it to res.
	 * res = B * Bt + res = B * Bt + B * A * At
	 */
    cblas_dgemm(CblasRowMajor, CblasTrans, CblasNoTrans, N, N, N, 1, B, N, Bt, N,
                1, res, N);

    free(A_At);
    free(Bt);

    return res;
}
