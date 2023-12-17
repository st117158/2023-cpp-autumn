#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int my_strcmp(char* a, char* b)
{
    int len1 = strlen(a);
    int len2 = strlen(b);
    int res = 0;
    if (len1 == len2)
    {
        res = 0;
    }
    if (len1 > len2)
    {
        res = len1 - len2;
    }
    if (len2 > len1)
    {
        res = len2 - len1;
    }
    return res;
}



int main(int argc, char* argv[])
{
	FILE* f = fopen("in.txt", "r");

	char a[255];
	fscanf(f, "%s", &a);
	char b[255];
	fscanf(f,"%s",&b);
	fclose(f);
    int res1 = my_strcmp(a,b);

	f = fopen("out.txt", "w");

    if (res1 > 0) {
        fprintf(f,"%s", "a is more than b");
    }
    else if (res1 < 0) {
        fprintf(f,"%s", "a is less than b");
    }
    else {
        fprintf(f,"%s", "a is equal to b");
    }

	fclose(f);
	return 0;
}

