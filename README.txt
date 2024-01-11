======= Homework Optimization =======

Bărbieru Bianca-Ștefania 334CC

In the Neopt method I transpose matrix A and B using a temporary array At for A
and a temporary array Bt for B. After that I multimply matrix A and B and I save 
it in a temporary array AB, I multiply matrix AB and At saving the result in a 
temporary array ABAt. I multiply Bt and Bt in a temporary array BtBt. Finally,
I sum ABAt and BtBt in result. Free AB and At after the ABAt operation, free
Bt after the BtBt operation, free ABAt and BtBt after the result operation.
    Run=./tema2_neopt: N=400: Time=0.798784
    Run=./tema2_neopt: N=600: Time=2.845986
    Run=./tema2_neopt: N=800: Time=6.837850
    Run=./tema2_neopt: N=1000: Time=12.067501
    Run=./tema2_neopt: N=1200: Time=22.815290

In the Opt_m method the code first transposes A and B using nested for-loops, 
and then multiplies A by B using three nested for-loops to compute AB. Next, it 
multiplies AB by At using three nested for-loops to compute ABAt, and then 
multiplies Bt by B using three nested for-loops to compute BtBt. Finally, it 
sums ABAt and BtBt element-wise to obtain the result matrix.
The code makes use of several optimizations, such as register variables to 
reduce memory access time, and loop unrolling to reduce loop overhead. The use
of pointers also helps to optimize memory access.
    Run=./tema2_opt_m: N=400: Time=0.342421
    Run=./tema2_opt_m: N=600: Time=1.185545
    Run=./tema2_opt_m: N=800: Time=3.021206
    Run=./tema2_opt_m: N=1000: Time=4.859737
    Run=./tema2_opt_m: N=1200: Time=9.447908

In the Blas method I use cblas_dgemm to calculate Bt * Bt (the transpose of B 
multiplied by itself) and store it in BtBt, and uses cblas_dtrmm to calculate 
A * B in B, and AB (which is now in B) * At in B, and cblas_daxpy to calculate 
ABAt(which is now in B) + BtBt and save it in BtBt.
    Run=./tema2_blas: N=400: Time=0.187005
    Run=./tema2_blas: N=600: Time=1.422167
    Run=./tema2_blas: N=800: Time=1.410682
    Run=./tema2_blas: N=1000: Time=2.712342
    Run=./tema2_blas: N=1200: Time=4.678195

Analyze using cachegrind:
    I refs: Number of instruction references for neopt > opt_m > blas, blass
        beeing less than half of opt_m
    D refs: Number of data references for neopt > opt_m > blas, opt_m beeing 
        almost quarter of neopt
    Branches: Number of branches executed is quite similar
