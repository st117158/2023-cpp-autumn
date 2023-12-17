#include <iostream>

const int max_disk = 10;
int ndisk = 0;
int h[4] {0}; // высота башни
int** towers = new int* [4]{nullptr, new int[max_disk], new int[max_disk], new int[max_disk]};
int location[max_disk] {0}; //расположение дисков

void initialiasion()
{
   std::cin >> ndisk;
   h[1] = ndisk;

   for (int  i = ndisk; i >= 1; i--)
   {
       std::cin >> towers[1][i];
   }

   for (int i = 1 ;i <= 3; i++) // чтобы потом понять на какой диск перемещать.Найти пустой диск
   {
       towers[i][0] = ndisk + 1;
   }
}

void shift(int from, int to)
{
    std::cout << towers[from][h[from]]<< " " << from << " " << to << std::endl;
    h[to]++;
    towers[to][h[to]] = towers[from][h[from]];
    h[from]--;

}

void hanoi(int k, int to)
{

    if (k <= 0)
    {
        return;
    }

    if (location[k] == to)
    {
       hanoi(k - 1, to);
    }
    else
    {
        hanoi(k - 1, 6 - location[k] - to);
        shift(location[k], to);
        location[k] = to;
        hanoi(k - 1, to);
    }
}

void correction()
{

    for (int i = 0; i <= ndisk; i++)
    {
        location[i] = 0;
    }

    int i = 0;
    while ((i < h[2]) && (towers[2][h[2] - i] <= towers[1][h[1]]))
    {
        location[towers[2][h[2] - i]] = 2;
        i++;
    }
    i = 0;
    while ((i < h[3]) && (towers[3][h[3] - i] <= towers[1][h[1]]))
    {
        location[towers[3][h[3] - i]] = 3;
        i++;
    }

    int k = 0;
    for (i = ndisk ; i > 0; i--)
    {
        if (location[i] == 0)
        {
            for (int j = i; j < ndisk; j++)
            {
                location[j] = location[j + 1];
            }
            k++;
        }
    }
    hanoi(ndisk - k, 3);
};
void HanoiMain()
{

    while (h[3]< ndisk)
    {

        if (towers[1][h[1]] <= towers[2][h[2]])
        {
            shift(1, 2);
        }
        else
            if (towers[1][h[1]] <= towers[3][h[3]])
            {
                shift(1, 3);
            }
            else
                correction();
    }
}

int main()
{
    initialiasion();
    HanoiMain();
}
