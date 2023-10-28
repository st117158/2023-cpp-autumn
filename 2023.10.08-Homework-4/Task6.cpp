#include<iostream>
#include<cstdlib>

int main(int argc, char**)
{
	int n = 0;
	std::cin >> n;
	int* a = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; ++i)
	{
		std::cin >> *(a + i);
	}
	int min_value = 0;
	int max_value = 0;

	for (int i = 0; i < n; ++i)
	{
		if (*(a + i) >= *(a + max_value))
		{
			max_value = i;
		}
		if (*(a + i) < *(a + min_value))
		{
			min_value = i;
		}
	}
	int b = *(a + min_value);
	*(a + min_value) = *(a + max_value);
	*(a + max_value) = b;

	for (int i = 0; i < n; ++i)
	{
		std::cout << *(a + i) << " ";
	}
	free(a);

	return EXIT_SUCCESS;
}
