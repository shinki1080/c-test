#include <stdio.h>
#include <stdlib.h>

#define M 10
#define N 10
#define MaxEof 32768

void main(void) {

	int i, j, p,q;
	int  a[M], 
		 b[N], 
	 	 c[M + N];

	printf("1つ目の乱数\n");
	for (i = 0; i < M; i++)
		a[i] = rand();
	for (i = 0; i < M; i++)
		printf("%d ", a[i]);
	printf("\n"); printf("\n");

	printf("2つ目の乱数\n");
	for (i = 0; i < M; i++)
		b[i] = rand();
	for (i = 0; i < M; i++)
		printf("%d ", b[i]);
	printf("\n"); printf("\n");

	printf("1つ目の乱数のソート\n");
	for (i = 0; i < M - 1; i++) {
		for (j = M - 1; j > i; j--) {
			if (a[j] < a[j - 1]) {
				q = a[j]; 
				a[j] = a[j - 1]; a[j - 1] = q;
			}
		}
	}
	for (i = 0; i < M; i++)
		printf("%d ", a[i]);
	printf("\n"); printf("\n");
	
	printf("2つ目の乱数のソート\n");
	for (i = 0; i < N - 1; i++) {
		for (j = N - 1; j > i; j--) {
			if (b[j] < b[j - 1]) {
				q = b[j];
				b[j] = b[j - 1]; b[j - 1] = q;
			}
		}
	}
	for (i = 0; i < N; i++)
		printf("%d ", b[i]);
	printf("\n"); printf("\n");

	a[M] = MaxEof; b[N] = MaxEof;

	printf("1つ目と2つ目の乱数を併合したソート\n");
	i = j = p = 0;
	while (a[i] != MaxEof || b[j] != MaxEof) {
		if (a[i] <= b[j])
			c[p++] = a[i++];
		else 
			c[p++] = b[j++];
	}
	for (i = 0; i < M + N; i++)
		printf("%d ", c[i]);
	printf("\n");
}