#include <iostream>
#include <fstream>

class CGraph
{
private:
    int n;
    int** distance;

public:
    CGraph(int k) : n(k)
    {
        distance = new int*[n];
        for(int i = 0; i < n; ++i)
        {
            distance[i] = new int[n];
        }
    }

    void read(std::ifstream& input)
    {
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                input >> distance[i][j];
            }
        }
    }

    int findroad()
    {
        int mindistance =  distance[0][1] + distance[1][2] + distance[2][0];

        for(int i = 0; i < n; ++i)
        {
            for(int j = i + 1; j < n; ++j)
            {
                for(int k = j + 1; k < n; ++k)
                {
                    int finaldistance = distance[i][j] + distance[j][k] + distance[k][i];
                    if(finaldistance < mindistance)
                    {
                        mindistance = finaldistance;

                    }
                }
            }
        }
        return mindistance;
    }

    ~CGraph()
    {
        for(int i = 0; i < n; ++i)
        {
            delete[] distance[i];
        }
        delete[] distance;
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
    output << graph.findroad() << std::endl;
    output.close();

    return 0;
}
