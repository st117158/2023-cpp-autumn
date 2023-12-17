#include <iostream>


const int max_disks = 10;
//кол-во дисков
int ndisk;
//высота башни
int h[4]{ 0 };
//список дисков на каждой башне
int** towers = new int* [4]{ nullptr, new int[max_disks], new int[max_disks], new int[max_disks] };

//местоположение дисков на стержне
int Loc[max_disks]{ 0 };

//нач настройка
void init()
{
     std::cout << "Введите кол-во дисков " << std::endl;
     std::cin >> ndisk;
    h[1] = ndisk;

    for (int i = 1; i <= ndisk; i++)
    {
        std::cin >> towers[1][i] ;
    }


    //фундамент больше кол-ва дисков, на пустой можем ставить диск
    for (int i = 1; i <= 3; i++)
    {
        towers[i][0] = ndisk + 1;
    }
};

// переместить диск  from --> to
void MoveDisk(int from, int to)
{
    std::cout << "Move disk " << towers[from][h[from]] <<  " from " << from << " -->> " << to << std::endl;
    h[to]++;
    towers[to][h[to]] = towers[from][h[from]];
    towers[from][h[from]] = 0; // диск перемещен
    h[from]--;
};

// собрать k дисков на стержне to
void HanoiBuild(int k, int to)
{
    if (k <= 0)
    {
        return;
    }
    if (Loc[k] == to)
    {
        HanoiBuild(k - 1, to);
    }
    else
    {
        HanoiBuild(k - 1, 6 - Loc[k]- to);
        MoveDisk(Loc[k], to);
        Loc[k] = to;
        HanoiBuild(k - 1, to);
    }
};

// найти на 2 и 3 стержне диски меньше верхнего на 1 стержне
// собрать их на 2 стержне
void Clearning()
{
    int i = 0;
    //чистим
    for ( i = 0; i <= ndisk; i++)
    {
        Loc[i] = 0;
    }

    //нумеруем диски на 2 и 3
    i = 0;
    while ((i < h[2]) && (towers[2][h[2] - i] <= towers[1][h[1]]))
    {
        Loc[towers[2][h[2] - i]] = 2;
        i++;
    };
    i = 0;
    while ((i < h[3]) && (towers[3][h[3] - i] <= towers[1][h[1]]))
    {
        Loc[towers[3][h[3] - i]] = 3;
        i++;
    };

    // удалить 0 из Loc
    int k = 0;
    for (i = ndisk ; i > 0; i--)
    {
        if (Loc[i] == 0)
        {
            for (int j = i; j < ndisk; j++)
            {
                Loc[j] = Loc[j + 1];
            }
            k++;
        }
    }
    HanoiBuild(ndisk - k, 3);
};
void HanoiMain()
{
    // пока на 3 не все диски
    while (h[3]< ndisk)
    {
        // если можем перемещаем диски 1 --> 2
        if (towers[1][h[1]] <= towers[2][h[2]])
        {
            MoveDisk(1, 2);
        }
        else         // если можем перемещаем диски 1 --> 3
            if (towers[1][h[1]] <= towers[3][h[3]])
            {
                MoveDisk(1, 3);
            }
            else
                Clearning();
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    init();
    HanoiMain();
}
