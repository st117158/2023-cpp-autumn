#include<iostream>

int main(int argc, char argv[])
{
    int n = 0;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        for (int j = n * 2 - 1 - i; j >  n * 2 - 1 - i - n; j--)
        {
            std::cout << j ;
        }
        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}

