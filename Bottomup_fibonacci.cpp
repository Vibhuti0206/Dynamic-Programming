#include<bits/stdc++.h>
using namespace std;
int fib(int n)
{
	int dp[1000];
	dp[0] = 0;
	dp[1] = 1;
	for(int currNum =2 ;currNum <= n;currNum++)
	 dp[currNum] = dp[currNum -1 ] + dp[currNum - 2];
	 
	return dp[n];
}
int main()
{
	int n;
	cin>>n;
	cout<<"nth fibonacci is "<<fib(n);
	return 0;
	
}
