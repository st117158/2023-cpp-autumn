#include <iostream>
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
    int max_value = 0;

    for (int i = 0; i < n; ++i)
    {
        if ((i == 0) || (max_value <= *(a + i)))
        {
            max_value = *(a + i);
        }
    }
    free(a);
    std::cout << max_value;

    return EXIT_SUCCESS;
}
