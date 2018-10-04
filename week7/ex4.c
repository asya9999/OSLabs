#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *m_realloc(void *ptr, size_t new_size, size_t old_size){
	void *new_ptr;
	if(ptr == NULL){
		ptr = malloc(new_size);
	}
	else if(new_size == 0){
		free(ptr);
	}
	else{
		new_ptr = malloc(new_size);
		if(new_size > old_size)
		{
		memcpy(new_ptr, ptr, old_size);	
		}
		else{
		memcpy(new_ptr, ptr, new_size);}
		
		free(ptr);
	}
	return new_ptr;
}

int main(){

	printf("Size of array\n");
	int size1=0;
	scanf("%d",&size1);
	int* array = malloc(size1 * sizeof(int));
	int i;
	for(i=0; i<size1; i++){
		array[i]=1;
		printf("%d ", array[i]);
	}

	printf("\nNew size:\n");
	int size2=0;
	scanf("%d",&size2);

	array = m_realloc(array, size2 * sizeof(int), size1 * sizeof(int));

	if(size2 > size1){
		for(i = size1; i < size2; i++){
			array[i] = 0;
		}	
	}

	for(i=0; i<size2;i++){
		printf("%d ",array[i]);
	}

	return 0;
}