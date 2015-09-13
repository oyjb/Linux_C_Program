/**********************************************************
 * Author        : oyjb
 * Email         : jbouyang@126.com
 * Last modified : 2015-09-13 22:37
 * Filename      : my_ls.c
 * Description   : copy right for oyjb
 * *******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>

#define MAX 1024

void my_ls(char *root);

int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		printf("%s\n","wrong usage.");
		exit(1);
	}

	my_ls(argv[1]);

	exit(0);
}

void my_ls(char *root)
{
	DIR *dir; // get directry's information,then get every file and directry
	struct dirent *ptr;
	int count;

	dir = opendir(root); //open directory
	if (dir == NULL)
	{
		perror("fail to open dir");
		exit(1);
	}

	errno = 0;
	while ((ptr = readdir(dir)) != NULL) //Sequential read every dirent
	{
		if (strcmp(ptr->d_name, ".") == 0 || strcmp(ptr->d_name, "..") == 0)
			continue;
		printf("%s\t", ptr->d_name); //print file's name

		++count;
		if (count % 5 == 0)
			printf("\n");
	}

	if (errno != 0)
	{
		perror("fail to read dir");
		exit(1);
	}

	closedir(dir); //close dir
}
