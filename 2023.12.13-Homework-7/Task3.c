#include <stdio.h>
#include <stdlib.h>
#include<string.h>

char* my_strcat(char* str1, char* str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    for(int i = len1; i < len1 + len2; i++)
    {
        str1[i] = str2[i - len1];
    }
    str1[len1 + len2] = '\0';
    return str1;
}

int main(int argc, char* argv[])
{
	FILE* f = fopen("in.txt", "r");

	char a[255];
	fscanf(f, "%s", &a);
	char b[255];
	fscanf(f,"%s",&b);
	fclose(f);

	f = fopen("out.txt", "w");
	fprintf(f, "%s", my_strcat(a, b));

	fclose(f);

	return 0;
}
