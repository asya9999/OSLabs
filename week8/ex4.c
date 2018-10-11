#include <stdio.h>
#include <time.h> 
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>

int main(){

	time_t start = time(NULL);
	struct rusage usage;

	while((time(NULL) - start) < 10){
		int mem_size = 1024 * 10 * sizeof(char);
		void * pointer = malloc(mem_size); 
		memset(pointer, 0, mem_size);
		
		getrusage(RUSAGE_SELF, &usage); 
		printf("Memory usage = %ld\n",usage.ru_maxrss);
		sleep(1);
	}

	return 0;
}