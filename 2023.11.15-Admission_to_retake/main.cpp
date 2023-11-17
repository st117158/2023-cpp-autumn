#include<iostream>
#include<algorithm>
#include<ctime>

int* initrandomarray(int len, int mn = 0, int mx = 9);
void printarray(int* a, int len);
void mixarray(int* a, int n);
void bubbleSort(int* a, int len);
void selectionSort(int* a, int len);
void monkeySort(int* a, int len);
bool isSorted(int* a, int len);
void insertionSort(int* a, int len);
void gnomeSort(int* a, int len);
void countSort(int* a, int len);


int main(int argc, char* argv[])
{
	srand(time(0));
	int n = 10;
	int* a = initrandomarray(n);

	{
		std::cout << "bubble sort" << std::endl;
		mixarray(a, n);
		printarray(a, n);
		bubbleSort(a, n);
		printarray(a, n);
	}
	{
		std::cout << "selection sort" << std::endl;
		mixarray(a, n);
		printarray(a, n);
		selectionSort(a, n);
		printarray(a, n);
	}
	{
		std::cout << "monkey sort" << std::endl;
		mixarray(a, n);
		printarray(a, n);
		monkeySort(a, n);
		printarray(a, n);
	}
	{
		std::cout << "insertion sort" << std::endl;
		mixarray(a, n);
		printarray(a, n);
		insertionSort(a, n);
		printarray(a, n);
	}
	{
	    std::cout << "gnome sort" << std::endl;
		mixarray(a, n);
		printarray(a, n);
		gnomeSort(a, n);
		printarray(a, n);
	}
	{
	    std::cout << "count sort" << std::endl;
		mixarray(a, n);
		printarray(a, n);
		countSort(a, n);
		printarray(a, n);
	}


	return EXIT_SUCCESS;
}

int* initrandomarray(int len, int mn, int mx)
{
	int* res = new int[len] { 0 };
	for (int i = 0; i < len; ++i)
	{
		res[i] = rand() % (mx - mn + 1) + mn;
	}
	return res;
}

void printarray(int* a, int len)
{
	for (int i = 0; i < len; ++i)
	{
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
}

void mixarray(int * a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		std::swap(a[i], a[rand() % n]);
	}
}

void bubbleSort(int * a, int len)
{
	for (int i = 0; i < len; ++i)
	{
		for (int j = 0; j < len - 1 - i; ++j)
		{
			if (a[j] > a[j + 1])
			{
				std::swap(a[j], a[j + 1]);
			}
		}
	}
}

void selectionSort(int * a, int len)
{
	for (int i = 0; i < len; ++i)
	{
		int min_ind = i;

		for (int j = i + 1; j < len; ++j)
		{
			min_ind = (a[min_ind] <= a[j] ? min_ind : j);
		}
		std::swap(a[i], a[min_ind]);
	}
}

void monkeySort(int * a, int len)
{
	while (!isSorted(a, len))
	{
		mixarray(a, len);
	}
}

bool isSorted(int * a, int len)
{
	for (int i = 0; i < len - 1; ++i)
	{
		if (a[i] > a[i + 1])
		{
			return false;
		}
	}
	return true;
}

void insertionSort(int * a, int len)
{
	for (int i = 1; i < len; ++i)
	{
		int b = i;
		while (b > 0 && a[b] < a[b - 1])
		{
			std::swap(a[b], a[b - 1]);
			--b;
		}
	}
}

void gnomeSort(int* a, int len)
{

    int index = 1;
    int nextindex = 2;

    while (index < len)
    {
        if (a[index - 1] < a[index])
        {
            index = nextindex;
            nextindex ++;
        }

        else
        {
            std::swap(a[index-1],a[index]);
            index --;

            if (index == 0)
            {
                index = nextindex;
                nextindex++;
            }
        }

    }
}

void countSort(int* a, int len)
{
    int lenb = 10;
    int* b = new int[lenb] { 0 };

    for (int i = 0; i < len; ++i)
    {
        ++b[a[i]];
    }
    int c = 0;
    for (int j = 0; j < lenb; ++j)
    {
        for (int i = 0; i < b[j]; ++i)
        {
            a[c] = j;
            ++c;
        }
    }
    delete [] b;
}
