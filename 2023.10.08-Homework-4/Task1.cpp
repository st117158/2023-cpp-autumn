#include<iostream>
#include<cstdlib>

int main(int argc, char**)
{
    int n = 0;
    std::cin >> n;
    int* a = (int*)malloc(sizeof(int) * n);
    int res = 0;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> *(a + i);
        if (*(a + i) > 0)
        {
            res++;
        }
    }
    free(a);
    std::cout << res;

    return EXIT_SUCCESS;
}
