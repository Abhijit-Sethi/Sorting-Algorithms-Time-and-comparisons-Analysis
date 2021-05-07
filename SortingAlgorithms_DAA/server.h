#include<stdio.h>
#include<stdlib.h>
#include<time.h>

float cmp = 0.0;
long length = 100000;
const long max_length = 1000000;

void read(long* );

void merge(long* ,long , long , long );
void mergeSort(long* ,long ,long );

void selectionSort(long* );

void bubbleSort(long* );

long partition(long* ,long, long );
void quickSort(long* ,long, long);