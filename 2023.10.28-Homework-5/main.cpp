#include<iostream>
#include<cstdlib>
#include<ctime>
#include "function.h"
int main(int argc, char* argv[])
{
	int* a = nullptr;
	int len = 0;
	bool exit = false;

	while (!exit)
	{

       {
           system("cls");
           PrintMenu();
           print_array(a, len);
       }

		int choise = 0;
		std::cin >> choise;

		switch (choise)
		{
		case(0):
		{
			exit = true;
			break;
		}
		case(1):
		{
			print_array(a, len);
			system("pause");
			break;
		}
		case(2):
		{
			std::cout << "enter the element" << std::endl;
			int b = 0;
			std::cin >> b;
			add_element(a, len, b);
			break;
		}
		case(3):
		{
			std::cout << "enter the index of the element" << std::endl;
			int c = 0;
			std::cin >> c;
			delete_element(a, len, c);
			break;
		}
		case(4):
		{
			sort_massive(a, len);
			break;
		}
		case(5):
		{
			a = reverse_massive(a, len);
			break;
		}
		case(6):
		{
			change_max_min(a, len);
			break;
		}
		case(7):
		{
			delete_dublicates(a, len);
			break;
		}
		case(8):
		{
			std::cout << "number of elements" << std::endl;;
			int count = 0;
			std::cin >> count;
			add_random_elements(a, len, count);
			break;
		}
		default:
		{
			std::cout << "Unknown command" << std::endl;
			break;
		}
		}
	}

	return EXIT_SUCCESS;
}



