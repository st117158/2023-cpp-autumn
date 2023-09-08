#include<iostream>

int main(int argc, char* argv[])
{
    int a = 0;
    int b = 0;
    std::cin >> a;
    std::cin >> b;
    int c = a + b;
    int d = abs(a - b);
    int s= (c + d) / 2;
    std::cout << s;
    return EXIT_SUCCESS;

}
