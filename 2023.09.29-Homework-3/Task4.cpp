#include <iostream>

int main (int argc, char* argv[])
{
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int lim = 1000;
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;
    std::cin >> d;
    for (int i = 0; i <= lim; i++)
    {
        if (a * i * i * i + b * i * i + c * i + d == 0)
        {
            std::cout << i << " ";
        }
    }
    return EXIT_SUCCESS;
}
