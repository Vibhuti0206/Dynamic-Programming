#include<bits/stdc++.h>
using namespace std;
bool achieve(int n,int arr[],int target)
{
	int dp[n+1][target+1];
	for(int i=0;i<n;i++) dp[i][0] = true;
	for(int j=0;j<target;j++) dp[0][j] = false;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=target;j++)
		{
			if(j < arr[i-1])
			  dp[i][j] = dp[i-1][j];
			else
			  dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
		}
	}
	return dp[n][target];
}
int main()
{
	int n,target;
	cin>>n>>target;
	int arr[n];
	for(int i=0;i<n;i++)
	 cin>>arr[i];
	bool ans = achieve(n,arr,target);
    if(ans)
	 cout<<"Yes";
	else
	  cout<<"No";
	return 0;
}
