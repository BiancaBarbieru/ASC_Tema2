/*
 * Tema 2 ASC
 * 2023 Spring
 */
#include "utils.h"

/*
 * Add your unoptimized implementation here
 */
double* my_solver(int N, double *A, double* B) {
	register int i, j, k;
	register double *At = (double*) malloc(N * N * sizeof(double));
	register double *Bt = (double*) malloc(N * N * sizeof(double));
	register double *AB = (double*) malloc(N * N * sizeof(double));
	register double *ABAt = (double*) malloc(N * N * sizeof(double));
	register double *BtBt = (double*) malloc(N * N * sizeof(double));
	register double *result = (double*) malloc(N * N * sizeof(double));


	// Transpose A and B
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++)
			{
				register int idx = j * N +i;
				register double auxA = A[idx];
				register double auxB = B[idx];
				At[i * N + j] = auxA;
				Bt[i * N + j] = auxB;
			}
	}


	// Multiply A by B
	for(i = 0; i < N; i++){
		register double *orig_pa = &A[i * N];
		for(j = 0; j < N; j++)
			{
				register double *pa = &orig_pa[i];
				register double *pb = &B[i * N + j];
				register double sum = 0;
				for(k = i; k < N; k++){
					sum += *pa * *pb;
					pa++;
					pb += N;
				}

			AB[i * N + j] = sum;
		}
	}

	// Multiply AB by At
	for(i = 0; i < N; i++){
		register double *orig_pa = &AB[i * N];
		for(j = 0; j < N; j++)
			{
				register double *pa = &orig_pa[j];
				register double *pb = &At[j * N + j];
				register double sum = 0;
				for(k = j; k < N ; k++){
					sum += *pa * *pb;
					pa ++;
					pb += N;
				}

			ABAt[i * N + j] = sum;
		}
	}
	// Free At
	free(At);
	free(AB);

	// Multiply Bt by Bt
	for(i = 0; i < N; i++) {
		register double *orig_pa = &Bt[i * N];
 		for(j = 0; j < N; j++) {
			register double *pa = orig_pa;
			register double *pb = &Bt[j];
			register double sum = 0;
    		for(k = 0; k < N; k++) { 
				sum += *pa * *pb;
				pa++;
				pb += N;
    		}
			BtBt[i * N + j] = sum;
  		}	
	}

	// Free Bt
	free(Bt);

	// Sum ABAt and BtBt
	for(i = 0; i < N; i++) {
  		for(j = 0; j < N; j++) {
			register int idx = i * N + j;
			register double auxABAt = ABAt[idx];
			register double auxBtBt = BtBt[idx];
   			result[idx] = auxABAt + auxBtBt ;
  		}
	}

	// Free ABAt
	free(ABAt);
	// Free BtBt
	free(BtBt);

	//printf("OPT SOLVER\n");
	return result;
}