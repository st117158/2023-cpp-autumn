#include <iostream>

int main(int argc, char* argv[])
{
    int N = 0;
    std::cin >> N;
    int d = (abs(N - 1))/(N - 1);
    int n = 1 + ((N - 1)/ d);
    int AP = (1 + N) * n / 2;
    std::cout << AP;
    return EXIT_SUCCESS;
}
