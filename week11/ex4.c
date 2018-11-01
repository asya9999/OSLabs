#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <unistd.h>

int main()
{

	int f1 = open("ex1.txt", O_RDWR, 0);
 	int f2 = open("ex1.memcpy.txt", O_RDWR, 0);	

 	struct stat file_stat;
 	fstat(f1, &file_stat);
 	size_t size = file_stat.st_size;

 	ftruncate(f2, size);

 	char* addr1 = mmap(0, size, PROT_READ, MAP_SHARED, f1, 0);
 	char* addr2 = mmap(0, size, PROT_READ|PROT_WRITE, MAP_SHARED, f2, 0);

 	memcpy(addr2, addr1, size);
    munmap(addr1, size);
    munmap(addr2, size);

    return 0;
    }