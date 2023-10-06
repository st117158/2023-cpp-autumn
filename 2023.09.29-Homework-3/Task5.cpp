#include <iostream>

int main (int argc, char* argv[])
{
    int n = 0;
    std::cin >> n;
    int i = 1;
    int d = 0;
    int res = 0;
    while (i <= n)
    {
        int k = i;
        int n1 = 0;
        while (k > 0)
        {
            d = k % 10;
            k = k / 10;
            n1 = n1 * 10;
            n1 = n1 + d;
        }
        if (i == n1)
        {
            res++;
        }
        i++;

    }
    std::cout << res;
    return EXIT_SUCCESS;
}

