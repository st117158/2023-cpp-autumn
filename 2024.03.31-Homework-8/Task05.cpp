#include <iostream>
#include <fstream>

class CGraph
{
private:
    int n;

public :
    CGraph(int k) : n(k) {}

    int findancestor(int species1, int species2)
    {
        while(species1 != species2)
        {
            if(species1 > species2)
            {
                species1 = species1 / 2;
            }
            else
            {
                species2 = species2 / 2;
            }
        }
        return species1;
    }
    ~CGraph() {}
};

int main(int argc, char* argv[])
{
    std::ifstream input("INPUT.TXT");
    std::ofstream output("OUTPUT.TXT");

    int n = 0;
    int species1 = 0;
    int species2 = 0;
    input >> n >> species1 >> species2;
    CGraph graph(n);
    int ancestor = graph.findancestor(species1, species2);
    output << ancestor;

    input.close();
    output.close();

    return 0;
}


