#include<bits/stdc++.h>
using namespace std;
int memo[2001][2001][6];
int N,M,k;
int lcs(int i,int j,int k, int arr1[],int arr2[])
{
   
   int ans =0;
   if(i==N || j==M)
   {
       return 0;
   }
   if(memo[i][j][k] != -1)
     return memo[i][j][k];

   
           if(arr1[i] == arr2[j])
           {
               ans = 1+lcs(i+1,j+1,k,arr1,arr2);
           }
           else
           {
               if(k > 0)
               {
               
               ans=1+lcs(i+1,j+1,k-1,arr1,arr2);
               }
               ans=max(ans,lcs(i,j+1,k,arr1,arr2));
               ans=max(ans,lcs(i+1,j,k,arr1,arr2));
           }
           return memo[i][j][k] = ans;
}
  
int main() 
{
    cin>>N>>M>>k;
    int arr1[N],arr2[M];
    for(int i=0;i<N;i++)
    {
        cin>>arr1[i];
    }
    for(int j=0;j<M;j++)
    {
        cin>>arr2[j];
    }
    
    for(int i=0;i<=2000;i++)
        for(int j=0;j<=2000;j++)
            for(int k=0;k<=5;k++)
                memo[i][j][k]=-1;

    cout<<lcs(0,0,k,arr1,arr2);
	return 0;
}
