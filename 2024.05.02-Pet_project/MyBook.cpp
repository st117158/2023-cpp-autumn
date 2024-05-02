#include "MyBook.h"
using namespace std;


void MyBook::inputbook()

{
	std::cin.ignore();
	std::cout << "������� �������� �����: ";
	getline(std::cin, book_name);
	std::cout << "������� ������: ";
	getline(std::cin, author);
	std::cout << "������� ����: ";
	getline(std::cin, genre);
	std::cout << "������� �����������: ";
	getline(std::cin, impression);
	std::cout << "������� ��������: ";
	getline(std::cin, descrintion);
	std::cout << "������ �� �������������� �����: ";
	getline(std::cin, new_rating);
	rating = TestRating(new_rating);
};

string MyBook::TestRating(string new_rating) 
{
	int n = 0;
	n = atoi(new_rating.c_str());
	while (n < 0 || n > 10)
	{
		std::cout << "������ �� �������������� ����� (�� 0 �� 10). ���������� ��� ���: ";
		getline(std::cin,new_rating);
		n = atoi(new_rating.c_str());
	}
	return new_rating;
}

string MyBook::split_line(string& input_string)
{

	int pos = 0;
	std::string token = "";
	pos = input_string.find(delimeter);
	if (pos != std::string::npos)
	{
		token = input_string.substr(0, pos);
		input_string.erase(0, pos + delimeter.length());
	}
	return token;
}
void MyBook::readbook(std::ifstream& input)
{
	string  line;
	getline(input, line);
	book_name = split_line(line);
	author = split_line(line);
	genre = split_line(line);
	impression = split_line(line);
	descrintion = split_line(line);
	rating = split_line(line);
}
void MyBook::PrintBookInfo(std::ostream & out_stream)
{
	out_stream << "========================" << std::endl;
	out_stream << "�����    : " << author << std::endl;
	out_stream << "�����    : " << book_name << std::endl;
	out_stream << "�������� : " << descrintion << std::endl;
	out_stream << "������   : " << rating << "/10" << std::endl;

}

void MyBook::PrintBookInfo1(std::ostream& out_stream)
{
	out_stream << "========================" << std::endl;
	out_stream << "�����      : " << author << std::endl;
	out_stream << "�����      : " << book_name << std::endl;
	out_stream << "��������   : " << descrintion << std::endl;
	out_stream << "�����������: " << impression << std::endl;
	out_stream << "������     : " << rating << "/10" << std::endl;

}

void MyBook::PrintBookImp(std::ostream& out_stream)
{
	out_stream << "========================" << std::endl;
	out_stream << "�����������    : " << impression << std::endl;
}
void MyBook::writebook(std::string _file_name)
{
	std::ofstream output(_file_name, std::ios::app);
	if (output.is_open())
	{
		output << book_name << delimeter;
		output << author << delimeter;
		output << genre << delimeter;
		output << impression << delimeter;
		output << descrintion << delimeter;
		output << rating << delimeter;
		output << std::endl;
		output.close();
	}

};

void MyBook::LibraryOut()
{
	std::ofstream output("dlitbooks.txt", std::ios::app);
	if (output.is_open())
	{
		output << "~�������� �����: " << std::endl;
		output << book_name << std::endl;
		output << "~�����: " << std::endl;
		output << author << std::endl;
		output << "~����: " << std::endl;
		output << genre << std::endl;
		output << "~�����������: " << std::endl;
		WriteSentence(impression);
		output << "~��������: " << std::endl;
		WriteSentence(descrintion);
		output << "~������: " << std::endl;
		output << rating << "/10" << std::endl;
		output << " " << std::endl;
		output.close();
		std::cout << "���� ����� ���� ��������" << std::endl;
	}
}


void MyBook::WriteSentence(string Impression)
{
	std::ofstream output("dlitbooks.txt", std::ios::app);
	std::string sentence ;
	std::stringstream memory(Impression);
	while (getline( memory, sentence, '.'))
	{
		sentence.erase(0, sentence.find_first_not_of(" \t\n\r\f\v"));
		
		output << sentence << "." << std::endl;
	}

	output.close();
}


