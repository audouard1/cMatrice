#ifndef H_CHOLES
#define H_CHOLES

int decomp_cholesky(double *tab, double decomp, int N);
void equation1(double *tab, double *res, double *y, int N);
void equation2(double *tab, double *res, double *y, int N);
int cholesky(double *tab, double *res, int N);

#endif