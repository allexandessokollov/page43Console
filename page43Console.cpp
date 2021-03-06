//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int const MAX_ARR_SIZE  = 14;
int const MAX_RANDOM_VALUE = 15;
int const MIN_RANDOM_VALUE = -5;

int numMaxOfArray(int arr[], int arrLength);
int numMinOfArray(int arr[], int arrLength);
int countAnswer(int arr[], int minIndex, int maxIndex);
void fillArrKeyboard(int arr[], int arrSize);
void fillArrRandomly(int arr[], int arrSize);

int main()
{
    int arrSize, minIndex, maxIndex, answer, toFillArr;

    printf("Enter array size\n");
    scanf("%d", &arrSize);

    while(arrSize < 0 || arrSize > MAX_ARR_SIZE )
    {
        printf("Size of array should be more than 0 and less than 14\n");
        scanf("%d", &arrSize);
    }

    int *arr = new int[arrSize];
    
    printf("\nTo fill array using keybord press 1\nTo fill array randomly press 2\n");

    scanf("%d", &toFillArr);


    switch(toFillArr)
    {
    case 1:
        fillArrKeyboard(arr, arrSize);
        break;
    case 2:
        fillArrRandomly(arr, arrSize);
        break;
    }


    printf("\n\n");

    for(int i = 0; i < arrSize; i++)
    {
        printf(" %d | ", arr[i]);
    }
    printf("\n\n");


    minIndex = numMinOfArray(arr, arrSize);
    maxIndex = numMaxOfArray(arr, arrSize);

    if(maxIndex < minIndex)
    {
        int tmp = maxIndex;
        maxIndex = minIndex;
        minIndex = tmp;
    }

    if((maxIndex - minIndex) <= 1)
    {
        printf("\n\nthere is no elements between\nrestart application\n\n");
    }
    else
    {
        answer = countAnswer(arr, minIndex, maxIndex);
        printf("answer is: %d\n\n", answer);
    }



    
    puts("\n\n\nPress any key ... ");
    getch();
    getch();

    delete []arr;
    return 0;
}


int numMaxOfArray(int arr[], int arrLength)
{
    int maxPos = 0,
    maxValue = arr[0];
    
    for(int i = 1; i < arrLength; i++)
    {
        if(arr[i] > maxValue)
        {
            maxPos = i;
            maxValue = arr[i];
        }
    }
    
    return maxPos;
}

int numMinOfArray(int arr[], int arrLength)
{
    int minPos = 0,
    minValue = arr[0];

    for(int i = 1; i < arrLength; i++)
    {
        if(arr[i] < minValue)
        {
            minPos= i;
            minValue = arr[i];
        }
    }

    return minPos;
}

int countAnswer(int arr[], int minIndex, int maxIndex)
{
    int answer = 1;

    for(int i = minIndex + 1; i < maxIndex; i++)
    {
        answer *= arr[i];
    }

    return answer;
}



void fillArrKeyboard(int arr[], int arrSize)
{

    for(int i = 0; i < arrSize; i++)
    {
        printf("Enter element number %d \n", i);
        scanf("%d", &arr[i]);
    }

}

void fillArrRandomly(int arr[], int arrSize)
{
    for(int i = 0; i < arrSize; i++)
    {
        arr[i] = random(MAX_RANDOM_VALUE - MIN_RANDOM_VALUE) + MIN_RANDOM_VALUE;
    }
}


//---------------------------------------------------------------------------
 