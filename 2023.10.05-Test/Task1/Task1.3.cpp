#include<iostream>

int main(int argc, char* argv[])
{
    unsigned short a = 0;
    unsigned short b = 0;
    unsigned int c = 0;
    std::cin >> a;
    std::cin >> b;
    bool up = 0;

    for (int i = 0; i <= 31; ++i)
    {
        bool bit_a = ((a >> i) & 1);
        bool bit_b = ((b >> i) & 1);
        bool current = bit_a ^ bit_b ^ up;
        up = (bit_a & up) | (bit_b & up) | (bit_a & bit_b);
        c |= ((int)current << i);
    }
    std::cout << c;

    return EXIT_SUCCESS;
}

