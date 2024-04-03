#include <iostream>
#include <fstream>

class CGraph
{
private:
    int size_g;
    int** matrix;
public:
    CGraph();
    void loaddata()
    {
        std::ifstream input("INPUT.TXT");
        int n = 0;
        input >> n;

        size_g = n;
        matrix = new int* [size_g + 1];
        for(int i = 0; i <= size_g; ++i)
        {
            matrix[i] = new int[size_g + 1] {0};
        }

        for(int i = 0; i < n - 1; ++i)
        {
            int p1 = 0;
            int p2 = 0;
            input >> p1 >> p2;
            matrix[p1][p2] = 1;
            matrix[p2][p1] = 1;
        }
    }

    bool importantcheck(int p)
    {
        int* visit = new int[size_g + 1] {0};

        for(int i = 1; i <= size_g; i++)
        {
            if(i == p)
            {
                continue;
            }
            for(int j = 1; j <= size_g; j++)
            {
                if(j == p)
                {
                    continue;
                }
                if(matrix[i][j] == 1)
                {
                    visit[j] = 1;
                }
            }
        }

        int sum = 0;
        for(int i = 1; i <= size_g; i++)
        {
            sum += visit[i];
        }

        bool result = false;
        if(size_g - sum > 1)
            result = true;

        delete[] visit;

        return result;
    }
    int important()
    {
        int count = 0;
        for(int i = 1; i <= size_g; i++)
        {
            if(importantcheck(i))
            {
                count++;
            }
        }
        return count;
    }
    ~CGraph()
{
    for(int i = 0; i <= size_g; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}
};
CGraph::CGraph() : size_g(0), matrix(nullptr) {}

int main(int argc, char* argv[])
{
    CGraph graph;
    graph.loaddata();
    std::ofstream output("OUTPUT.TXT");
    output << graph.important();
    output.close();
}
