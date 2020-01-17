#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007   //because large output
int dp[1001][1001];
int numWays(int Ro,int Col){
	//base Case
	if(dp[0][0] == -1){
		return 0;
	}
	//Compute the number of ways in first row
	for(int j = 0; j<Col;j++){
		if(dp[0][j] == -1){
			break;               //Because this means the cell is blocked and if cell is blocked we donot have to continue
			
		}
		dp[0][j] = 1;
	}
	for(int j = 0; j<Ro;j++){
		if(dp[j][0] == -1){
			break;               //Because this means the cell is blocked and if cell is blocked we donot have to continue
			
		}
		dp[j][0] = 1;
	}
	
	//Bottom Up Approach for rest of matrix
	for(int i=1;i<Ro;i++){
		for(int j=1;j<Col;j++){
			//if cell is blocked we have to leave it
			if(dp[i][j] == -1){
				continue;       //goes back to the loop 
			}
			//dp[i][j] = 0;
			if(dp[i][j-1] != -1){
				dp[i][j] = dp[i][j-1]%MOD;
			}
			if(dp[i-1][j] != -1){
				dp[i][j] = (dp[i][j] + dp[i-1][j])%MOD;
			}
		}
    } 
		//Check for the final cells
		if(dp[Ro-1][Col-1] == -1){
			return 0;
		}
			//Print the entire dp table
		for(int i=0;i<Ro;i++){
			for(int j=0;j<Col;j++){
				cout<<dp[i][j]<<" ";
			}
			cout<<endl;
		}
		return dp[Ro-1][Col-1];
	
}
int main()
{
	memset(dp,0,sizeof dp);
	int m,n,p;  //m=number of rows,n=number of columns,p= number fo blocked co-ordinates
    cin>>m>>n>>p;
    for(int i=0;i<p;i++)
    {
    	int X,Y;
    	cin>>X>>Y;
    	//Mark all the blocked cells as -1
    	dp[X-1][Y-1] = -1;
    	
	}
	cout<<numWays(m,n)<<endl;
	return 0;
}
