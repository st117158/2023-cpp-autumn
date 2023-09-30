#include <iostream>

int main ( int argc, char* argv [])
{
    int n = 0;
    std::cin >> n;
    int a = 0;
    int b = 1;
    int c = 0;
    int i = 0;
    while ( i < n - 1 )
    {
        c = a + b;
        a = b;
        b = c;
        i++;
    }
    if (n > 1)
    {
        std::cout << c;
    }
    else if ( n == 0)
    {
        std::cout << 0;
    }
    else
    {
        std::cout << 1;
    }
    return EXIT_SUCCESS;
}
