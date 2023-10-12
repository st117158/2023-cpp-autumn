#include<iostream>

int main(int argc, int argv[])
{
    int n = 0;
    std::cin >> n;
    int sum = 0;
    for (int i = 0; i <= 31; ++i)
    {
        sum += (n >> i) & 1;
    }
    std::cout << sum;

    return EXIT_SUCCESS;
}
