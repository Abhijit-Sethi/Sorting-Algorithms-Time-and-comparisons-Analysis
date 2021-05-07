#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include "server.h"

void merge(long *list,long l, long m, long r)
{
    long n1 = m - l + 1;
    long n2 = r - m;
 
    // Create temp arrays
    long *L=(long*)malloc(sizeof(long)*n1);
     long *R=(long*)malloc(sizeof(long)*n2);
    // long L[n1], R[n2];
 
    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = list[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = list[m + 1 + j];
 
    // Merge the temp arrays back into arr[l..r]
 
    // Initial index of first subarray
    long i = 0;
 
    // Initial index of second subarray
    long j = 0;
 
    // Initial index of merged subarray
    long k = l;
 
    while (i < n1 && j < n2) {
        cmp++;
        if (L[i] <= R[j]) {
            list[k] = L[i];
            i++;
        }
        else {
            list[k] = R[j];
            j++;
        }
        k++;
    }
 
    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1) {
        list[k] = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2) {
        list[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(long *list,long l,long r){
    if(l>=r){
        return;//returns recursively
    }
    long m =(l+ r)/2;
    mergeSort(list,l,m);
    mergeSort(list,m+1,r);
    merge(list,l,m,r);
}


void selectionSort(long *list)  
{  
    int i, j, min_idx,temp=0;  
  
    // One by one move boundary of unsorted subarray  
    for (i = 0; i < length - 1; i++)  
    {  
        // Find the minimum element in unsorted array  
        min_idx = i;  
        for (j = i+1; j < length; j++)  
        {   
            cmp++;
            if(list[j] < list[min_idx])  
                min_idx = j;  
        }
        // Swap the found minimum element with the first element  
        temp = list[min_idx]; 
        list[min_idx] = list[i];
        list[i] = temp;
    }  
}  
void read(long *list)
{
    FILE * fin = fopen("random.txt", "r");
    for (long i = 0; i < length; i++)
    {
        fscanf(fin,"%d",&list[i]);
    }
    fclose(fin);
}
 
void bubbleSort(long *list)
{
    int temp;
    for(long i = 0; i < length; i++)
    {
        for(long j = 0; j < length-i-1; j++)
        {
            cmp++;
            if (list[j] > list[j+1])
            {
                temp        = list[j];
                list[j]     = list[j+1];
                list[j+1]   = temp;
            }
        }
    }
}
 
long partition(long *list,long left, long right)
{
    int pivot_element = list[left];
    int lb = left, ub = right;
    int temp;
 
    while (left < right)
    {
        while(list[left] <= pivot_element)
            left++;
        while(list[right] > pivot_element)
            right--;
        cmp++;
        if (left < right)
        {
            temp        = list[left];
            list[left]  = list[right];
            list[right] = temp;
        }
    }
    list[lb] = list[right];
    list[right] = pivot_element;
    return right;
}
 
void quickSort(long *list,long left, long right)
{
    if (left < right)
    {
        long pivot = partition(list,left, right);
        quickSort(list,left, pivot-1);
        quickSort(list,pivot+1, right);
    }
}
 