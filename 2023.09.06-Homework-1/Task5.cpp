#include<iostream>

int main(int argc, char* argv[])
{
    int v = 0;
    int t = 0;
    std::cin >> v;
    std::cin >> t;
    int s1 = 109;
    int s2 = (v * t) % s1;
    int s = s1 + s2;
    int s3 = s % s1 + 1;
    std::cout << s3;
    return EXIT_SUCCESS;
}
