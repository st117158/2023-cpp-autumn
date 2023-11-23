#include<iostream>

void notfaire_h(int n, int i, int l)
{
    int k = 6 - i - l;
    if(n == 1)
    {
        std::cout << n << " " << i << " " << l << std::endl;
    }
    else
    {
        notfaire_h(n - 1, i, l);
        std::cout << n << " " << i << " " << k << std::endl;
        notfaire_h(n - 1, l, i);
        std::cout << n << " " << k << " " << l << std::endl;
        notfaire_h(n - 1, i, l);
    }
}
int main(int argc, char* argv[])
{
    int n = 0;
    std::cin >> n;
    notfaire_h(n, 1, 3);
    std::cout << std::endl;

    return EXIT_SUCCESS;
}
