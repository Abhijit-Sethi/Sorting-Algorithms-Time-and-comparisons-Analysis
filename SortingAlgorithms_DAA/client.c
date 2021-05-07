#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include "server.h"

int main()
{
    double t1, t2;
    FILE* fp;
    for (length = 100000; length <= max_length; length+=50000 )
    {
        printf("Length : %d\n",length);
        long *list = (long *)malloc(sizeof(int)*length);
        read(list);
        cmp=0.0;
        t1 = clock();
        bubbleSort(list);
        t2 = clock();
        printf("Bubble Sort\t: %f sec\nComparisons : %.0f\n",(t2 - t1)/CLK_TCK,cmp);
        fp=fopen("BubbleSort_time.txt","a");
        fprintf(fp,"%d %f\n",length,(t2-t1)/CLK_TCK);
        fclose(fp);
        fp = fopen("BubbleSort_comp.txt","a");
        fprintf(fp,"%d %.0f\n",length,cmp);
        fclose(fp);
        free(list);
        list=NULL;

        read(list);
        cmp=0.0;
        t1 = clock();
        selectionSort(list);
        t2 = clock();
        printf("Selection Sort\t: %f sec\nComparisons : %.0f\n",(t2 - t1)/CLK_TCK,cmp);
        fp=fopen("SelectionSort_time.txt","a");
        fprintf(fp,"%d %f\n",length,(t2-t1)/CLK_TCK);
        fclose(fp);
        fp = fopen("SelectionSort_comp.txt","a");
        fprintf(fp,"%d %.0f\n",length,cmp);
        fclose(fp);
        free(list);
        list=NULL;

        list = (long *)malloc(sizeof(int)*length);
        read(list);
        cmp=0.0;
        t1 = clock();
        mergeSort(list,0, length - 1);
        t2 = clock();
        printf("Merge Sort\t: %f sec\nComparisons : %.0f\n",(t2 - t1)/CLK_TCK,cmp);
        fp=fopen("MergeSort_time.txt","a");
        fprintf(fp,"%d %f\n",length,(t2-t1)/CLK_TCK);
        fclose(fp);
        fp = fopen("MergeSort_comp.txt","a");
        fprintf(fp,"%d %.0f\n",length,cmp);
        fclose(fp);
        free(list);
        list=NULL;

        list = (long *)malloc(sizeof(int)*length);
        read(list);
        cmp=0.0;
        t1 = clock();
        quickSort(list,0, length - 1);
        t2 = clock();
        printf("Quick Sort\t: %f sec\nComparisons : %.0f\n",(t2 - t1)/CLK_TCK,cmp);
        //Write into file
        fp=fopen("QuickSort_time.txt","a");
        fprintf(fp,"%d %f\n",length,(t2-t1)/CLK_TCK);
        fclose(fp);
        fp = fopen("QuickSort_comp.txt","a");
        fprintf(fp,"%d %.0f\n",length,cmp);
        fclose(fp);
        free(list);
        list=NULL;

    }
 
    return 0;
}