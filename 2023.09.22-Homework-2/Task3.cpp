#include <iostream>

int main ( int argc, char* argv[])
{
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;
    std::cin >> d;
    int x = -b / a;
    if (a == 0 && b == 0)
    {
        std::cout << "INF";
    }
    else if ( (a == 0 ) || (c * x + d == 0))
    {
        std::cout << "NO";
    }
    else if ((b % a == 0))
    {
        std::cout << x ;
    }
    else
    {
        std::cout << "NO";
    }
    return EXIT_SUCCESS;
}

