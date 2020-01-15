#include<bits/stdc++.h>
using namespace std;
int reduceNo(int n){
	if(n == 1) return 0;
	int q1=INT_MAX,q2 = INT_MAX,q3=INT_MAX;
	if(n %3 == 0) q1 = 1+reduceNo(n/3);
	if(n %2 == 0) q2 = 1+reduceNo(n/2);
	q3 = 1+reduceNo(n - 1);
	return min(q1,min(q2,q3));
}
int memo[10000];
int reduceNoMemo(int n){
	if(n == 1) return 0;
	int q1=INT_MAX,q2 = INT_MAX,q3=INT_MAX;
	if(memo[n] != -1)
	{
		return memo[n];
	}
	if(n %3 == 0) q1 = 1+reduceNo(n/3);
	if(n %2 == 0) q2 = 1+reduceNo(n/2);
	q3 = 1+reduceNo(n - 1);
	memo[n] = min(q1,min(q2,q3));
	return memo[n];
}
int dp[1000];
int reduceNoDP(int n)
{ //set the base case
   dp[0] = 0;
   dp[1] = 0;
   dp[2] = 1;
   dp[3] = 1;
   
   for(int i=4;i<=n;i++)
   {
     int q1=INT_MAX,q2 = INT_MAX,q3=INT_MAX;
   	if(i %3 == 0) q1 = 1+reduceNo(i/3);
	if(i %2 == 0) q2 = 1+reduceNo(i/2);
	q3 = 1+reduceNo(i - 1);
	dp[i] = min(q1,min(q2,q3));
   }
	return dp[n];
}
int main()
{
	int n;
	cin>>n;
    cout<<reduceNo(n)<<"Using recursion"<<endl;
	fill(memo,memo+n+1,-1);  //or use loop to initialise -1;
	cout<<reduceNoMemo(n)<<" using memoization"<<endl;
	cout<<reduceNoDP(n)<<" using bottom up";
	
	return 0;
	
}
