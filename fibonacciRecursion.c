/// memorized top-down approach

#include<stdio.h>
#include<limits.h>
int fibo[1280000];

int setFibo(int n)
{
    if(fibo[n]>=0) return fibo[n];
    if(n<=1) fibo[n]=n;
    else fibo[n]=setFibo(n-1)+setFibo(n-2);      /// 0 1 1 2 3 5 8------ 46
    return fibo[n];
}

int main()
{
    puts("we have a fibonacci series(- -)");
    puts("which nth number in the fibonacci series do you want?");
    int n;
    scanf("%d",&n);

    for(int i=0;i<1280000;i++)
        fibo[i]=INT_MIN;

    printf("the nth number in the fibonacci series is :  %d",setFibo(n));
}
