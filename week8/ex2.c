#include <stdio.h>
#include <time.h> 
#include <stdlib.h>
#include <string.h>

int main(){

	time_t start = time(NULL);

	while((time(NULL) - start) < 10){
		int num = 1024 * 10 * sizeof(char);
		void *array = malloc(num); // allocate 10 MB
		memset(array, '0', num);
		sleep(1);
	}
	return 0;
}
