#include <iostream>
#include <fstream>

struct edge
{
    int start;
    int end;
};

class CGraph
{
private:
    int n;
    int** edge;

public:
    CGraph(int k = 0) : n(k)
    {
        edge = new int*[n + 1];
        for(int i = 0; i <= n; ++i)
        {
            edge[i] = new int[n + 1];
            for(int j = 0; j <= n; ++j)
            {
                edge[i][j] = 0;
            }
        }
    }

    void addedge(int start, int end)
    {
        edge[start][end] = 1;
        edge[end][start] = 1;
    }

    void count()
    {
        for(int i = 1; i <= n; ++i)
        {
            int lcount = 0;
            for(int j = 1; j <= n; ++j)
            {
                if(edge[i][j] == 1)
                {
                    lcount++;
                }
            }
            std::cout << lcount << " ";
        }
        std::cout << std::endl;
    }

    ~CGraph()
    {
        for(int i = 0; i <= n; ++i)
        {
            delete[] edge[i];
        }
        delete[] edge;
    }
};

int main(int argc, char* argv[])
{
    std::ifstream input("INPUT.TXT");
    int n = 0;
    int m = 0;
    input >> n >> m;

    CGraph graph(n);

    for(int i = 0; i < m; ++i)
    {
        int start = 0;
        int end = 0;
        input >> start >> end;
        graph.addedge(start, end);
    }

    graph.count();
    input.close();

    return 0;
}

