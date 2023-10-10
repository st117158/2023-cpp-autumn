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

    for (int i = 0; i < n; ++i)
    {
        if (*(a + i) % 2 == 1)
        {
            std::cout << *(a + i) << " ";
        }
    }
    free(a);

    return EXIT_SUCCESS;
}
