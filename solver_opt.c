/*
 * Tema 2 ASC
 * 2022 Spring
 */
#include "utils.h"

#define MAX(A, B) (A > B ? A : B)

/*
 * Add your optimized implementation here
 */

/*
 * Basic function for computing the transpose of a matrix.
 * Optimized using pointers and loop unrolling.
 */
double *transpose(int N, double *A) {
    double *At = (double *)calloc(N * N, sizeof(double));
    if (!At) {
        return NULL;
    }

    for (register int i = 0; i < N; ++i) {
        double *pA = &A[i * N + 0];
        double *pAt = &At[0 * N + i];
        for (register int j = 0; j < N; j += 40) {
            *pAt = *pA;
            *(pAt + N) = *(pA + 1);
            *(pAt + 2 * N) = *(pA + 2);
            *(pAt + 3 * N) = *(pA + 3);
            *(pAt + 4 * N) = *(pA + 4);
            *(pAt + 5 * N) = *(pA + 5);
            *(pAt + 6 * N) = *(pA + 6);
            *(pAt + 7 * N) = *(pA + 7);
            *(pAt + 8 * N) = *(pA + 8);
            *(pAt + 9 * N) = *(pA + 9);
            *(pAt + 10 * N) = *(pA + 10);
            *(pAt + 11 * N) = *(pA + 11);
            *(pAt + 12 * N) = *(pA + 12);
            *(pAt + 13 * N) = *(pA + 13);
            *(pAt + 14 * N) = *(pA + 14);
            *(pAt + 15 * N) = *(pA + 15);
            *(pAt + 16 * N) = *(pA + 16);
            *(pAt + 17 * N) = *(pA + 17);
            *(pAt + 18 * N) = *(pA + 18);
            *(pAt + 19 * N) = *(pA + 19);
            *(pAt + 20 * N) = *(pA + 20);
            *(pAt + 21 * N) = *(pA + 21);
            *(pAt + 22 * N) = *(pA + 22);
            *(pAt + 23 * N) = *(pA + 23);
            *(pAt + 24 * N) = *(pA + 24);
            *(pAt + 25 * N) = *(pA + 25);
            *(pAt + 26 * N) = *(pA + 26);
            *(pAt + 27 * N) = *(pA + 27);
            *(pAt + 28 * N) = *(pA + 28);
            *(pAt + 29 * N) = *(pA + 29);
            *(pAt + 30 * N) = *(pA + 30);
            *(pAt + 31 * N) = *(pA + 31);
            *(pAt + 32 * N) = *(pA + 32);
            *(pAt + 33 * N) = *(pA + 33);
            *(pAt + 34 * N) = *(pA + 34);
            *(pAt + 35 * N) = *(pA + 35);
            *(pAt + 36 * N) = *(pA + 36);
            *(pAt + 37 * N) = *(pA + 37);
            *(pAt + 38 * N) = *(pA + 38);
            *(pAt + 39 * N) = *(pA + 39);
            pA += 40;
            pAt += 40 * N;
        }
    }

    return At;
}

/*
 * Function for multiplying an upper triangular matrix with its transpose.
 * Optimized using pointers.
 */
double *multiply_upper_triangular_with_transpose(int N, double *A) {
    double *res = (double *)calloc(N * N, sizeof(double));
    if (!res) {
        return NULL;
    }

	// res = A * At
    for (register int i = 0; i < N; ++i) {
        double *orig_pA = &A[i * N + 0];
        for (register int j = 0; j < N; ++j) {
            double *pA = orig_pA + MAX(i, j);
            double *pAt = &A[j * N + MAX(i, j)];
            register double sum = 0;
            for (register int k = MAX(i, j); k < N; ++k) {
                sum += *pA * *pAt;
                pA++;
                pAt++;
            }

            res[i * N + j] = sum;
        }
    }

    return res;
}

/*
 * Function for computing the matrix equation provided.
 * Optimized using pointers and loop unrolling.
 */
double *
compute_result(int N, double *B, double *A_At, double *B_t) {
    double *res = (double *)calloc(N * N, sizeof(double));
    if (!res) {
        return NULL;
    }

	// res = B * A_At + Bt * B = B * A * At + Bt * B
    for (register int i = 0; i < N; ++i) {
        double *orig_pB = &B[i * N + 0];
        double *orig_pB_t = &B_t[i * N + 0];
        for (register int j = 0; j < N; ++j) {

            double *pB1 = orig_pB;
            double *pA_At = &A_At[j * N + 0];

            double *pB_t = orig_pB_t;
            double *pB2 = &B_t[j * N + 0];

            register double sum = 0;
            for (register int k = 0; k < N; k += 40) {
                sum += *pB1 * *pA_At + *pB_t * *pB2;
                sum += *(pB1 + 1) * *(pA_At + 1) + *(pB_t + 1) * *(pB2 + 1);
                sum += *(pB1 + 2) * *(pA_At + 2) + *(pB_t + 2) * *(pB2 + 2);
                sum += *(pB1 + 3) * *(pA_At + 3) + *(pB_t + 3) * *(pB2 + 3);
                sum += *(pB1 + 4) * *(pA_At + 4) + *(pB_t + 4) * *(pB2 + 4);
                sum += *(pB1 + 5) * *(pA_At + 5) + *(pB_t + 5) * *(pB2 + 5);
                sum += *(pB1 + 6) * *(pA_At + 6) + *(pB_t + 6) * *(pB2 + 6);
                sum += *(pB1 + 7) * *(pA_At + 7) + *(pB_t + 7) * *(pB2 + 7);
                sum += *(pB1 + 8) * *(pA_At + 8) + *(pB_t + 8) * *(pB2 + 8);
                sum += *(pB1 + 9) * *(pA_At + 9) + *(pB_t + 9) * *(pB2 + 9);
                sum += *(pB1 + 10) * *(pA_At + 10) + *(pB_t + 10) * *(pB2 + 10);
                sum += *(pB1 + 11) * *(pA_At + 11) + *(pB_t + 11) * *(pB2 + 11);
                sum += *(pB1 + 12) * *(pA_At + 12) + *(pB_t + 12) * *(pB2 + 12);
                sum += *(pB1 + 13) * *(pA_At + 13) + *(pB_t + 13) * *(pB2 + 13);
                sum += *(pB1 + 14) * *(pA_At + 14) + *(pB_t + 14) * *(pB2 + 14);
                sum += *(pB1 + 15) * *(pA_At + 15) + *(pB_t + 15) * *(pB2 + 15);
                sum += *(pB1 + 16) * *(pA_At + 16) + *(pB_t + 16) * *(pB2 + 16);
                sum += *(pB1 + 17) * *(pA_At + 17) + *(pB_t + 17) * *(pB2 + 17);
                sum += *(pB1 + 18) * *(pA_At + 18) + *(pB_t + 18) * *(pB2 + 18);
                sum += *(pB1 + 19) * *(pA_At + 19) + *(pB_t + 19) * *(pB2 + 19);
                sum += *(pB1 + 20) * *(pA_At + 20) + *(pB_t + 20) * *(pB2 + 20);
                sum += *(pB1 + 21) * *(pA_At + 21) + *(pB_t + 21) * *(pB2 + 21);
                sum += *(pB1 + 22) * *(pA_At + 22) + *(pB_t + 22) * *(pB2 + 22);
                sum += *(pB1 + 23) * *(pA_At + 23) + *(pB_t + 23) * *(pB2 + 23);
                sum += *(pB1 + 24) * *(pA_At + 24) + *(pB_t + 24) * *(pB2 + 24);
                sum += *(pB1 + 25) * *(pA_At + 25) + *(pB_t + 25) * *(pB2 + 25);
                sum += *(pB1 + 26) * *(pA_At + 26) + *(pB_t + 26) * *(pB2 + 26);
                sum += *(pB1 + 27) * *(pA_At + 27) + *(pB_t + 27) * *(pB2 + 27);
                sum += *(pB1 + 28) * *(pA_At + 28) + *(pB_t + 28) * *(pB2 + 28);
                sum += *(pB1 + 29) * *(pA_At + 29) + *(pB_t + 29) * *(pB2 + 29);
                sum += *(pB1 + 30) * *(pA_At + 30) + *(pB_t + 30) * *(pB2 + 30);
                sum += *(pB1 + 31) * *(pA_At + 31) + *(pB_t + 31) * *(pB2 + 31);
                sum += *(pB1 + 32) * *(pA_At + 32) + *(pB_t + 32) * *(pB2 + 32);
                sum += *(pB1 + 33) * *(pA_At + 33) + *(pB_t + 33) * *(pB2 + 33);
                sum += *(pB1 + 34) * *(pA_At + 34) + *(pB_t + 34) * *(pB2 + 34);
                sum += *(pB1 + 35) * *(pA_At + 35) + *(pB_t + 35) * *(pB2 + 35);
                sum += *(pB1 + 36) * *(pA_At + 36) + *(pB_t + 36) * *(pB2 + 36);
                sum += *(pB1 + 37) * *(pA_At + 37) + *(pB_t + 37) * *(pB2 + 37);
                sum += *(pB1 + 38) * *(pA_At + 38) + *(pB_t + 38) * *(pB2 + 38);
                sum += *(pB1 + 39) * *(pA_At + 39) + *(pB_t + 39) * *(pB2 + 39);
                pB1 += 40;
                pA_At += 40;
                pB_t += 40;
                pB2 += 40;
            }

            res[i * N + j] = sum;
        }
    }
    return res;
}

double* my_solver(int N, double *A, double* B) {
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

    // res = B * A_At + Bt * B = B * A * At + Bt * B 
	double *res = compute_result(N, B, A_At, Bt);

    free(Bt);
    free(A_At);

    return res;
}
