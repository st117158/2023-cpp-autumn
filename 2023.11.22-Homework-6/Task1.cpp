#include<iostream>

void hanoi(int n, int i, int l)
{
    if(n <= 0)
    {
        return;
    }


    else
    {
        int k = 6 - i - l;
        hanoi(n - 1, i, k);
        std::cout << n << " " << i << " " << l << std::endl;
        hanoi(n - 1, k, l);
    }
}

int main(int argc, char* argv[])
{
    int n = 0;
    std::cin >> n;
    hanoi(n, 1, 3);
    std::cout << std::endl;

    return EXIT_SUCCESS;
}
