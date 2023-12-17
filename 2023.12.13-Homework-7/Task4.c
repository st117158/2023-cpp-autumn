#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int my_strstr(char* s1, char* s2)
{
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	int count = 0;

	for (int i = 0; i < len1; ++i)
	{
		int ind_s1 = i;
		int ind_s2 = 0;

		while (ind_s2 < len2)
		{
			if (s1[ind_s1] == s2[ind_s2])
			{
				++ind_s1;
				++ind_s2;
			}
			else
			{
				break;
			}
		}

		if (ind_s2 == len2)
		{
			return i;
		}
		else
		{
			++count;
		}
	}
	if (count = len1)
	{
		return 0;
	}
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
	fprintf(f, "%d", my_strstr(a, b));

	fclose(f);

	return 0;
}

