#include<iostream>

void sort_h(int n, int i, int l)
{
    if(n > 0)
    {
        int k = 6 - i - l;
        sort_h(n - 1, i, k);
        std::cout << n << " " << i << " " << l << std::endl;
        sort_h(n - 1, k, l);
    }
}

void sort_hanoy(int n)
{
    int l = 0;
    if(n % 2 == 0)
    {
        l = 3;
    }
    else
    {
        l = 2;
    }
    int i = 1;
    sort_h(n, i, l);
    int k = 5 - l;
    for(int i = n; i > 0; i--)
    {
        sort_h(i - 1, l, k);
        std::swap(l, k);
    }
}

int main(int argc, char* argv[])
{
    int n = 0;
    std::cin >> n;
    sort_hanoy(n);
    std::cout << std::endl;

    return EXIT_SUCCESS;
}
