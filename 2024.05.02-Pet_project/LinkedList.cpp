#include "LinkedList.h"

void LinkedList::dispose()
{
	while (!IsEmpty())
	{
		ExtractNode(0);
	}
}

void LinkedList::InsertNode(int index, Node* node)
{
	if ((head == nullptr) || (index <= 0))
	{
		node->next = head;
		head = node;
	}
	else if (IndexValid(index))
	{
		Node* tmp = head;
		for (int i = 0; i < index - 1 && tmp->next != nullptr; ++i)
		{
			tmp = tmp->next;
		}
		node->next = tmp->next;
		tmp->next = node;
	}
	else
	{ 

		Node* tmp = head;
		while (tmp->next != nullptr)
		{
			tmp = tmp->next;
		}
		tmp->next = node;
		node->next = nullptr;
	}
}


Node* LinkedList::ExtractNode(int index)

{
	if (!IndexValid(index))
	{
		return nullptr;
	}
	if (index == 0)
	{
		Node* temp = head;
		head = head->next;
		return temp;
	}
	Node* tmp = head;
	for (int i = 0; i < index - 1; ++i)
	{
		tmp = tmp->next;
	}
	Node* temp = tmp->next;
	tmp->next = temp->next;
	return temp;
}

int LinkedList::Length()
{
	int len = 0;
	Node* tmp = head;
	while (tmp != 0 && tmp->next != head)
	{
		tmp = tmp->next;
		++len;
	}
	return len;
}

