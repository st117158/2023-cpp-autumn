
#include <iostream>
#include <fstream>
#include <string>

class CGraph
{
private:
  int vertices;
  int** matrix;

public:
  CGraph(int n)
  {
    vertices = n;
    matrix = new int* [vertices];
    for (int i = 0; i < vertices; ++i)
    {
      matrix[i] = new int[vertices];
      for (int j = 0; j < vertices; ++j)
      {
        matrix[i][j] = 0;
      }
    }
  }

  void read(std::ifstream& input)
  {
    for (int i = 0; i < vertices; ++i)
    {
      for (int j = 0; j < vertices; ++j)
      {
        input >> matrix[i][j];
      }
    }
  }

  void findsource(std::ofstream& output)
  {
    int sourcecount = 0;
    std::string str1 = " ";
    for (int i = 0; i < vertices; ++i)
    {
      bool source = true;
      for (int j = 0; j < vertices; ++j)
      {
        if (matrix[j][i] == 1)
        {
          source = false;
          break;
        }
      }
      if (source)
      {
        str1 = str1 + std::to_string(i + 1) + " ";
        sourcecount++;
      }
    }
    output << sourcecount << str1 << std::endl;
  }

  void finddrain(std::ofstream& output)
  {
    int draincount = 0;
    std::string str2 = " ";
    for (int i = 0; i < vertices; ++i)
    {
      bool drain = true;
      for (int j = 0; j < vertices; ++j)
      {
        if (matrix[i][j] == 1)
        {
          drain = false;
          break;
        }
      }
      if (drain)
      {
        str2 = str2 + std::to_string(i + 1) + " ";
        draincount++;
      }
    }
    output << draincount << str2 << std::endl;
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

    graph.read(input);

    graph.findsource(output);
    graph.finddrain(output);

    input.close();
    output.close();

    return 0;
  }
