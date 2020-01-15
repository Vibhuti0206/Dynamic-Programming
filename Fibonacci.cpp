#include<bits/stdc++.h>
using namespace std;
int fib(int n,int *memo)
{
	if(n == 0) return 0;
	if(n == 1) return 1;
	
	if(memo[n] != -1)
	  return memo[n];
	
	int ans = fib(n-1,memo) + fib(n-2,memo);
	memo[n] = ans;
	return ans;
}
int main()
{
	int n;
	cin>>n;
	int memo[n]; 
	for(int i=0;i<=n;i++) //i< = n,equals is sed because number of elements in array till the number whose finbonacci is to be computed
	{
		memo[i]  = -1;
	}
	cout<<"Fibonacci is "<<fib(n,memo);
	return 0;
}
