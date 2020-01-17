#include<bits/stdc++.h>
using namespace std;
int lcs(string x,string y){
	int m = x.length();
	int n = y.length();
	int dp[100][100];
	//base cases
	for(int i=0;i<=m;i++) dp[i][0] = 0;
    for(int j=0;j<=n;j++) dp[0][j] = 0;
    
    for(int i=1;i<=m;i++){
    	for(int j=1;j<=n;j++){
    		int q = 0;
    		if(x[i-1] == y[j-1]){
    			q = 1+dp[i-1][j-1];
			}
			else{
				q = max(dp[i-1][j] , dp[i][j-1]);
			}
			dp[i][j] = q;
			
		}
	}
	return dp[m][n];

}
int main()
{
	string x;
	cin>>x;
	string y;
	cin>>y;
	int ans = lcs(x,y);
	cout<<ans;
}
