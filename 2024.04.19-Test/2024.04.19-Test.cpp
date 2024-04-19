#include <iostream>

struct Node
{
    int data;
    Node* next;
    Node(int data, Node* next = nullptr) : data(data), next(next) {}
    Node(const Node& node) : data(node.data), next(nullptr) {}
    ~Node()
    {
        data = 0;
        next = nullptr;
    }
    friend std::ostream& operator<<(std::ostream& stream, Node*& node)
    {
        stream << node->data << " ";
        return stream;
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

    void Insert(int index, int data);
    void PushHead(int data);
    void PushTail(int data);
    int Extract(int index);
    int PopHead();
    int PopTail();
    int Data(int index);
    void swap(int a, int b);
    void sort();
    friend std::ostream& operator<<(std::ostream& stream, const LinkedList& list);

private:
    void dispose();
    int PopData(Node* node);
    void InsertNode(int index, Node* node);
    Node* ExtractNode(int index);
    Node* head;

};

void LinkedList::dispose()
{
    while(!IsEmpty())
    {
        PopHead();
    }
}

void LinkedList::InsertNode(int index, Node* node)
{
    if(head == nullptr)
    {
        node->next = head;
        head = node;
    }
    if(index == 0)
    {
        node->next = head;
        head = node;
    }
    else
    {
        Node* tmp = head;
        for(int i = 0; i < index - 1 && tmp->next != nullptr; ++i)
        {
            tmp = tmp->next;
        }
        node->next = tmp->next;
        tmp->next = node;
    }
}

Node* LinkedList::ExtractNode(int index)
{
    if(!IndexValid(index))
    {
        return nullptr;
    }
    if(index == 0)
    {
        Node* temp = head;
        head = head->next;
        return temp;
    }
    Node* tmp = head;
    for(int i = 0; i < index - 1; ++i)
    {
        tmp = tmp->next;
    }
    Node* temp = tmp->next;
    tmp->next = temp->next;
    return temp;
}

int LinkedList::PopData(Node* node)
{
    int res = 0;
    if(node != nullptr)
    {
        res = node->data;
        delete node;
        node = nullptr;
    }
    return res;
}

int LinkedList::Length()
{
    int len = 0;
    Node* tmp = head;
    while(tmp != 0 && tmp->next != head)
    {
        tmp = tmp->next;
        ++len;
    }
    return len;
}

void LinkedList::PushHead(int data)
{
    Insert(0, data);
}

void LinkedList::PushTail(int data)
{
    if(IsEmpty())
    {
        return PushHead(data);
    }

    int i = Length();
    Insert(i, data);
}

void LinkedList::Insert(int index, int data)
{
    if(index == 0)
    {
        head = new Node(data, head);
    }
    else if(IndexValid(index))
    {
        Node* tmp = head;
        for(int i = 0; i < index - 1; ++i)
        {
            tmp = tmp->next;
        }
        tmp->next = new Node(data, tmp->next);
    }
    else
    {
        Node* tmp = head;
        while(tmp->next != nullptr)
        {
            tmp = tmp->next;
        }
        tmp->next = new Node(data);
    }

}

int LinkedList::Extract(int index)
{
    return PopData(ExtractNode(index));
}

int LinkedList::PopHead()
{
    return PopData(ExtractNode(0));
}

int LinkedList::PopTail()
{
    int i = Length();
    return PopData(ExtractNode(i - 1));
}

int LinkedList::Data(int index)
{
    Node *tmp = head;
    for(int i = 0; i < index && tmp != nullptr; ++i)
    {
        tmp = tmp->next;
    }
    if(tmp == nullptr)
    {
        return 0;
    }
    else
    {
        return tmp->data;
    }
}

void LinkedList::swap(int a, int b)
{
    if(a == b || !IndexValid(a) || !IndexValid(b))
    {
        return;
    }

    if(a > b)
    {
        int tmp = b;
        b = a;
        a = tmp;
    }
    Node* node1 = ExtractNode(b);
    Node* node2 = ExtractNode(a);

    if(node2 == nullptr || node1 == nullptr)
    {
        return;
    }

    InsertNode(a, node1);
    InsertNode(b, node2);
}

void LinkedList::sort()
{
    for(int i = Length() - 1; i >= 0; i--)
    {
        for(int j = 0; j < i; j++)
        {
            if(Data(j) > Data(j + 1))
            {
                swap(j, j + 1);
            }
        }
    }
}

std::ostream& operator<<(std::ostream& stream, const LinkedList& list)
{
    Node* tmp = list.head;
    while(tmp != nullptr)
    {
        stream << tmp << " ";
        tmp = tmp->next;
    }
    return stream;
}

int main(int argc, char* argv[])
{
    LinkedList list;
    std::cout << list << std::endl;
    list.PushHead(1);
    std::cout << list << std::endl;
    list.PushTail(3);
    std::cout << list << std::endl;
    list.Insert(1, 2);
    std::cout << list << std::endl;
    list.Insert(2, 4);
    std::cout << list << std::endl;
    std::cout << list.PopHead() << std::endl;
    std::cout << list << std::endl;
    std::cout << list.Extract(1) << std::endl;
    std::cout << list << std::endl;
    std::cout << list.PopTail() << std::endl;
    std::cout << list << std::endl;
    std::cout << list.Extract(0) << std::endl;
    std::cout << list << std::endl;
    list.PushHead(3);
    list.PushHead(4);
    list.PushHead(1);
    list.PushHead(2);
    list.PushHead(7);
    list.PushHead(5);
    list.PushHead(8);
    list.PushHead(6);
    std::cout << list << std::endl;
    list.sort();
    std::cout << list << std::endl;

    return EXIT_SUCCESS;
}
