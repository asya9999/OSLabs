#include <stdio.h>
#include <stdlib.h>

int main(){

	int N;
	scanf("%d", &N);
	int *ar = malloc(N*sizeof(int));
	int i;
	for (i = 0; i < N; i++){
		ar[i] = i;
		printf("%d ", ar[i]);
	}
	printf("\n");
	free(ar);
	return 0;
}