//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused

#include <stdio.h>

using namespace std;

int main(int argc, char* argv[])
{

    
    int arrSize;

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
    prontf("\n\n");





    
    int forClosing = 0;
    while (forClosing == 0)
    {
        printf("Enter 1 to close\n");
        scanf("%d", &forClosing);
    }

        return 0;
}
//---------------------------------------------------------------------------
 