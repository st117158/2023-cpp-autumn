#include<iostream>

bool check(int i, int l)
{
    if(i == 1 && l == 2)
    {
        return 1;
    }

    if(i == 2 && l == 1)
    {
        return 0;
    }

    if(i == 2 && l == 3)
    {
        return 1;
    }

    if(i == 3 && l == 2)
    {
        return 0;
    }

    if(i == 3 && l == 1)
    {
        return 1;
    }

    if(i == 1 && l == 3)
    {
        return 0;
    }
}


void cyclic_h(int n, int i, int l)
{
    if(n > 0)
    {
        int k = 6 - i - l;
        if(check(i, l))
        {
            cyclic_h(n - 1, i, k);
            std::cout << n << " " << i << " " << l << std::endl;
            cyclic_h(n - 1, k, l);
        }
        else
        {
            cyclic_h(n - 1, i, l);
            std::cout << n << " " << i << " " << k << std::endl;
            cyclic_h(n - 1, l, i);
            std::cout << n << " " << k << " " << l << std::endl;
            cyclic_h(n - 1, i, l);
        }
    }
}

int main(int argc, char* argv[])
{
    int n = 0;
    std::cin >> n;
    cyclic_h(n, 1, 3);
    std::cout << std::endl;

    return EXIT_SUCCESS;
}
