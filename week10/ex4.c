#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main() {
	DIR *dirp = opendir("./tmp");
	if (dirp == NULL) return 1;

	char path[1000];		

	struct dirent* dp;
	while ((dp = readdir(dirp)) != NULL) {
	    
		sprintf(path, "%s/%s", "./tmp", dp->d_name);
		struct stat sdata;
		stat(path, &sdata);
		
		if (sdata.st_nlink >= 2 && strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0){
			    printf("File: %s\n", dp->d_name);
			    
	            DIR *dir = opendir("./tmp");
	            if (dir == NULL) return 1;

	            char file_path[1000];		
	            struct stat data;	

	            struct dirent* dp1;
	            while ((dp1 = readdir(dir)) != NULL) {
		            sprintf(file_path, "%s/%s", "./tmp", dp1->d_name);
		            stat(file_path, &data);
		            if (data.st_ino == sdata.st_ino) printf("%s\n", dp1->d_name);
	            }
			}
	}

	return 0;
}