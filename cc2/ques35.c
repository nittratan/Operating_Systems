#include <stdio.h>
#include <stdlib.h>
void fifo(int arr[], int n, int frames);
void lru(int arr[], int n, int frames);
void optimal_pra(int arr[], int n, int frames);
int inar(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}
int max(int a, int b)
{
    if (a < b)
        return b;
    return a;
}
int inarp(int arr[], int start, int size, int key)
{
    for (int i = start; i < size; i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 2, 4, 2, 3};
    optimal_pra(arr, 7, 3);
    return 0;
}
void fifo(int arr[], int n, int frames)
{
    printf("\n---------FIFO--Page-Replacement-Algorithm-------\n");
    printf("Pages: ");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("\n\n");
    int hits = 0, miss = 0, b;
    int *buffer;
    buffer = (int *)malloc(sizeof(int) * frames);
    for (int i = 0; i < frames; i++)
    {
        buffer[i] = 0;
    }

    for (int p = 0; p < n; p++)
    {
        if (inar(buffer, frames, arr[p]) >= 0)
        {
            hits++;
            b = 1;
        }
        else
        {
            miss++;
            for (int i = frames - 2; i >= 0; i--)
            {
                buffer[i + 1] = buffer[i];
            }
            buffer[0] = arr[p];
            b = 0;
        }
        printf("Buffer: %d: ", arr[p]);
        for (int i = 0; i < frames; i++)
        {
            printf("%d  ", buffer[i]);
        }
        if (b)
            printf("Hit\n");
        else
            printf("Miss\n");
    }

    printf("Hits %d, Miss %d\n", hits, miss);
}

void lru(int arr[], int n, int frames)
{
    printf("\n---------LRU--Page-Replacement-Algorithm-------\n");
    printf("Pages: ");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("\n\n");
    int hits = 0, miss = 0, b;
    int *buffer;
    buffer = (int *)malloc(sizeof(int) * frames);
    for (int i = 0; i < frames; i++)
    {
        buffer[i] = 0;
    }
    int index, temp;
    for (int p = 0; p < n; p++)
    {
        index = inar(buffer, frames, arr[p]);
        if (index >= 0)
        {
            hits++;
            b = 1;
            temp = buffer[index];
            for (int i = index - 1; i >= 0; i--)
            {
                buffer[i + 1] = buffer[i];
            }
            buffer[0] = temp;
        }
        else
        {
            miss++;
            for (int i = frames - 2; i >= 0; i--)
            {
                buffer[i + 1] = buffer[i];
            }
            buffer[0] = arr[p];
            b = 0;
        }
        printf("Buffer: %d: ", arr[p]);
        for (int i = 0; i < frames; i++)
        {
            printf("%d  ", buffer[i]);
        }
        if (b)
            printf("Hit\n");
        else
            printf("Miss\n");
    }

    printf("Hits %d, Miss %d\n", hits, miss);
}

void optimal_pra(int arr[], int n, int frames)
{
    printf("\n-----------Optimal-Replacement-Algorithm-------\n");
    printf("Pages: ");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("\n\n");
    int hits = 0, miss = 0, b;
    int *buffer;
    buffer = (int *)malloc(sizeof(int) * frames);
    for (int i = 0; i < frames; i++)
    {
        buffer[i] = 0;
    }
    int ind, index, mindex = -1;
    int j = 0;
    for (int p = frames - 1; p >= 0; p--)
    {
        buffer[p] = arr[j++];
        printf("Buffer: %d: ", arr[j - 1]);
        for (int i = 0; i < frames; i++)
        {
            printf("%d  ", buffer[i]);
        }
        printf("Miss\n");
        miss++;
    }

    for (int p = frames; p < n; p++)
    {
        ind = inar(buffer, frames, arr[p]);
        if (ind >= 0)
        {
            hits++;
            b = 1;
        }
        else
        {
            miss++;
            for (int j = 0; j < frames; j++)
            {
                index = inarp(arr, p, n, buffer[j]);
                mindex = max(index, mindex);
                if (index == -1)
                {
                    buffer[j] = arr[p];
                    mindex = -1;
                    break;
                }
            }
            if (mindex != -1)
            {
                index = inar(buffer, frames, arr[mindex]);
                buffer[index] = arr[p];
            }
            b = 0;
        }
        printf("Buffer: %d: ", arr[p]);
        for (int i = 0; i < frames; i++)
        {
            printf("%d  ", buffer[i]);
        }
        if (b)
            printf("Hit\n");
        else
            printf("Miss\n");
    }
}