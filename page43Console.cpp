//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused

#include <stdio.h>

int numMaxOfArray(int arr[], int arrLength);
int numMinOfArray(int arr[], int arrLength);
int countAnswer(int arr[], int minIndex, int maxIndex);

int coloseApp()
{
    int forClosing = 1;
    while (forClosing == 1)
    {
        printf("Enter 0 to close\n");
        scanf("%d", &forClosing);
    }

    return forClosing;
}

int main(int argc, char* argv[])
{

    
    int arrSize, minIndex, maxIndex, answer;

    printf("Enter array size\n");
    scanf("%d", &arrSize);

    while(arrSize < 0 || arrSize > 14)
    {
        printf("Size of array should be more than 0 and less than 14\n");
        scanf("%d", &arrSize);
    }

    int *arr = new int[arrSize];
    
    printf("\nEnter array elements\n");

    for(int i = 0; i < arrSize; i++)
    {
        printf("Enter element number %d \n", i);
        scanf("%d", &arr[i]);
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
        int forClosing = coloseApp();

        if(forClosing == 0)
        {
            return 0;
        }
    }
    else
    {
        answer = countAnswer(arr, minIndex, maxIndex);
        printf("answer is: %d\n\n", answer);
    }



    
    int forClosing = coloseApp();
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
        answer = answer * arr[i];
    }

    return answer;
}
//---------------------------------------------------------------------------
 