#include <iostream>
#include <fstream>
#include <string>

class CGraph
{
private:
    int n;
    int** matrix;

public:
    CGraph(int k) : n(k)
    {
        matrix = new int* [n];
        for (int i = 0; i < n; ++i)
        {
            matrix[i] = new int[n];
        }
    }

    void read(std::ifstream& input)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                input >> matrix[i][j];
            }
        }
    }

    void print(std::ofstream& output)
    {
        int count = 0;
        std::string str = "";
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (matrix[i][j] == 1)
                {
                    ++count;
                    str = str + std::to_string(i + 1) + " " + std::to_string(j + 1) + '\n';
                }
            }
        }
        output << n << " " << count << std::endl;
        output << str;
    }

    ~CGraph()
    {
        for (int i = 0; i < n; ++i)
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
    graph.read(input);
    graph.print(output);

    input.close();
    output.close();

    return 0;
}
