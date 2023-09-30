#include <iostream>

int main ( int argc, char* argv[] )
{
    int t = 0;
    std::cin >> t;
    int k = 1;
    int p = 0;
    for ( int i = 0; i < t; i++ )
    {
        std::cout << k << " ";
        p++;
        if ( k == p )
        {
            k++;
            p = 0;
        }
    }
    return EXIT_SUCCESS;
}
