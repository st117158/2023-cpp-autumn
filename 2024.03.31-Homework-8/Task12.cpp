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

    bool directed()
    {
        for(int i = 0; i < vertices; ++i)
        {
            if(matrix[i][i] == 1)
            {
                return false;
            }
            for(int j = 0; j < vertices; ++j)
            {
                if(matrix[i][j] != matrix[j][i])
                {
                    return true;
                }
            }
        }
        return false;
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

    if(graph.directed())
    {
        output << "YES";
    }
    else
    {
        output << "NO";
    }

    input.close();
    output.close();

    return 0;
}
