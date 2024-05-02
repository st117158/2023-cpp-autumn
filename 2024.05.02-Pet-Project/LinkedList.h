#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include "MyBook.h"
using namespace std;

struct Node
{
	MyBook* data;
	Node* next;
	Node(MyBook* data, Node* next = nullptr) : data(data), next(next) {}
	Node(const Node& node) : data(node.data), next(nullptr) {}
	~Node()
	{
		data = nullptr;
		next = nullptr;
	}
};

class LinkedList
{
public:
	LinkedList() : head(nullptr) {};
	~LinkedList()
	{
		dispose();
	}
	int Length();
	bool IsEmpty()
	{
		return head == nullptr;
	}
	bool IndexValid(int index)
	{
		return (0 <= index && index < Length());
	}
	void InsertNode(int index, Node* node);
	Node* ExtractNode(int index);
	Node* head;
private:

	void dispose();
};

