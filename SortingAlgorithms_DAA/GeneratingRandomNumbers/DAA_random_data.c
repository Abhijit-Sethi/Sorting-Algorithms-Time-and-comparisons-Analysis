#include<stdio.h>
#include <stdlib.h>
#include <time.h>

 
const size_t length = 1000000;
 
int main()
{
    FILE *fp;
    fp = fopen("random.txt", "w");
 
    srand(time(NULL));
 
    int r;
    for (size_t i = 0; i < length; i++)
    {
        r = rand()%100000;
        fprintf(fp,"%d\n",r);
    }
 
    fclose(fp);
    return 0;
}