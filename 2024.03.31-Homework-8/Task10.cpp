#include <iostream>
#include <fstream>

class CGraph
{
private:
    int vertices;
    int** matrix;

public:
    CGraph(int n)
    {
        vertices = n;
        matrix = new int*[vertices];
        for(int i = 0; i < vertices; ++i)
        {
            matrix[i] = new int[vertices];
            for(int j = 0; j < vertices; ++j)
            {
                matrix[i][j] = 0;
            }
        }
    }

    void read(std::ifstream& input)
    {
        for(int i = 0; i < vertices; ++i)
        {
            for(int j = 0; j < vertices; ++j)
            {
                input >> matrix[i][j];
            }
        }
    }

    void _count(std::ofstream& output)
    {
        for(int i = 0; i < vertices; ++i)
        {
            int count = 0;
            for(int j = 0; j < vertices; ++j)
            {
                count += matrix[i][j];
            }
            output << count << " ";
        }
    }
    ~CGraph()
    {
        for(int i = 0; i < vertices; ++i)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

};

int main(int argc, char* argv[])
{
    std::ifstream input("INPUT.TXT");
    std::ofstream output("OUTPUT.TXT");

    int n = 0;
    input >> n;
    CGraph graph(n);

    graph.read(input);
    graph._count(output);

    input.close();
    output.close();

    return 0;
}

