#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* my_substr(char* str, int start, int len)
{
    char *sub = (char*)malloc(sizeof(char) * (len + 1));
    memset(sub, 0, (len + 1) * sizeof(char));// зануление массива
    int end = start + len;
    for(int i = start; i < end; i++)
    {
        sub[i - start] = str[i];
    }
    return sub;
}

int main(int argc, char* argv[])
{
	FILE* f = fopen("in.txt", "r");

	char a[255];
	fscanf(f, "%[^\n]s", &a);
	int start = 0;
	scanf("%d",&start);
	int len = 0;
	scanf("%d",&len);
	fclose(f);

	f = fopen("out.txt", "w");
	fprintf(f, "%s", my_substr(a, start, len));

	fclose(f);

	return 0;
}
