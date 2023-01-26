/**
--> this is a solution of maximum sum interval problem
**/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>


void printAns(int index,int positionArray[],int arr[])
{
    if(positionArray[index]==-1)
    {
        printf("%d ",arr[index]);
        return ;
    }
    printAns(index-1,positionArray,arr);

    printf("%d ",arr[index]);

}


int main()
{

    /** taking input from file **/
    freopen("MSI.txt","r",stdin);


    /** input section. **/
    puts("enter the number of elements");
    int arraySize;
    scanf("%d",&arraySize);

    puts("enter the array");
    int arr[arraySize];
    for(int i=0; i<arraySize; i++)
    {
        scanf("%d",&arr[i]);
    }


    /** two arrays to store the sum and track the position **/
    int sumArray[arraySize];
    int positionArray[arraySize];


    /** initialize sumArray and positionArray **/
    sumArray[0]=arr[0];
    positionArray[0]=-1;


    /** processing section **/
    for(int i=1; i<arraySize; i++)
    {
        sumArray[i]=sumArray[i-1]+arr[i];
        if(sumArray[i]<arr[i])      /** resetting array **/
        {
            sumArray[i]=arr[i];
            positionArray[i]=-1;
        }
        else
        {
            positionArray[i]=i-1;
        }
    }


    /** checking the result and tracking the index **/
    int result=0;
    int index=0;

    for(int i=0; i<arraySize; i++)
    {
        if(sumArray[i]>result)
        {
            result=sumArray[i];
            index=i;
        }
    }


    /** printing the result **/
    printf("the maximum sum is = %d\n",result);


    /** function to print all the elements in the sequence **/
    printAns(index,positionArray,arr);

}
