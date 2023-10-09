#include <iostream>
#include<cstdlib>

int main(int argc, char**)
{
	int n = 0;
	std::cin >> n;
	int* a = (int*)malloc(sizeof(int) * n);
	int res_pos = 0;

	for (int i = 0; i < n; ++i)
	{
		std::cin >> *(a + i);
	}
	int k = 0;

	for (int i = 0; i < n; ++i)
    {
        if (*(a + i) >= 0)
        {
            *(a + k) = *(a + i);
            k++;
        }
    }
    n = k;
    a = (int*)realloc(a, sizeof(int) * n);

    for (int i = 0; i < n; ++i)
	{
		std::cout << *(a + i) << " ";
	}
	free(a);

    return EXIT_SUCCESS;
}
