#include<iostream>

int main(int argc, char* argv[])
{
    int n = 0;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n + i; ++j)
        {
            std::cout << j % n + 1;
        }
        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}

