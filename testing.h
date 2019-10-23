#ifndef H_TESTING
#define H_TESTING

double error(double tab[], double res[], int N);
void test_gauss();
void gauss_testing_core(int maxDim, double tab[], double res[]);
void cholesky_testing_core(int maxDim, double tab[], double res[]);
void test_cholesky();
void test_gauss_Dyn(int maxDim);
void test_cholesky_Dyn(int maxDim);

#endif