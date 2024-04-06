#include <iostream>
#include <fstream>

class CGraph
{
private:
    int number;
    int departament1;
    int departament2;
    int** departments;


public:
    CGraph(int n, int a, int b) : number(n), departament1(a), departament2(b)
    {
        departments = new int* [number + 1];
        for(int i = 0; i <= number; ++i)
        {
            departments[i] = new int[number + 1] {0};
        }
    }

    void read(std::ifstream& input)
    {
        int n = 0;
        for(int i = 1; i < number; ++i)
        {
            input >> n;
            departments[i + 1][n] = 1;
            departments[n][i + 1] = 1;
        }
    }

    int findlocation()
    {
        int min_ = departament1;
        int max_ = departament2;

        while(true)
        {
            if(max_ == min_)
            {
                break;
            }
            else
            {

                for(int i = max_ - 1; i >= 1; i--)
                {
                    if(departments[max_][i] == 1)
                    {
                        max_ = std::max(i, min_);
                        min_ = std::min(i, max_);
                        break;
                    }
                }
            }
        }
        return min_;
    }
};

int main(int argc, char* argv[])
{
    std::ifstream input("INPUT.TXT");
    std::ofstream output("OUTPUT.TXT");

    int n = 0;
    int a = 0;
    int b = 0;
    input >> n >> a >> b;
    CGraph graph(n, a, b);

    graph.read(input);

    output << graph.findlocation();

    input.close();
    output.close();

    return 0;
}

