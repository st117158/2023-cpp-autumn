#include<iostream>

int main(int argc, char* argv[])
{
    int a = 0;
    std::cin >> a;
    int b = a / 10;
    int c = b + 1;
    int d = b * c;
    int e = d * 100;
    int f = e + 25;
    std::cout << f;
    return EXIT_SUCCESS;
}
