#include<bits/stdc++.h>
using namespace std;
int editDist(string inp,string out)
{
	int dp[101][101] = {};
	int m = inp.length();
	int n = out.length();
	dp[0][0] = 0;
	for(int i = 0 ; i<=n;i++) dp[0][i] = dp[0][i-1] + 1;  //insertion in oth row as base case
	for(int j = 0 ;j<=m;j++) dp[j][0] = dp[j-1][0] + 1; //deletion in 0th row as bse case
	
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			int q1 = dp[i-1][j-1];   //replacement
			int q2 = dp[i-1][j]; //deletion
			int q3 = dp[i][j-1]; //insertion
			dp[i][j] = min(q1,min(q2,q3)) + (inp[i-1] != out[j-1]);   //we have not one +1 while calculating q1,q2,q3 because that was considering the case when s=s(example in saturday and sunday) and the answer of the block was 1 although it should have beeen zero so now to add that +1 we 
			                                                          //have used (inp[i-1] != out[j-1] which means that when character equals then donot add one that is answer of this bracket is 0 otherrwise 1 which is for the operation done
			                                                          
		}
	}
	return dp[m][n];
    

}
int main()
{
	string inp;
	cin>>inp;
	string out;
	cin>>out;
	int ans = editDist(inp,out);
	cout<<ans;
	return 0;
}
