#include <iostream>

int main (int argc, char* argv[])
{
    int n = 0;
    int Price1 = 15;
    int Price5 = 70;
    int Price10 = 125;
    int Price20 = 230;
    int Price60 = 440;
    std::cin >> n;
    int count60 = n / 60;
    int n1 = n % 60;
    int count20 = n1 / 20;
    int n2 = n1 % 20;
    int count10 = n2 / 10;
    int n3 = n2 % 10;
    int count5 = n3 / 5;
    int count1 = n3 % 5;

    if (count1 * Price1 >= Price5)
    {
        count1 = 0;
        count5++;
    }
    if (count1 * Price1  + count5 * Price5  >= Price10)
    {
        count1 = 0;
        count5 = 0;
        count10++;
    }
    if (count1 * Price1  + count5 * Price5  + count10 * Price10 >= Price20)
    {
        count1 = 0;
        count5 = 0;
        count10 = 0;
        count20++;
    }
    if (count1 * Price1  + count5 * Price5 + count10 * Price10  + count20 * Price20 >= Price60)
    {
        count1 = 0;
        count5 = 0;
        count10 = 0;
        count20 = 0;
        count60++;
    }
    std::cout<< count1 << " " << count5 << " " << count10 << " " << count20 << " " << count60;
    return EXIT_SUCCESS;
}
