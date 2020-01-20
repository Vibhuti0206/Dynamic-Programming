#include<bits/stdc++.h>
using namespace std;
int optimal(int n,int s,int size[],int value[])
{
    int dp[n+1][s+1];
    
    for(int i=0;i<=n;i++) dp[i][0] = 0;
   
    for(int i=0;i<=s;i++) dp[0][i] = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=s;j++)  //s is the target or the total capacity
        {
            if(j < size[i-1])
            {
                dp[i][j] = dp[i-1][j];
            }
            else
              dp[i][j] = max(dp[i-1][j] , dp[i-1][j-size[i-1]] + value[i-1]);
        }
    }
    return dp[n][s];
}
int main()
{
    int n,s;
    cin>>n>>s;
    int size[n],value[n];
    for(int i=0;i<n;i++)
     cin>>size[i];
    for(int i=0;i<n;i++)
      cin>>value[i];
    cout<<optimal(n,s,size,value);
}
