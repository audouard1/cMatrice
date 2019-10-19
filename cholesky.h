#ifndef H_CHOLES
#define H_CHOLES

int decomp_cholesky(float *tab, float decomp, int N);
void equation1(float *tab, float *res, float *y, int N);
void equation2(float *tab, float *res, float *y, int N);
int cholesky(float *tab, float *res, int N);

#endif