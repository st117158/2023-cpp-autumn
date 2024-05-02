#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <sstream>
using namespace std;

class MyBook
{
public:
	std::string book_name;
	std::string author;
	std::string genre;
	std::string descrintion;
	std::string impression;
	std::string new_rating;
	std::string rating;
	const std::string file_name = "settings.txt";
	std::string delimeter = "|";
	void inputbook();
	string TestRating(string rating);
	void writebook(std::string _file_name);
	void LibraryOut();
	void WriteSentence(string Impression);
	string split_line(string& input_string);
	void readbook(std::ifstream& input);
	void PrintBookInfo(std::ostream & out_stream);
	void PrintBookInfo1(std::ostream& out_stream);
	void PrintBookImp(std::ostream& out_stream);




};


