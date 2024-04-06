#include <iostream>
#include <fstream>

struct Cgraph
{
    int n;
    int** roads;

    Cgraph(int k) : n(k)
    {
        roads = new int*[n];
        for(int i = 0; i < n; ++i)
        {
            roads[i] = new int[n];
        }
    }

    void readroads(std::ifstream& input)
    {
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                input >> roads[i][j];
            }
        }
    }

    int countroads()
    {
        int rcount = 0;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(roads[i][j] == 1)
                {
                    rcount++;
                }
            }
        }
        return rcount/2;
    }

    ~Cgraph()
    {
        for(int i = 0; i < n; ++i)
        {
            delete[] roads[i];
        }
        delete[] roads;
    }
};

int main(int argc, char* argv[])
{
    std::ifstream input("INPUT.TXT");
    int n = 0;
    input >> n;

    Cgraph graph(n);

    graph.readroads(input);

    input.close();

    std::ofstream output("OUTPUT.TXT");
    output << graph.countroads() << std::endl;
    output.close();

    return 0;
}
