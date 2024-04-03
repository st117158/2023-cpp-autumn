#include <iostream>
#include <fstream>

class CGraph
{
private:
    int vertices;
    int edge;
    int** matrix;

public:
    CGraph(int n, int m)
    {
        vertices = n;
        edge = m;
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
        for(int i = 0; i < edge; ++i)
        {
            int from = 0;
            int to = 0;
            input >> from >> to;
            matrix[from - 1][to - 1] = 1;
        }
    }

    bool tournament()
    {
        for(int i = 0; i < vertices; ++i)
        {
            for(int j = 0; j < vertices; ++j)
            {
                if(i != j)
                {
                    if(matrix[i][j] == 0 && matrix[j][i] == 0)
                    {
                        return false;
                    }
                    if(matrix[i][j] == 1 && matrix[j][i] == 1)
                    {
                        return false;
                    }
                }
            }
        }
        return true;
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
    int m = 0;
    input >> n >> m;
    CGraph graph(n, m);

    graph.read(input);

    if(graph.tournament())
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

