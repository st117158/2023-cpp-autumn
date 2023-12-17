#include<iostream>

void exchange_towers(int n, int from, int to)
{
    if(n <= 0)
    {
        return;
    }

    int res = 6 - from - to;

    if(n == 1)
    {
        std::cout << 1 << " " << from << " " << to << std::endl;
    }
    else
    {
        exchange_towers(n - 1, from, to);
        exchange_towers(n - 2, to, res);
        std::cout << 0 << " " << from << " " << to << std::endl;
        exchange_towers(n - 2, res, from);
        exchange_towers(n - 1, from, to);
    }
}


int main(int argc, char* argv[])
{
    int n = 0;
    std::cin >> n;
    exchange_towers(n, 1, 3);
    return EXIT_SUCCESS;
}
