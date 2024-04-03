#include <iostream>
#include <fstream>

struct h
{
    int color;
};

class CGraph
{
private:
    int n;
    int** bridges;
    h* hills;

public:
    CGraph(int k = 0) : n(k)
    {
        bridges = new int*[n];
        for(int i = 0; i < n; ++i)
        {
            bridges[i] = new int[n];
        }
        hills = new h[n];
    }

    void read(std::ifstream& input)
    {
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                input >> bridges[i][j];
            }
        }

        for(int i = 0; i < n; ++i)
        {
            input >> hills[i].color;
        }
    }

    int countbridge()
    {
        int bridge = 0;
        for(int i = 0; i < n; ++i)
        {
            for(int j = i + 1; j < n; ++j)
            {
                if ( bridges[i][j] == 1 && hills[i].color != hills[j].color)
            {
                bridge++;
            }
        }
    }
    return bridge;
}

~CGraph()
    {
        for(int i = 0; i < n; ++i)
        {
            delete[] bridges[i];
        }
        delete[] bridges;
        delete[] hills;
    }

};

int main(int argc, char* argv[])
{
    std::ifstream input("INPUT.TXT");
    int n = 0;
    input >> n;

    CGraph graph(n);

    graph.read(input);

    input.close();

    std::ofstream output("OUTPUT.TXT");
    output << graph.countbridge() << std::endl;
    output.close();

    return 0;
}
