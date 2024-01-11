/*
 * Tema 2 ASC
 * 2023 Spring
 */
#include "utils.h"

/*
 * Add your unoptimized implementation here
 */
double* my_solver(int N, double *A, double* B) {
	int i, j, k;
	double *At = (double*) malloc(N * N * sizeof(double));
	double *Bt = (double*) malloc(N * N * sizeof(double));
	double *AB = (double*) malloc(N * N * sizeof(double));
	double *ABAt = (double*) malloc(N * N * sizeof(double));
	double *BtBt = (double*) malloc(N * N * sizeof(double));
	double *result = (double*) malloc(N * N * sizeof(double));


	// Transpose A and B
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++)
			{
				At[i * N + j] = A[j * N + i];
				Bt[i * N + j] = B[j * N + i];
			}
	}

	// Multiply A by B
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			double sum = 0.0;
			for(k = i; k < N; k++){
				sum += A[i * N + k] * B[k * N + j];
			}
			AB[i * N + j] = sum;
		}
	}

	// Multiply AB by At
	for(i = 0; i < N; i++) {
 		for(j = 0; j < N; j++) {
    		double sum = 0.0;
    		for(k = j; k < N; k++) { 
      		sum += AB[i * N + k] * At[k * N + j];
    		}
    		ABAt[i * N + j] = sum;
  		}	
	}

	

	// Free At
	free(At);
	free(AB);

	// Multiply Bt by Bt
	for(i = 0; i < N; i++) {
 		for(j = 0; j < N; j++) {
			double sum = 0.0;
    		for(k = 0; k < N; k++) { 
      			sum += Bt[i * N + k] * Bt[k * N + j];
    		}
			BtBt[i * N + j] = sum;
  		}	
	}

	// Free Bt
	free(Bt);

	// Sum ABAt and BtBt
	for(i = 0; i < N; i++) {
  		for(j = 0; j < N; j++) {
   			result[i * N + j] = ABAt[i * N + j] + BtBt[i * N + j];
  		}
	}

	// Free ABAt
	free(ABAt);
	// Free BtBt
	free(BtBt);

	//printf("NEOPT SOLVER\n");
	return result;
}