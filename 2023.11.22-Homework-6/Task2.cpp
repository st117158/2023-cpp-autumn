#include<iostream>

void repair_h(int n, int i, int l)
{
    if(n > 0)
    {
        if((i + l) == 4)
        {
            repair_h(n, i, 2);
            repair_h(n, 2, l);
        }
        else
        {
            repair_h(n - 1, i, 6 - i - l);
            std::cout << n << " " << i << " " << l << std::endl;
            repair_h(n - 1, 6 - i - l, l);
        }
    }

}

int main(int argc, char* argv[])
{
    int n = 0;
    std::cin >> n;
    repair_h(n, 1, 3);
    std::cout << std::endl;

    return EXIT_SUCCESS;
}
