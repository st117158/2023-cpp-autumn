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

    void addedge(int from, int to)
    {
        matrix[from - 1][to - 1] = 1;
    }

    void print(std::ofstream& output)
    {
        output << vertices << std::endl;
        for(int i = 0; i < vertices; ++i)
        {
            for(int j = 0; j < vertices; ++j)
            {
                output << matrix[i][j] << " ";
            }
            output << std::endl;
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

    for(int i = 0; i < n; ++i)
    {
        int m = 0;
        input >> m;
        for(int j = 0; j < m; ++j)
        {
            int vertex = 0;
            input >> vertex;
            graph.addedge(i + 1, vertex);
        }
    }

    graph.print(output);

    input.close();
    output.close();

    return 0;
}

