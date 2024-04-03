#include <iostream>
#include <fstream>

class CGraph
{
private:
    int vertices;
    int** adjacencylist;

public:
    CGraph(int n)
    {
        vertices = n;
        adjacencylist = new int*[vertices];
        for (int i = 0; i < vertices; ++i)
            {
            adjacencylist[i] = new int[vertices];
            for (int j = 0; j < vertices; ++j)
             {
                adjacencylist[i][j] = 0;
            }
        }
    }

    void addedge(int a, int b)
     {
        adjacencylist[a - 1][b - 1] = 1;
    }

    void print(std::ofstream& output)
     {
        output << vertices << std::endl;
        for (int i = 0; i < vertices; ++i)
            {
            int count = 0;
            for (int j = 0; j < vertices; ++j)
            {
                if (adjacencylist[i][j] == 1)
                 {
                    count++;
                }
            }
            output << count << " ";
            for (int j = 0; j < vertices; ++j)
            {
                if (adjacencylist[i][j] == 1)
                {
                    output << j + 1 << " ";
                }
            }
            output << std::endl;
        }
    }

    ~CGraph()
    {
        for (int i = 0; i < vertices; ++i)
            {
            delete[] adjacencylist[i];
        }
        delete[] adjacencylist;
    }
};

int main(int argc, char* argv[])
{
    std::ifstream input("INPUT.TXT");
    std::ofstream output("OUTPUT.TXT");

    int n = 0;
    int m = 0;
    input >> n >> m;

    CGraph graph(n);

    for (int i = 0; i < m; ++i)
        {
        int a = 0;
        int b = 0;
        input >> a >> b;
        graph.addedge(a, b);
    }

    graph.print(output);

    input.close();
    output.close();

    return 0;
}

