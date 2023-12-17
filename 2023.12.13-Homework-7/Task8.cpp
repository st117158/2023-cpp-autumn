#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[])
{
    std::ifstream f;
    f.open("in.txt");
    int len = 0;
    std::string j = "";
    if(f)
    {
        getline(f, j);
    }
    int count = 0;
    int n=j.size();
    for(int i = 0; i < n; i++)
    {
        if(j[i] == ' ')
        {
            count++;
        }
    }
    int words = count + 1;
    std::string* s = new std::string[words] {""};
    int k = 0;
    for(int i = 0; i < n; i++)
    {
        if((j[i] >= 'A' || j[i] >= 'a') && (j[i] <= 'Z' || j[i] <= 'z'))
        {
            s[k] += j[i];
        }
        else
        {
            k++;
        }
    }
    int ind = 0;
    int max = 0;
    for(int i = 0; i < words; i++)
    {
        int r = 0;
        for(int k = i; k < words; k++)
        {
            if(s[i] == s[k])
            {
                r++;
            }
        }
        if(r > max)
        {
            ind = i;
            max = r;
        }
    }

    f.close();

    std::ofstream fout;
    fout.open("out.txt");
    if(fout.is_open())
    {
        fout << s[ind] << std::endl;
    }
    fout.close();

    return	EXIT_SUCCESS;

}
