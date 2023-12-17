#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    FILE* f = fopen("in.txt", "r");
    int count = 0;

    while(!feof(f))
    {
        char c = 0;
        fscanf(f, "%c", &c);
        if(c == ' ')
        {
            count++;
        }
    }
    int sum = count + 1;
    fclose(f);
    f = fopen("out.txt", "w");
    fprintf(f, "%d", sum);
    fclose(f);
    return 0;
}



