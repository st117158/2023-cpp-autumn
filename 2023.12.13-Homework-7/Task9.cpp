#include <iostream>
#include <fstream>
#include <string>
#include<algorithm>;


std::string palindrom(std::string l)
{
    int len = l.size();
    std::string p = l;
    std::reverse(p.begin(), p.end());
    if(l == p)
    {
        return "ispalindrom";
    }
    else
    {
        return "no";
    }
}


int main(int argc, char argv[])
{
    std::ifstream f;
    f.open("in.txt");
    int len = 0;
    std::string s = "";
    if(f)
    {
        while(!f.eof())
        {
            std::string k = "";
            getline(f, k);
            len++;
            s += k;
            s += '/';
        }

    }

    int j = 0;
    std::string* k = new std::string[len] { "" };
    for(int i = 0; i < len; i++)
    {
        while(s[j] != '/')
        {
            k[i] += s[j];
            j++;
        }
        j++;
    }


    std::ofstream fout("out.txt");
    for(int i = 0; i < len; i++)
    {
        std::string l = palindrom(k[i]);
        fout << l;
    }
    f.close();
    fout.close();

    return 0;
}

