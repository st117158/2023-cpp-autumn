#include <iostream>

int main (int argc, char* argv[])
{
    int k = 0;
    int m = 0;
    int n = 0;
    std::cin >> k;
    std::cin >> m;
    std::cin >> n;
    int time = 0;
    2 * n / k;
    if (n <= k)
    {
        time = m * 2;
    }
    else if (n * 2 % k == 0)
    {
        time = (2 * n / k) * m;
    }
    else
    {
        time = ((2 * n / k) + 1) * m;
    }
    std::cout << time;
    return  EXIT_SUCCESS;
}
