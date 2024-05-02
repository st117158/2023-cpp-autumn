#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include "LinkedList.h"
using namespace std;


class BoookLibrary
{
public:
	BoookLibrary();
	~BoookLibrary();
	LinkedList books;
	string library_file_name = "settings.txt";

	void PrintHeader()
	{
		std::cout << "######  #       #  ########      " << std::endl;
		std::cout << "#     # #       #     #  " << std::endl;
		std::cout << "#     # #       #     # " << std::endl;
		std::cout << "#     # #       #     # " << std::endl;
		std::cout << "#     # #     # #     #  " << std::endl;
		std::cout << "#     # #     # #     #  " << std::endl;
		std::cout << "######  ####### #     # " << std::endl;
		std::cout << " " << std::endl;
		std::cout << "Book Library " << std::endl;


	}

	void printMenu()
	{
		system("cls");
		PrintHeader();
		std::cout << "_________________________________________" << std::endl;
		std::cout << "0 - Добавить книгу" << std::endl;
		std::cout << "1 - Поиск по автору" << std::endl;
		std::cout << "2 - Поиск по жанру" << std::endl;
		std::cout << "3 - вывести впечатление" << std::endl;
		std::cout << "4 - отсортировать по рейтингу" << std::endl;
		std::cout << "5- выход" << std::endl;
		
	}

	void LoadLibraryFromFile()
	{
		std::ifstream in;
		in.open(library_file_name);
		while (in.is_open() && !in.eof())
		{
			MyBook* book = new MyBook();
			Node* book_node = new Node(book);
			book->readbook(in);
			if (book->author.empty())
			{
	 
				delete book;
			}
			else
			{
				books.InsertNode(0, book_node);
			}
		}
		in.close();
	}

	int choice(int choice)
	{
		switch (choice)
		{
		case 0:
		{
			MyBook* book = new MyBook();
			Node* book_node = new Node(book);
			book->inputbook();
			books.InsertNode(0, book_node);
			book->writebook(library_file_name);
			book->LibraryOut();
			std::cout << "Книги были записаны в файл dlitbooks.txt";
			break;
		}
		case 1:
		{
			std::string author;
			std::cout << "Введите автора : ";
			std::cin.ignore();
			getline(std::cin, author);
			FindBookByAuthor(author);
			break;
		}
		case 2:
		{
			std::string genre;
			std::cout << "Введите жанр: ";
			std::cin.ignore();
			getline(std::cin, genre);
			FindBookByGenre(genre);
			break;
		}

		case 3:
		{
			std::string book_name;
			std::string author;
			std::cin.ignore();
			std::cout << "Введите название книги: ";
			getline(std::cin, book_name);
			std::cout << "Введите автора : ";
			getline(std::cin, author);
			OutImpression(book_name, author);
			break;
		}

		case 4:
		{
			std::string rating;
			std::cout << "Введите оценку ( /10):  ";
			std::cin.ignore();
			getline(std::cin, rating);
			FindBookByRating(rating); 
			break;
		}

		case 5:
			return 0;
		}
	}


	void FindBookByAuthor(string Author)
	{

		ostream& objOstream = cout;
		Node* tmp = books.head;
		while (tmp != nullptr)
		{
			if (tmp->data->author.find(Author) != std::string::npos)
			{
				tmp->data->PrintBookInfo(objOstream);
			}
			tmp = tmp->next;
		}

		std::cout << "Press any key to continue ... ";
		string str;
		getline(std::cin, str);
	}

	void FindBookByGenre(string Genre)
	{

		ostream& objOstream = cout;
		Node* tmp = books.head;
		while (tmp != nullptr)
		{
			if (tmp->data->genre.find(Genre) != std::string::npos)
			{
				tmp->data->PrintBookInfo(objOstream);
			}
			tmp = tmp->next;
		}

		std::cout << "Press any key to continue ... ";
		string str;
		getline(std::cin, str);
	}

	void OutImpression(string Book_name, string Author)
	{
		ostream& objOstream = cout;
		Node* tmp = books.head;
		while (tmp != nullptr)
		{
			if (tmp->data->book_name.find(Book_name) != std::string::npos && tmp->data->author.find(Author) != std::string::npos)
			{
				tmp->data->PrintBookImp(objOstream);
			}
				tmp = tmp->next;
		}

		std::cout << "Press any key to continue ... ";
		string str;
		getline(std::cin, str);
	}

	void FindBookByRating(string Rating)
	{

		ostream& objOstream = cout;
		Node* tmp = books.head;
		while (tmp != nullptr)
		{
			if (tmp->data->rating.find(Rating) != std::string::npos)
			{
				tmp->data->PrintBookInfo1(objOstream);
			}
			tmp = tmp->next;
		}

		std::cout << "Press any key to continue ... ";
		string str;
		getline(std::cin, str);
	}


private:

};

BoookLibrary::BoookLibrary()
{

}

BoookLibrary::~BoookLibrary()
{
}

int main(int argc, char* argv[])
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	BoookLibrary Library;
	Library.LoadLibraryFromFile();

	while (true)
	{
		Library.printMenu();

		int choice = 0;
		std::cin >> choice;

		if (!Library.choice(choice))
			break;
	}

	return 0;
}