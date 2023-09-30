#include <iostream>

int main ( int argc, char* argv[])
{
    int n = 0;
    std::cin >> n;
    int n1=0;
    int i = 0;
    while (n > 0)
    {
        i = n % 10;
        n = n / 10;
        n1 = n1*10;
        n1 = n1 + i;
    }
    std::cout << n1;
    return EXIT_SUCCESS;
}
