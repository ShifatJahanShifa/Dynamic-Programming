/* tabulation method */

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    vector<int>array(n);
    for(int i=0;i<n;i++)
    {
        cin>>array[i];
    }

    vector<vector<int>>DP(n,vector<int>(n,0));
    vector<vector<int>>mark(n,vector<int>(n,0));

    for(int i=n-1;i>0;i--)
    {
        for(int j=i+1;j<n;j++)
        {
            int total=INT_MAX,cost;
            for(int k=i;k<j;k++)
            {
                cost=array[i-1]*array[k]*array[j]+DP[i][k]+DP[k+1][j];
                if(cost<total)
                {
                    total=cost;
                    mark[i][j]=k;
                }
            }
            DP[i][j]=total;
        }
    }

    cout<<DP[1][n-1]<<"\n";

    for(int i=1;i<n;i++)
    {
        for(int j=1;j<n;j++)
            cout<<mark[i][j]<<" ";

        puts("");
    }
}


/* input

    6
    10 5 1 10 2 10

*/

/* output

    190
    0 0 0 0 0 0
    0 0 1 2 2 2
    0 0 0 2 2 2
    0 0 0 0 3 4
    0 0 0 0 0 4
    0 0 0 0 0 0
*/
