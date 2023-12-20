#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* my_strmult(char* a, int num)
{
  int len = strlen(a);
  char* newstr = (char*)malloc(sizeof(char) * (len * num));
  memset(newstr,0 ,(len * num) * sizeof(char));;
	for (int i = 0; i < num; ++i)
	{
		for (int j = i * len; j < i * len + len; ++j)
		{
			newstr[j] = a[j % len];
		}
	}
	printf("%s", newstr);
	return newstr;
	free(newstr);
}


int main(int argc, char* argv[])
{
	FILE* f = fopen("in.txt", "r");

	char a[255];
	fscanf(f, "%s", &a);
	int b = 0;
	scanf("%d", &b);
	fclose(f);
	f = fopen("out.txt", "w");
	fprintf(f, "%s", my_strmult(a,b));


	fclose(f);
	return 0;
}
