/*
 * Tema 2 ASC
 * 2023 Spring
 */
#include "utils.h"

#include "cblas.h"

/* 
 * Add your BLAS implementation here
 */
double* my_solver(int N, double *A, double *B) {

	double *BtBt = (double*) malloc(N * N * sizeof(double));
	cblas_dgemm(CblasRowMajor, CblasTrans, CblasTrans, N, N, N, 1.0, B, N, B, N, 0.0, BtBt, N); // Save Bt * Bt in BtBt
	cblas_dtrmm(CblasRowMajor, CblasLeft, CblasUpper, CblasNoTrans, CblasNonUnit, N, N, 1.0, A, N, B, N); // Save A * B in B
	cblas_dtrmm(CblasRowMajor, CblasRight, CblasUpper, CblasTrans, CblasNonUnit, N, N, 1.0, A, N, B, N); // Save A * B * At in B
	cblas_daxpy(N * N, 1.0, B, 1, BtBt, 1);

	//printf("BLAS SOLVER\n");
	return BtBt;
}