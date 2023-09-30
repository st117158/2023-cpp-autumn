#include <iostream>

int main ( int argc, char* argv [])
{
    int n = 0;
    std::cin >> n;
    int i = 1;
    int k = 0;
    while (i < n)
    {
        i = i * 2;
        k++;
    }
    std::cout << k;
    return EXIT_SUCCESS;
}
