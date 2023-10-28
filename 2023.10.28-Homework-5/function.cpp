#include<iostream>
#include "function.h"
#include<cstdlib>
#include<cmath>
#include<ctime>

void PrintMenu()
{
	std::cout << "0 - exit" << std::endl;
	std::cout << "1 - print array" << std::endl;
	std::cout << "2 - add element" << std::endl;
	std::cout << "3 - delete element" << std::endl;
	std::cout << "4 - sort array in ascending order" << std::endl;
	std::cout << "5 - reverse array" << std::endl;
	std::cout << "6 - change the first maximum and last minimum element" << std::endl;
	std::cout << "7 - Remove duplicates" << std::endl;
	std::cout << "8 - Add n random elements" << std::endl;
}

void print_array(int*& a, int len)
{
    if (a == nullptr)
    {
        std::cout << "EMPTY";
    }
    else
    {
        for(int i = 0; i < len; ++i)
        {
            std::cout << a[i] << " ";
        }
    }
}

void add_element(int*& a, int& len, int b)
{
    int* new_a = new int[len + 1] { 0 };
	if (a != nullptr)
	{
		for (int i = 0; i < len; ++i)
		{
			new_a[i] = a[i];
		}
		delete[] a;
	}
	a = new_a;
	++len;
	a[len - 1] = b;
}

void delete_element(int*& a, int& len, int& c)
{
	if (a != nullptr)
	{
		int* new_a = new int[len - 1];
		for (int i = 0; i < c; ++i)
		{
			new_a[i] = a[i];
		}
		for (int j = c; j < len - 1; ++j)
		{

			new_a[j] = a[j + 1];
		}
		delete[] a;
		a = new_a;
		--len;
	}
    else

	{
		std::cout << "EMPTY" << std::endl;
	}

}

void sort_massive(int*& a, int& len)
{
    if (a != nullptr)
    {
        for (int i = 0; i < len; ++i)
            {
                for (int j = 0; j < len - 1; ++j)
                {
                    if (a[j] > a[j + 1])
                    {
                        int c = a[j];
                        a[j] = a[j + 1];
                        a[j + 1] = c;
                    }
                }
            }
            for (int i = 0; i < len; ++i)
                {
                    std::cout << a[i] << " ";
                }
    }
    else
	{
		std::cout << "EMPTY" << std::endl;
	}
}

int* reverse_massive(int*& a, int& len)
{
    if (a == nullptr)
    {
        std::cout << "EMPTY";
        return a;
    }
    else
    {
        int* new_a = new int[len];
        for(int i = 0; i < len; ++i)
        {
            new_a[i] = a[len - i - 1];
        }
        for(int i = 0; i < len; ++i)
        {
            std::cout << new_a[i] << " ";
        }
        std::cout << std::endl;
        delete[] a;
        return new_a;
    }
}

void change_max_min(int*& a, int& len)
{
    if (a != nullptr)
    {
        int min_value = 0;
        int max_value = 0;
        for (int i = 0; i < len; ++i)
            {
                if (a[i] > a[max_value])
                {
                    max_value = i;
                }
                if (a[i] <= a[min_value])
                    {
                        min_value = i;
                    }
            }
        int b = a[min_value];
        a[min_value] = a[max_value];
        a[max_value] = b;
        for (int i = 0; i < len; ++i)
            {
                std::cout << a[i] << " ";
            }
    }
    else
    {
       std::cout << "EMPTY";
    }


}

void delete_dublicates(int*& a, int& len)
{
	if (a != nullptr)
	{
		for (int i = 0; i < len - 1; ++i)
		{
			for (int j = i + 1; j < len; ++j)
			{
				if (a[i] == a[j])
				{
					delete_element(a, len, j);
				}
			}
		}
	}
	else
	{
		std::cout << "EMPTY" << std::endl;
	}
}

void add_random_elements(int*& a, int& len, int count)
{
	srand(time(NULL));
	for (int i = 0; i < count; ++i)
	{
		add_element(a, len, rand());
	}
}



