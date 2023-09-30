#include <iostream>

int main ( int argc, char* argv[])
{
    int x = 0;
    std::cin >> x;
    int k = 0;
    int i = 1;
    while (i * i < x)
    {
        if (x % i == 0)
        {
            k = k + 2;
        }
        i++;
    }
    if (i * i == x)
    {
        k = k + 1 ;
    }

    std::cout << k ;
    return EXIT_SUCCESS;
}
